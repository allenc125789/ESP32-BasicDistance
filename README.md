## Description

Guages distance by adjusting the ESP32C3's wifi transmission power.

Cycles between 8 levels of signal streangth. Then sends a simple bool statement through the ESP-NOW protocol, and if recieved, will power an LED and a piezo buzzer. As distance shortens between the transmitter and reciever, the higher frequency the `distancePin` will light up.

## Distance Calculation
(With [Seeed antenna](https://media-cdn.seeedstudio.com/media/catalog/product/cache/bb49d3ec4ee05b6f018e93f896b8a25d/5/-/5-113991114-xiao-esp32s3-45fontall_1.jpg))
-To do: calculate distance.

Cycle 1: 19dBm

Cycle 2: 17dBm

Cycle 3: 15dBm

Cycle 4: 13dBm

Cycle 5: 11dBm

Cycle 6: 7dBm

Cycle 7: 5dBm

Cycle 8: 2dBm

_____

Tutorials used: https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
