# OpenHaystack BLE based Apple AirTag location

Part of what I want to do is to check how the cellular performs in different locations nationally. 

One idea I have for this is to post the device around and about and see how it performs, and in particular how reconnecting may influence the data overhead.

It occurred to me that the ESP32 has BLE and so it might be possible to spoof an Apple AirTag and leverage Apple's AirTag location network to track devices independently as I am monitoring the data-comms.

Rather wonderfully there is an ESP32 implementation of this called [OpenHaystack](https://github.com/seemoo-lab/openhaystack). The existing code is for ESP-IDF but I have ported this work here to build under Platform.io

I've also added a simple command `Custom->Write Public Key` which runs the Python code in publickey.b64 to set the needed tag advertising key into the ESP32.

The process you'd follow is

- Install and run OpenHaystack appliccation on a MAC
- Create a device
- Copy the device public advertising key
- Put this into the `publickey.b64` file here
- Write the firmware to the ESP32 (as this currently erases the key partition - need to look at this)
- Write the public key

After about half an hour - assuming iPhones are around - you should see the location pop up on the OpenHaystack application

Cheers!
