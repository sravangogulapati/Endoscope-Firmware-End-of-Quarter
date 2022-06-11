#include "WiFi.h"

#define WIFI_NETWORK "SpectrumSetup-2F"
#define WIFI_PASSWORD "zoneimmune208"
#define WIFI_TIMEOUT_MS 20000

void connectToWiFi(){
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

  unsigned long startAttemptTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS){
    Serial.print(".");
    delay(100);
    Serial.print("Failed");
  }

  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Failed!");
  }
  else{
    Serial.print("Connection Succesful!");
    Serial.println(WiFi.localIP());
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  connectToWiFi();
}

void loop() {
  // put your main code here, to run repeatedly:

}
