## Description

Guages distance by adjusting the ESP32C3's wifi transmission power.

Sends a simple bool statement through the ESP-NOW protocol, and if recieved, will power an LED and a piezo buzzer. As distance between the transmitter and reciever shortens, the higher frequency the `distancePin` will light up. Goes up to 8 cycles (8 blinks on the LED).

-To do: calculate distance.

_____

Tutorials used: https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
