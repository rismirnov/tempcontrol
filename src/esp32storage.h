#include <storage.h>
#include "SPIFFS.h"

class ESP32Storage : public Storage
{
private:
    File file;
public:
    ESP32Storage();
    ~ESP32Storage();
    void load(Settings *settings) override;
    void save(Settings *settings) override;
};