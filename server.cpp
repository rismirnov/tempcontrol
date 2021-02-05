#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include <TemperatureControl.h>

class TemperatureSensor: public Sensor {
  public: 
  TemperatureSensor() {}
  void measure() override {}
};

class ThermalValve: public Motor {
  public: 
  ThermalValve() {}
  void drive(int control) override {
    // Microprogram code;
  }
};

AsyncWebServer server(80);
Relay relay;
Clock clk;
ThermalValve motor;
TemperatureSensor sensor;
Settings settings;
Monitor monitor;

const char * ssid = "ESP-MODULE";
const char * password = "12345678";

void notFound(AsyncWebServerRequest * request) {
  request -> send(404, "text/plain", "Not found");
}

void setup() {

  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request -> send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request -> send(SPIFFS, "/bulma.min.css", "text/css");
  });

  server.on("/data", HTTP_GET, [](AsyncWebServerRequest * request) {
    //application/json
    request -> send(200, "text/plain", String(sensor.getData()));
  });

  server.on("/setup", HTTP_POST, [](AsyncWebServerRequest * request) {

    bool invariant = request -> hasParam("control", true) &&
      request -> hasParam("econom", true) &&
      request -> hasParam("start", true) &&
      request -> hasParam("end", true) &&
      request -> hasParam("time", true);

    if (invariant) {
      settings.setComfortTemp(atoi(request -> getParam("control", true) -> value().c_str()));
      settings.setEconomTemp(atoi(request -> getParam("econom", true) -> value().c_str()));
      settings.setStartTime(atoi(request -> getParam("start", true) -> value().c_str()));
      settings.setEndTime(atoi(request -> getParam("end", true) -> value().c_str()));
      clk.setTime(atoi(request -> getParam("time", true) -> value().c_str()));
    }

  });

  server.onNotFound(notFound);
  server.begin();

  monitor.setSettings(&settings);
  monitor.setRegulator( & relay);
  monitor.setClock( & clk);
  monitor.setSensors( & sensor, 1);

  relay.setMotor( & motor);

  clk.setPeriod(1000);
  clk.setInterval(1800000, []() {
      monitor.work();
  });

}

void loop() {
  delay(1000);
  clk.tick();
  sensor.measure();
}