#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "Realme 5g";
const char* password = "11111111";

unsigned long myChannelNumber = 2936584;
const char* myWriteAPIKey = "S6SPLDU2JF104RF5";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    data.trim();

    float mainCurrent = 0.0, theftCurrent = 0.0;
    int theftDetected = 0;

    // Check if format contains Main and Theft
    if (data.startsWith("Main:") && data.indexOf(",Theft:") != -1) {
      int theftIndex = data.indexOf(",Theft:");
      String mainStr = data.substring(5, theftIndex);  // Extract main current
      mainCurrent = mainStr.toFloat();

      // Now get the theft current part
      int secondComma = data.indexOf(",", theftIndex + 7);
      if (secondComma == -1) secondComma = data.length();  // for Normal line

      String theftStr = data.substring(theftIndex + 7, secondComma);
      theftCurrent = theftStr.toFloat();

      // Determine if theft is detected
      if (data.indexOf("Theft Detected") != -1) {
        theftDetected = 1;
      } else {
        theftDetected = 0;
      }

      // Cap values
      if (mainCurrent > 1.8) mainCurrent = 1.8;
      if (theftCurrent > 1.8) theftCurrent = 1.8;

      // Send to ThingSpeak
      ThingSpeak.setField(1, mainCurrent);
      ThingSpeak.setField(2, theftCurrent);
      ThingSpeak.setField(3, theftDetected);

      int status = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
      if (status == 200) {
        Serial.println("✅ Data sent to ThingSpeak successfully");
      } else {
        Serial.print("❌ Error sending data. Code: ");
        Serial.println(status);
      }
    } else {
      Serial.println("❌ Invalid data format received.");
    }
  }

  delay(15000);  // Wait before next attempt (ThingSpeak limit)
}
