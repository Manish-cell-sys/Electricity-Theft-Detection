#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ACS712.h"

ACS712 mainSensor(ACS712_20A, A1);    // Main line current sensor on A1
ACS712 theftSensor(ACS712_20A, A2);   // Theft line current sensor on A2
LiquidCrystal_I2C lcd(0x27, 16, 2);   // LCD I2C 16x2 display

const int buzzerPin = 9;              // Passive Buzzer on digital pin 9
const float theftThreshold = 0.06;    // Theft current threshold

bool theftPreviouslyDetected = false;
unsigned long theftStartTime = 0;
const unsigned long beepDuration = 10000;  // 10 seconds in milliseconds

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  mainSensor.calibrate();
  theftSensor.calibrate();

  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin); // Ensure buzzer is off
}

void loop() {
  float mainCurrent = mainSensor.getCurrentAC();
  float theftCurrent = theftSensor.getCurrentAC();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Main: ");
  lcd.print(mainCurrent, 2);
  lcd.print("A");

  lcd.setCursor(0, 1);
  lcd.print("Theft: ");
  lcd.print(theftCurrent, 2);
  lcd.print("A");

  delay(500);

  // Theft detected
  if (theftCurrent >= theftThreshold) {
    if (!theftPreviouslyDetected) {
      tone(buzzerPin, 1000); // Start beeping
      theftStartTime = millis(); // Start time tracking
      theftPreviouslyDetected = true;

      // Show theft alert on LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Theft Detected!");
      lcd.setCursor(0, 1);
      lcd.print("M:");
      lcd.print(mainCurrent, 2);
      lcd.print(" T:");
      lcd.print(theftCurrent, 2);

      // Serial alert
      Serial.print("Main:");
      Serial.print(mainCurrent, 2);
      Serial.print(",Theft:");
      Serial.print(theftCurrent, 2);
      Serial.println(",Theft Detected");
    } else {
      // Check if 10 seconds passed
      if (millis() - theftStartTime >= beepDuration) {
        noTone(buzzerPin); // Stop buzzer after 10s
      }
    }
  } else {
    // No theft: reset everything
    noTone(buzzerPin);
    theftPreviouslyDetected = false;

    // Send normal status via Serial
    Serial.print("Main:");
    Serial.print(mainCurrent, 2);
    Serial.print(",Theft:");
    Serial.print(theftCurrent, 2);
    Serial.println(",Normal");
  }

  delay(1000);
}
