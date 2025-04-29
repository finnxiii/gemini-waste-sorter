# ♻️ S.O.R.T.S. – Smart Object Recognition Trash Sorting System

🏆 **Winner of “Most Adventurous Hack” – iForge Hack Day 2025**

S.O.R.T.S. is an AI-powered smart trash sorting prototype designed to automate waste classification using embedded systems and real-time image recognition. Built at a MLH hackathon, it demonstrates how embedded AI can tackle real-world sustainability challenges.

---

## 🚀 Features

- 📸 Image capture using ESP32-CAM
- 🧠 AI-based waste classification via Google Gemini Vision API
- 🤖 Sorting control with Arduino Uno R4 WiFi
- 🌐 Offline functionality via local Wi-Fi hotspot
- ♻️ Separates recyclable, compostable, and landfill items

---

## 🛠️ Technologies Used

- **Hardware:** Arduino Uno R4 WiFi, ESP32-CAM  
- **Software:** Python, Google Gemini 2.0 Flash Model  
- **Networking:** Local Wi-Fi hotspot  
- **Tools:** Arduino IDE, VS Code  

---

## 📸 How It Works

1. ESP32-CAM captures an image of the trash.
2. Image is sent to a Python script that queries Google Gemini’s Vision model.
3. Based on the classification result, Arduino directs trash to the correct bin.
4. System works over a local hotspot for communication between the components.
5. Only the python running device needs internet to access Gemini API.

P.S. A better version would be to control the directing of trash also with the ESP32-CAM module but due to time constraints, we used an extra arduino.

---

## 👥 Team

- Naing Htoo Lwin  
- Phone Linn Khant  
- Nadav T Chong  
- Mohammad Ridwaan Joomun

---

## 💡 Inspiration

With growing waste issues globally, we wanted to prototype a low-cost, AI-driven solution that could be scaled in smart cities, schools, or public venues to improve sustainability.

---

## 📷 Screenshots & Demo

Coming soon – stay tuned!
