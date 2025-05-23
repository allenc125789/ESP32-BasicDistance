## ESP32C3 Basic Distance Tracking

Estimates distance between two XIAO-ESP32C3 devices by adjusting the wifi transmission power.

## How does it work?

+ This program is based on the RSSI-based distance estimation method [^1].

+ Cycles between 5 modes of signal streangth [^2]. Then sends a bool statement through the ESP-NOW protocol, and if recieved, will power an LED and a piezo buzzer. As the two devices get closer, the frequency of output will increase.

## Setup:
### Reciever...
  1) Get the mac address of 1 of your ESP32C3s. [I used this code to get mine, provided by Random Nerd Tutorials](https://raw.githubusercontent.com/RuiSantosdotme/Random-Nerd-Tutorials/master/Projects/ESP32/ESP32_Get_MAC_Address.ino) [^3]. Write this mac address down.
  2) Upload `Reciever.ino` to previously used ESPC3s. Power it on and set it to the side.

### Transmitter...
  1) Replace the MAC address in `Transmitter.ino`'s code with the new one you received.
  2) Upload the edited `Transmitter.ino` to your second ESP32C3. You'll then be able to monitor output through console to confirm functionality.

### Transmitter Circuit (Optional)...
This is a reference schematic for building a basic circuit that utilizes my program. The circuit adds portability with a Battery Management System(U1) and a LiPo battery, and visual/auditory reference with an LED and piezo buzzer. This step is optional, as the program will function without it.
![Transmitter Circuit Schematic](https://github.com/allenc125789/ESP32C3-BasicDistance/blob/main/KiCad-files/ESP32C3-DistanceTracker-Transmitter.jpg)

## Distance Calculation
(Will depend on the antenna used. These calculations will use this [Seeed Studio Antenna](https://media-cdn.seeedstudio.com/media/catalog/product/cache/bb49d3ec4ee05b6f018e93f896b8a25d/5/-/5-113991114-xiao-esp32s3-45fontall_1.jpg))
-To do: calculate distance.

Cycle 1: 19dBm

Cycle 2: 15dBm

Cycle 3: 11dBm

Cycle 4: 7dBm

Cycle 5: 2dBm

## Resources...

[^1]: https://en.wikipedia.org/wiki/Received_signal_strength_indicator#RSSI-based_distance_estimation
[^2]: https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/src/WiFiGeneric.h
[^3]: https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/
