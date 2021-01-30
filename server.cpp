
#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include <OneWire.h>


class TemperatureSensor : public Sensor {
public:
	OneWire ds(8);
    TemperatureSensor() {}
    void measure() override {
		  byte data[2]; // Место для значения температуры
		  
		  ds.reset(); // Начинаем взаимодействие со сброса всех предыдущих команд и параметров
		  ds.write(0xCC); // Даем датчику DS18b20 команду пропустить поиск по адресу. В нашем случае только одно устрйоство 
		  ds.write(0x44); // Даем датчику DS18b20 команду измерить температуру. Само значение температуры мы еще не получаем - датчик его положит во внутреннюю память
		  
		  delay(1000); // Микросхема измеряет температуру, а мы ждем.  
		  
		  ds.reset(); // Теперь готовимся получить значение измеренной температуры
		  ds.write(0xCC); 
		  ds.write(0xBE); // Просим передать нам значение регистров со значением температуры

		  // Получаем и считываем ответ
		  data[0] = ds.read(); // Читаем младший байт значения температуры
		  data[1] = ds.read(); // А теперь старший

		  // Формируем итоговое значение: 
		  //    - сперва "склеиваем" значение, 
		  //    - затем умножаем его на коэффициент, соответсвующий разрешающей способности (для 12 бит по умолчанию - это 0.0625)
		 _data = ((data[1] << 8) | data[0]) * 0.0625;
    }
};

class ThermalValve  : public Motor {
public:
    MotorExample() {}
    void drive(int control) override {
        // Microprogram code;
    }
};

AsyncWebServer server(80);


PID pid;
Clock c;
ThermalValve m;
TemperatureSensor ts;
Settings settings;
Monitor monitor(&settings);

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* PARAM_MESSAGE = "message";

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void setup() {

    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
         request->send(SPIFFS, "/index.html", "text/html");
    });
	
	server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
		request->send(SPIFFS, "/bulma.min.css", "text/css");
	});

    server.on("/data", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String data = "{\"temp\" : \"" + ts.data() + "\"";
        request->send(200, "application/json", data);
    });

    server.on("/setup", HTTP_POST, [](AsyncWebServerRequest *request){
    
		bool invariant = request->hasParam("control", true) && \
		request->hasParam("econom", true) && \
		request->hasParam("start", true) && \ 
		request->hasParam("end", true); && \
		request->hasParam("time", true); \
	
        if (invariant) {
            settings.setComfortTemp(atoi(request->getParam("control", true)->value().c_str()));
			settings.setEconomTemp(atoi(request->getParam("econom", true)->value().c_str()));
			settings.setStartTime(atoi(request->getParam("start", true)->value().c_str()));
			settings.setEndTime(atoi(request->getParam("end", true)->value().c_str()));
        } 

    });

    server.onNotFound(notFound);
    server.begin();
	
	// ts.setupAddress();
	settings.setRegulator(&pid);
    settings.setMotor(&m);
    settings.setClock(&c);
    settings.setSensors(&ts, 1);
}

void loop() {
	
	ts.measure();
	monitor.work();
}