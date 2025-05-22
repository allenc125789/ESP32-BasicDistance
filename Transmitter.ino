#include <esp_now.h>
#include <WiFi.h>
#include "esp_wifi.h"

// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xB0, 0x81, 0x84, 0x04, 0x97, 0x88};
int loopcount = 0;
int txpower = 0;
bool confirmTx = 0;
//Pin Out
const int ledPin =  3;    // Pin D1
const int buzzerPin =  4;    // Pin D2

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  bool p;
} struct_message;

// Create a struct_message called myData
struct_message myData;
esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  //Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  if (status == ESP_NOW_SEND_SUCCESS){
    confirmTx = true;
  } else {
    confirmTx = false;
  }
}

void sendTx(){
  // Set values to send
  myData.p = true;
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
}

void selectTxPower(int loopcount){
    if (loopcount == 0){
        txpower = WIFI_POWER_19dBm;      // 19dBm
    } else if (loopcount == 1){
        txpower = WIFI_POWER_15dBm;      // 15dBm
    } else if (loopcount == 2){
        txpower = WIFI_POWER_11dBm;      // 11dBm
    } else if (loopcount == 3){
        txpower = WIFI_POWER_7dBm;       //  7dBm
    } else if (loopcount == 4){
        txpower = WIFI_POWER_2dBm;       //  2dBm
    }
    esp_wifi_set_max_tx_power(txpower);
    //Serial.println(WiFi.getTxPower());
}

void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

  //Set Pin mode.
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

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

void loop() {
  //Sets Wi-Fi Transmission range.
  selectTxPower(loopcount);

  //Sends and confirms Message transmission.
  sendTx();
  if (confirmTx == true){
    //Activates pins depending on confirmation of range.
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  } else {
    delay(200);
  }
  delay(200);

  //Determines stage of loop
  loopcount += 1;
  if (loopcount == 5){
    loopcount = 0;
  }
}
