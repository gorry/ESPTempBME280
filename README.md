# ESPTempBME280
ESP8266��Wifi�o�RWWW�T�[�o�Ƃ��ċN�����ABME280�̒l��ǂݎ��e�X�g�B


# �g����

1. �u���b�h�{�[�h��ESP8266��BME280��}���A�ȉ��̂悤�Ɍ�������B
```
    ESP8266:GND   ----  GND:BME280
    ESP8266:3.3V  ---- 3.3V:BME280
    ESP8266:GPIO4 ----  SDA:BME280
    ESP8266:GPIO5 ----  SCL:BME280
```
2. ESPTempBME280.ino �̈ȉ����C�����ASSID�ƃp�X���[�h��ݒ肷��B
```
    const char *ssid = "YOUR_SSID";
    const char *password = "YOUR_PASSWORD";
```
3. �Œ�IP�ŋN���������ꍇ�́A�ȉ����C������B
```
    // #define USE_FIXED_IP
    #if defined(USE_FIXED_IP)
    IPAddress ip(192, 168, 2, 222);
    IPAddress gateway(192, 168, 2, 2);
    IPAddress subnet(255, 255, 255, 0);
    #endif
```
4. �ȉ�����Arduino�pBME280���C�u�������擾���ABME280_MOD-1022.cpp ��BME280_MOD-1022.h �� ESPTempBME280.ino �Ɠ����t�H���_�ɐݒu����B�\�[�X��Arduino�p�����AESP8266�ł��g�p�\�B
```
    https://github.com/embeddedadventures/BME280
```
5. Arduino IDE���N������ ESPTempBME280.ino ��ǂ݁A�^�[�Q�b�g�{�[�h��"Generic ESP8266 Module"���A�������ݑ��u��"AVR ISP"��I�сA�r���h�E�]������B

6. ESP8266���N������ƁA�V���A���R���\�[���Ɏ擾����IP�A�h���X���o�͂����B

7. http://ip-address/ �ɃA�N�Z�X���A�uHello from ESP8266!�v���\������邱�Ƃ��m�F����B

8. http://ip-address/temp.txt �ɃA�N�Z�X���A�C���E���x�E�C�����\������邱�Ƃ��m�F����B


# ���C�Z���X

�{�v���_�N�g�́A���R�������Ŏg�p�E�R�s�[�E�z�z�E�ύX�E���p���s�����Ƃ��ł��܂��B�܂����Ȃ��Ĕz�z�E�o�ŁE�̔����s�����Ƃ��ł��܂��B
�{�v���_�N�g�́A���ۏ؂ł��B�g�p�����A���邢�͂��Ȃ��������Ƃɂ���؂̐ӔC�͎g�p�҂ɂ�����̂Ƃ��܂��B

# �A����

�㓡 �_�� / GORRY  
http://GORRY.hauN.org/  
twitter/gorry5

