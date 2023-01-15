// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define SerialMon Serial

#include <esp_wifi.h>

extern "C" void openhaystack_main(void);
extern "C" bool isAdvertising(void);

#define GPIO_DEEP_SLEEP_DURATION 60

void setup()
{
#ifdef BOARD_LUATOS_ESP32C3
    // Disable LED outputs - not really happy about these being outputs?
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_13, GPIO_MODE_OUTPUT);
#endif

    // Set console baud rate
    SerialMon.begin(115200);

    // Setup OpenHaystack
    openhaystack_main();

    while(!isAdvertising())
        yield();

    delay(1000);
    log_i("Sleeping...");
    esp_deep_sleep(1000000LL * GPIO_DEEP_SLEEP_DURATION);
}

void loop()
{
    log_i("Should be asleep");

    delay(5000);
}