#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define BEACON_UUID "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"

BLEAdvertising *pAdvertising;

void setup() {
  Serial.begin(115200);
  
  BLEDevice::init("EchoSOS Beacon");
  BLEServer *pServer = BLEDevice::createServer();
  pAdvertising = pServer->getAdvertising();
  
  BLEUUID serviceUUID(BEACON_UUID);
  pAdvertising->addServiceUUID(serviceUUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->start();
  
  Serial.println("EchoSOS Beacon Active");
}

void loop() {
  // Keep broadcasting the signal
  delay(1000);
}
