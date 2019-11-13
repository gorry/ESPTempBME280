# ESPTempBME280
ESP8266をWifi経由WWWサーバとして起動し、BME280の値を読み取るテスト。


# 使い方

1. ブレッドボードにESP8266とBME280を挿し、以下のように結線する。
```
    ESP8266:GND   ----  GND:BME280
    ESP8266:3.3V  ---- 3.3V:BME280
    ESP8266:GPIO4 ----  SDA:BME280
    ESP8266:GPIO5 ----  SCL:BME280
```
2. ESPTempBME280.ino の以下を修正し、SSIDとパスワードを設定する。
```
    const char *ssid = "YOUR_SSID";
    const char *password = "YOUR_PASSWORD";
```
3. 固定IPで起動したい場合は、以下も修正する。
```
    // #define USE_FIXED_IP
    #if defined(USE_FIXED_IP)
    IPAddress ip(192, 168, 2, 222);
    IPAddress gateway(192, 168, 2, 2);
    IPAddress subnet(255, 255, 255, 0);
    #endif
```
4. 以下からArduino用BME280ライブラリを取得し、BME280_MOD-1022.cpp とBME280_MOD-1022.h を ESPTempBME280.ino と同じフォルダに設置する。ソースはArduino用だが、ESP8266でも使用可能。
```
    https://github.com/embeddedadventures/BME280
```
5. Arduino IDEを起動して ESPTempBME280.ino を読み、ターゲットボードに"Generic ESP8266 Module"を、書き込み装置に"AVR ISP"を選び、ビルド・転送する。

6. ESP8266を起動すると、シリアルコンソールに取得したIPアドレスが出力される。

7. http://ip-address/ にアクセスし、「Hello from ESP8266!」が表示されることを確認する。

8. http://ip-address/temp.txt にアクセスし、気温・湿度・気圧が表示されることを確認する。


# ライセンス

本プロダクトは、自由かつ無償で使用・コピー・配布・変更・流用を行うことができます。また許可なく再配布・出版・販売を行うことができます。
本プロダクトは、無保証です。使用した、あるいはしなかったことによる一切の責任は使用者にあるものとします。

# 連絡先

後藤 浩昭 / GORRY  
http://GORRY.hauN.org/  
twitter/gorry5

