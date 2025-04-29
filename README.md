## Description

Guages distance by adjusting the ESP32C3's wifi transmission power[^1].

Cycles between 8 levels of signal streangth. Then sends a bool statement through the ESP-NOW protocol, and if recieved, will power an LED and a piezo buzzer. As distance shortens between the transmitter and reciever, the higher frequency the `distancePin` will light up.

## Setup:
Requires x2 ESP32C3s (I have only tested on XIAO models).

### - Reciever
  1) Get the mac address of 1 of your ESP32C3s. [I used this code to get mine, provided by Random Nerd Tutorials.](https://raw.githubusercontent.com/RuiSantosdotme/Random-Nerd-Tutorials/master/Projects/ESP32/ESP32_Get_MAC_Address.ino)[^2]. Write this mac address down.
  2) Upload reciever.ino to previously used ESPC3s. Power it on and set it to the side.
### - Transmitter
  3) Replace the MAC address in transmiiter.ino's code with the new one you recieved, then upload the edited transmitter.ino to your second ESP32C3.

## Distance Calculation
(Will depend on the antenna used. These calculations will use this [Seeed Studio Antenna](https://media-cdn.seeedstudio.com/media/catalog/product/cache/bb49d3ec4ee05b6f018e93f896b8a25d/5/-/5-113991114-xiao-esp32s3-45fontall_1.jpg))
-To do: calculate distance.

Cycle 1: 19dBm

Cycle 2: 17dBm

Cycle 3: 15dBm

Cycle 4: 13dBm

Cycle 5: 11dBm

Cycle 6: 7dBm

Cycle 7: 5dBm

Cycle 8: 2dBm

### Resources:
[^1]: https://github.com/G6EJD/ESP32-8266-Adjust-WiFi-RF-Power-Output/blob/main/ESP_WiFI_Power_Adjust.ino
[^2]: https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
