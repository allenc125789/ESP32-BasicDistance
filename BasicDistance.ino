/*
  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*/
#include <esp_now.h>
#include <WiFi.h>
#include "esp_wifi.h"

// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xB0, 0x81, 0x84, 0x04, 0x97, 0x88};
int loopcount = 0;
int txpower = 0;
const int ledPin =  0;    // the number of the LED pin

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  char a[32];
  int b;
  float c;
  bool d;
} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);


  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

void selectTxPower(int state){
    if (state == 0){
        txpower = WIFI_POWER_19dBm;      // 19dBm
        digitalWrite(ledPin, HIGH);
    } if (state == 1){
        txpower = WIFI_POWER_17dBm;      // 17dBm
    } if (state == 2){
        txpower = WIFI_POWER_15dBm;      // 15dBm
    } if (state == 3){
        txpower = WIFI_POWER_13dBm;      // 13dBm
    } if (state == 4){
        txpower = WIFI_POWER_11dBm;      // 11dBm
    } if (state == 5){
        txpower = WIFI_POWER_7dBm;       //  7dBm
    } if (state == 6){
        txpower = WIFI_POWER_5dBm;       //  5dBm
    } if (state == 7){
        txpower = WIFI_POWER_2dBm;       //  2dBm
    }
}



void loop() {
  // Set values to send
  loopcount += 1;
  strcpy(myData.a, "THIS IS A CHAR");
  myData.b = random(1,20);
  myData.c = 1.2;
  myData.d = false;
  
  selectTxPower(loopcount);
  esp_wifi_set_max_tx_power(txpower);
  Serial.println(WiFi.getTxPower());
  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }

  if (loopcount == 7){
    loopcount = 0;
  }
  digitalWrite(ledPin, LOW);
  delay(200);
}
