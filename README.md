# 🔌 Electricity Theft Detection System (IoT-Based)

This project detects electricity theft using dual current sensors and reports data to ThingSpeak using an ESP8266 WiFi module. It uses an Arduino UNO to monitor power consumption from the main and theft lines, display data on an LCD, and trigger alerts.

---

## 📟 Features

- Detects electricity theft based on abnormal current on a parallel line
- Displays real-time current readings on 16x2 I2C LCD
- Sounds buzzer when theft is detected for 10 sec
- Sends data to ThingSpeak (Main current, Theft current, Theft alert)

---

## 🛠️ Hardware Used

- Arduino UNO
- ESP8266 WiFi module
- ACS712 20A Current Sensors (x2)
- LCD 16x2 with I2C module
- Passive Buzzer
- Breadboard & Jumper Wires
- Bulbs (for load and theft simulation)
- 9V/12V Adapter or Step-down power supply

---

## 📡 ThingSpeak Fields

- **Field 1:** Main Line Current (A)
- **Field 2:** Theft Line Current (A)
- **Field 3:** Theft Detected (1 = Yes, 0 = No)

---

## 📁 File Descriptions

- `ESP8266_ThingSpeak_Code.ino`: Connects ESP8266 to WiFi and uploads serial data to ThingSpeak.
- `Arduino_UNO_Code.ino`: Reads current from sensors, triggers buzzer/LCD alerts, and sends formatted data over Serial.

---

## 📷 Preview
![IMG-20250601-WA0003](https://github.com/user-attachments/assets/5183b428-64aa-4cef-959a-bda0a81ead40)
 https://drive.google.com/drive/folders/1vV6ZWmZiXyuWrhnqMFM4NVz2zUjux4Cw


---

## 🧠 Future Scope

- Add relay control to cut off the load automatically
- Integrate Firebase or mobile app monitoring
- Improve security with password access

---

## 👨‍💻 Created by

**Manish Kumar Jonewal**  
Electrical Engineering, RTU Kota  
Project Year: 2025
