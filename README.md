## Description

Guages distance by adjusting the ESP32C3's wifi transmission power.

Cycles between 8 levels of signal streangth. Then sends a simple bool statement through the ESP-NOW protocol, and if recieved, will power an LED and a piezo buzzer. As distance shortens between the transmitter and reciever, the higher frequency the `distancePin` will light up.

## Distance Calculation

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
