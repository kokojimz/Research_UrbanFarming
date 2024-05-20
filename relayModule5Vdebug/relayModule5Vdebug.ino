#include <ESP8266WiFi.h>

#define waterPump 4
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(waterPump, LOW);
  delay(1000);
  digitalWrite(waterPump, HIGH);
  delay(1000);

}
