DRISHTI: Intelligent Safety Stick for the Visually Impaired

Project DRISHTI (दृष्टिः Vision) is an open-source, smart electronic travel aid designed to enhance the mobility and safety of visually impaired individuals. It acts as an intelligent guardian by integrating multiple sensors to provide real-time environmental awareness and an automated emergency alert system.

This project addresses the key limitations of traditional aids, which cannot detect head-level obstacles or ground-level hazards like puddles. It also tackles the critical challenge of summoning help quickly after a fall and the economic inaccessibility of commercial smart canes, which can cost from ₹15,000 to over ₹50,000. By leveraging an ESP32 microcontroller and common components, DRISHTI offers a powerful, low-cost, and reliable safety device.

✨ Key Features
Proactive Obstacle Detection: An ultrasonic sensor detects forward obstacles within a 1 m range. When an obstacle is detected, it provides a 2-second haptic (vibration) warning to the user.

Automated Fall Detection: An integrated MPU-6050 accelerometer accurately detects the unique G-force signature associated with a user fall.

Multi-Stage SOS System: Upon detecting a fall, a dual-alert system is immediately activated:

Local Alarm: A loud, continuous buzzer sounds to alert people in the immediate vicinity for help.

Remote Alert: Simultaneously, a signal is sent via Bluetooth LE to a companion smartphone app. The app then automatically sends a pre-written emergency SMS to a designated contact.

Intuitive Feedback: The system uses both haptic feedback (vibration) for obstacles and audible alerts (buzzer) for emergencies, providing clear and distinct warnings.

Rechargeable Power System: Powered by a standard 3.7V 18650 Li-ion battery, featuring a TP4056 module for safe and easy charging via a standard USB port.

🛠️ Hardware & Software
Hardware Components
Microcontroller: ESP32

Sensors:
Ultrasonic Sensor (for obstacle detection)
MPU-6050 Accelerometer & Gyroscope (for fall detection)

Actuators:
Vibration Motor (for haptic feedback)
Buzzer (for audible alerts)

Connectivity: Bluetooth Low Energy (BLE)

Software
Firmware: Developed in C++ (Arduino Framework) for the ESP32.

Companion App: A mobile application that receives Bluetooth signals to trigger emergency SMS alerts.

🔭 Future Scope
GPS Navigation: Integrating a GPS module to provide haptic turn-by-turn directions to pre-saved locations.

Advanced Ground Sensing: Upgrading to Time-of-Flight (ToF) laser sensors for more accurate detection of potholes and puddles, even in bright sunlight.

AI on the Edge: Using an ESP32-CAM to run a lightweight machine learning model to recognize and announce specific objects like 'stairs' or 'motorcycle'.

📜 Conclusion
Project DRISHTI successfully demonstrates an affordable, reliable, and feature-rich safety device for the visually impaired. Its offline-first design and use of low-cost components make it a practical and scalable solution to real-world challenges. It is more than a prototype; it is a platform for empowerment that offers a tangible increase in safety, confidence, and independence for its users.
