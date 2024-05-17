#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const int soilMoisturePin = A0;
const int relayPin = 4;
const int moistureThreshold = 20; // Sesuaikan dengan kebutuhan

// Pengaturan WiFi
const char *ssid = "realme 5";
const char *password = "123456gg";
const char *host = "192.168.43.12"; // Alamat IP server (tanpa subnet)

int moisturePercentage; // Variabel moisturePercentage bukan konstanta

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, password); // Mulai koneksi WiFi

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Pastikan pompa dalam keadaan mati saat mulai
}

// Get the soil moisture values
void soilMoistureSensor() {
  int value = analogRead(soilMoisturePin);
  value = map(value, 1024, 0, 0, 100);
  moisturePercentage = value;
}

void runPumpOff() {
  digitalWrite(relayPin, LOW); 
  Serial.println("Watering activated"); 
}

void runPumpOn() {
  digitalWrite(relayPin, HIGH);
  Serial.println("Watering deactivated");
}

void loop()
{
  WiFiClient client;
  HTTPClient http;

  int sensorValue = analogRead(soilMoisturePin);
  Serial.println(soilMoisturePin);
  Serial.println(sensorValue);
  soilMoistureSensor();
  Serial.println(moistureThreshold);

  Serial.println("Soil Moisture: " + String(moisturePercentage) + "%");
  Serial.println(moisturePercentage);

  if (moisturePercentage < moistureThreshold)
    {
      runPumpOn();
      delay(2000); 
    }
    else
    {
      runPumpOff();
    }

  if (WiFi.status() == WL_CONNECTED)
  {
    String url = "http://" + String(host) + "/websensor_soil/sendSoilMoisture.php?sensor=" + String(moisturePercentage);
    Serial.println(url);

    http.begin(client, url);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
      String payload = http.getString();
      Serial.println(payload);
    }
    else
    {
      Serial.println("Error on HTTP request");
    }

    http.end(); 
  }
  else
  {
    Serial.println("Not connected to WiFi");
  }

  delay(1000);
}
