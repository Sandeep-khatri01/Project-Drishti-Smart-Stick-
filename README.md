# [cite_start]DRISHTI: Intelligent Safety Stick for the Visually Impaired [cite: 1]

[cite_start]Project DRISHTI (दृष्टिः Vision) is an open-source, smart electronic travel aid designed to enhance the mobility and safety of visually impaired individuals[cite: 3]. [cite_start]It acts as an intelligent guardian by integrating multiple sensors to provide real-time environmental awareness and an automated emergency alert system[cite: 4].

[cite_start]This project addresses the key limitations of traditional aids, which cannot detect head-level obstacles or ground-level hazards like puddles[cite: 7]. [cite_start]It also tackles the critical challenge of summoning help quickly after a fall [cite: 9] [cite_start]and the economic inaccessibility of commercial smart canes, which can cost from ₹15,000 to over ₹50,000[cite: 10]. [cite_start]By leveraging an ESP32 microcontroller and common components, DRISHTI offers a powerful, low-cost, and reliable safety device[cite: 5].

---

## ✨ Key Features

* [cite_start]**Proactive Obstacle Detection**: An ultrasonic sensor detects forward obstacles within a 1 m range[cite: 20]. [cite_start]When an obstacle is detected, it provides a 2-second haptic (vibration) warning to the user[cite: 21].
* [cite_start]**Automated Fall Detection**: An integrated MPU-6050 accelerometer accurately detects the unique G-force signature associated with a user fall[cite: 22].
* [cite_start]**Multi-Stage SOS System**: Upon detecting a fall, a dual-alert system is immediately activated[cite: 23]:
    * [cite_start]**Local Alarm**: A loud, continuous buzzer sounds to alert people in the immediate vicinity for help[cite: 24].
    * [cite_start]**Remote Alert**: Simultaneously, a signal is sent via Bluetooth LE to a companion smartphone app[cite: 25]. [cite_start]The app then automatically sends a pre-written emergency SMS to a designated contact[cite: 25].
* [cite_start]**Intuitive Feedback**: The system uses both haptic feedback (vibration) for obstacles and audible alerts (buzzer) for emergencies, providing clear and distinct warnings[cite: 17].
* [cite_start]**Rechargeable Power System**: Powered by a standard 3.7V 18650 Li-ion battery, featuring a TP4056 module for safe and easy charging via a standard USB port[cite: 26].

---

## 🛠️ Hardware & Software

### Hardware Components
* [cite_start]**Microcontroller**: ESP32 [cite: 5]
* **Sensors**:
    * [cite_start]Ultrasonic Sensor (for obstacle detection) [cite: 20]
    * [cite_start]MPU-6050 Accelerometer & Gyroscope (for fall detection) [cite: 22]
* **Actuators**:
    * [cite_start]Vibration Motor (for haptic feedback) [cite: 17]
    * [cite_start]Buzzer (for audible alerts) [cite: 17, 24]
* [cite_start]**Connectivity**: Bluetooth Low Energy (BLE) [cite: 5]

### Software
* **Firmware**: Developed in C++ (Arduino Framework) for the ESP32.
* [cite_start]**Companion App**: A mobile application that receives Bluetooth signals to trigger emergency SMS alerts[cite: 25].

---

## 🔭 Future Scope

* [cite_start]**GPS Navigation**: Integrating a GPS module to provide haptic turn-by-turn directions to pre-saved locations[cite: 34].
* [cite_start]**Advanced Ground Sensing**: Upgrading to Time-of-Flight (ToF) laser sensors for more accurate detection of potholes and puddles, even in bright sunlight[cite: 35].
* [cite_start]**AI on the Edge**: Using an ESP32-CAM to run a lightweight machine learning model to recognize and announce specific objects like 'stairs' or 'motorcycle'[cite: 36].

---

## 📜 Conclusion

[cite_start]Project DRISHTI successfully demonstrates an affordable, reliable, and feature-rich safety device for the visually impaired[cite: 38]. [cite_start]Its offline-first design and use of low-cost components make it a practical and scalable solution to real-world challenges[cite: 39]. [cite_start]It is more than a prototype; it is a platform for empowerment that offers a tangible increase in safety, confidence, and independence for its users[cite: 40].
