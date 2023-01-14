// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define SerialMon Serial

#include <esp_wifi.h>

extern "C" void openhaystack_main(void);

void setup()
{
    // Set console baud rate
    SerialMon.begin(115200);

    delay(1000);

#ifdef BOARD_LUATOS_ESP32C3
    // Disable LED outputs - not really happy about these being outputs?
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_13, GPIO_MODE_OUTPUT);
#endif

    // Setup OpenHaystack
    openhaystack_main();
}

void loop()
{
    esp_err_t status;

    //
    log_i("Sleeping");

    // Enter light sleep
    if ((status = esp_light_sleep_start()) != ESP_OK) {
        log_e("esp_light_sleep_start: %s", esp_err_to_name(status));
    }

    log_i("Should be asleep");

    delay(5000);
}