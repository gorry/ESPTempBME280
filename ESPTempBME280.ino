
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <Wire.h>
#include "BME280_MOD-1022.h"

const char *ssid = "YOUR_SSID";
const char *password = "YOUR_PASSWORD";
// #define USE_FIXED_IP
#if defined(USE_FIXED_IP)
IPAddress ip(192, 168, 2, 222);
IPAddress gateway(192, 168, 2, 2);
IPAddress subnet(255, 255, 255, 0);
#endif

ESP8266WebServer server(80);

void handleRoot()
{
  char temp[400];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  snprintf(temp, 400,
  "<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>ESP8266 Demo</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Hello from ESP8266!</h1>\
    <p>Uptime: %02d:%02d:%02d</p>\
  </body>\
</html>",
    hr, min % 60, sec % 60
  );
  server.send(200, "text/html", temp);
}

void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void sendTempTxt() {
  char temp[400];
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level

  delay(300);
  BME280.writeMode(smForced);
  while (BME280.isMeasuring()) {
    delay(300);
  }
  BME280.readMeasurements();
  float temperature = BME280.getTemperature();
  float humidity = BME280.getHumidity();
  float pressure = BME280.getPressure();

  snprintf(temp, 400, "%f, %f, %f : %s\n", temperature, humidity, pressure, ARDUINO_BOARD);
  Serial.println(temp);
  server.send(200, "text/plain", temp);

  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
}

void setupWifi(void)
{
  Serial.print("WiFi connect [");
  Serial.print(ssid);
  Serial.print("]: ");
#if defined(USE_FIXED_IP)
  WiFi.config(ip, gateway, subnet);
#endif
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected. IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/temp.txt", sendTempTxt);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level

  Serial.begin(115200);

  Wire.begin(4, 5);
  BME280.readCompensationParams();
  BME280.writeOversamplingTemperature(os1x);
  BME280.writeOversamplingHumidity(os1x);
  BME280.writeOversamplingPressure(os1x);

  setupWifi();

  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
}

void loop()
{
  server.handleClient();
  MDNS.update();
}
