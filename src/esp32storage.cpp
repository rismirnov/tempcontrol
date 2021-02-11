#include "esp32storage.h"

ESP32Storage::ESP32Storage()
{
    SPIFFS.begin();
    file = SPIFFS.open("/settings.bin", FILE_WRITE);
}

void ESP32Storage::load(Settings *settings)
{
    char *settingsBytes = reinterpret_cast<char *>(settings);
    if (file.size() != 0)
        file.readBytes(settingsBytes, sizeof(Settings));
}

void ESP32Storage::save(Settings *settings)
{
    auto settingsBytes = reinterpret_cast<const uint8_t *>(settings);
    file.write(settingsBytes, sizeof(Settings));
}

ESP32Storage::~ESP32Storage()
{
    file.close();
}
