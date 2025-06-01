# 🔌 Electricity Theft Detection System (IoT-Based)

This project detects electricity theft using dual current sensors and reports data to ThingSpeak using an ESP8266 WiFi module. It uses an Arduino UNO to monitor power consumption from the main and theft lines, display data on an LCD, and trigger alerts.

---

## 📟 Features

- Detects electricity theft based on abnormal current on a parallel line
- Displays real-time current readings on 16x2 I2C LCD
- Sounds buzzer for 10 sec when theft is detected 
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
![Screenshot_2025-06-01-21-40-23-56_99c04817c0de5652397fc8b56c3b3817](https://github.com/user-attachments/assets/c841b3fd-87c9-4dcf-816f-0bb643f763d2)
![Screenshot_2025-06-01-21-40-42-56_99c04817c0de5652397fc8b56c3b3817](https://github.com/user-attachments/assets/5421380a-c4ec-4b8c-9eb7-9b12dd1f42c3)
![IMG20250429232940](https://github.com/user-attachments/assets/dec82951-0b4c-4262-9881-8d40203e0072)



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
