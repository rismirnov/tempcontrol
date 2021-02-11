#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "AsyncJson.h"
#include <Monitor.h>
#include "relay.h"
#include "motor.h"
#include "esp32storage.h"
#include "temperature_sensor.h"

AsyncWebServer server(80);
//DNSServer dnsServer;

Settings settings;

/*Relay relay;
Clock clk;
Motor motor;
TemperatureSensor sensor;
Settings settings;
Monitor monitor;
ESP32Storage storage;
*/

int Regulator::CONTROL_PRECISION = 2;

const char *ssid = "ESP-MODULE";
const char *password = "12345678";

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}

void setup()
{

  Serial.begin(115200);
  SPIFFS.begin();

  //IPAddress apIP(192, 168, 0, 1);
  //IPAddress netMsk(255, 255, 255, 0);
  WiFi.softAP(ssid, password);
  //WiFi.softAPConfig(apIP, apIP, netMsk);

  //dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  //dnsServer.start(53, "localhost", apIP);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/bulma.min.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/bulma.min.css", "text/css");
  });

  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request) {
    //String(sensor.getData())
    request->send(200, "text/plain", String(200));
  });

  server.on("/getsetup", HTTP_GET, [](AsyncWebServerRequest *request) {
    auto response = new AsyncJsonResponse();
    const JsonObject &root = response->getRoot();
    root["comfortTemp"] = settings.getComfortTemp();
    root["economTemp"] = settings.getEconomTemp();
    root["startTime"] = settings.getStartTime();
    root["endTime"] = settings.getEndTime();
    response->setLength();
    request->send(response);
  });

  server.on("/setup", HTTP_POST, [](AsyncWebServerRequest *request) {
    bool invariant = request->hasParam("control", true) &&
                     request->hasParam("econom", true) &&
                     request->hasParam("start", true) &&
                     request->hasParam("end", true) &&
                     request->hasParam("time", true);

    if (invariant)
    {
      settings.setComfortTemp(atoi(request->getParam("control", true)->value().c_str()));
      settings.setEconomTemp(atoi(request->getParam("econom", true)->value().c_str()));
      settings.setStartTime(atoi(request->getParam("start", true)->value().c_str()));
      settings.setEndTime(atoi(request->getParam("end", true)->value().c_str()));
      //clk.setTime(atoi(request->getParam("time", true)->value().c_str()));
      //storage.save(&settings);
    }
  });

  server.onNotFound(notFound);
  server.begin();

  /*monitor.setSettings(&settings);
  monitor.setRegulator(&relay);
  monitor.setClock(&clk);

  clk.setPeriod(5000);
  /*clk.setInterval(3600000, []() {
  });
  storage.load(&settings);*/
}

void clockDelay()
{
  //delay(clk.getPeriod());
 // clk.tick();
}

void controlMotor()
{
  //monitor.calculateControlMode();
  //bool relayState = relay.control(sensor.getData());
  //motor.drive(relayState);
}

void loop()
{
  //dnsServer.processNextRequest();
  delay(1000);
  //clockDelay();
  //sensor.measure();
  //controlMotor();
}