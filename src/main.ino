// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define SerialMon Serial

#include <esp_wifi.h>

extern "C" void openhaystack_main(void);

void setup()
{
    // Set console baud rate
    SerialMon.begin(115200);
    
    delay(2000);

    log_i("GNAT starting up");

#ifdef BOARD_LUATOS_ESP32C3
    // Disable LED outputs - not really happy about these being outputs?
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_13, GPIO_MODE_OUTPUT);
#endif

    // Setup OpenHaystack
    openhaystack_main();
    
    // Allow OpenHaystack advertising to start up
    delay(5000);

    esp_err_t status;

    // Make sure WiFi is disabled
    if ((status = esp_wifi_stop()) != ESP_OK) {
        log_e("esp_wifi_stop: %s", esp_err_to_name(status));
        return;
    }

    // Enter light sleep
    if ((status = esp_light_sleep_start()) != ESP_OK) {
        log_e("esp_light_sleep_start: %s", esp_err_to_name(status));
        return;
    }
    log_i("Should be asleep");
}

void loop()
{
    log_i("Should be asleep");
    delay(5000);
}