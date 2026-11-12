# Emergency Alerting System for the Elderly

## 1. Project Overview

The Emergency Alerting System for the Elderly is an IoT-based wearable safety system designed to detect accidental falls and provide timely emergency alerts to caregivers or family members.

The system uses an ESP32 microcontroller and an MPU6050 motion sensor to continuously monitor the user's movements. The MPU6050 combines a 3-axis accelerometer and a 3-axis gyroscope to measure acceleration, angular velocity and orientation.

When the system identifies a sudden movement or impact that exceeds a predefined threshold, the ESP32 triggers an audible alert through a buzzer and uses its built-in Wi-Fi connectivity to send an emergency notification.

The system also includes a manual request assistance button, allowing the user to request help directly during an emergency.

## 2. Problem Statement

Elderly individuals, particularly those living alone, may experience accidental falls and injuries. In many situations, they may be unable to reach a phone or contact someone for assistance.

Delayed emergency response can increase the risk of serious complications. Therefore, a reliable system is required to monitor movement, identify possible falls and notify caregivers as quickly as possible.

This project aims to develop a cost-effective and wearable fall detection system using sensors, a microcontroller and wireless communication technology.

## 3. Objectives

- Develop an IoT-based emergency alerting system for elderly individuals.
- Detect sudden movements and possible falls using the MPU6050 sensor.
- Monitor acceleration, angular velocity and orientation.
- Process sensor readings using the ESP32 microcontroller.
- Generate an audible alert using a buzzer when a possible fall is detected.
- Provide a manual emergency assistance button.
- Send emergency notifications through Wi-Fi.
- Reduce delays in providing assistance to elderly users.

## 4. Hardware Components

| Component | Function |
|---|---|
| ESP32 | Main controller for processing sensor data and Wi-Fi communication |
| MPU6050 | Measures acceleration, angular velocity and orientation |
| Push Button | Allows the user to manually request assistance |
| Buzzer | Produces an audible emergency alert |
| Power Supply | Provides power to the system |

## 5. Software Requirements

- Arduino IDE
- Embedded C/C++
- ESP32 board support package
- MPU6050 sensor library
- Serial Monitor and Serial Plotter for testing and debugging

## 6. Working Principle

The system continuously monitors the user's movement through the MPU6050 sensor.

1. **Initialization:** The ESP32 and MPU6050 sensor are initialized and configured.
2. **Sensor Reading:** The MPU6050 collects real-time acceleration and gyroscope readings.
3. **Data Processing:** The ESP32 processes the sensor values and calculates movement-related parameters such as acceleration, jerk and orientation angles.
4. **Threshold Comparison:** The calculated values are compared with predefined threshold values.
5. **Fall Detection:** If the measured impact or jerk exceeds the configured threshold, the system identifies a possible fall.
6. **Audible Alert:** The ESP32 activates the buzzer to notify nearby people.
7. **Wireless Notification:** The ESP32 uses Wi-Fi to send an emergency alert to caregivers or connected devices.
8. **Manual Assistance:** The user can also press the request assistance button to raise an alert manually.

If the readings remain below the threshold, the system continues monitoring the user's movements.

## 7. Fall Detection Algorithm

The fall detection process uses motion data collected by the MPU6050 sensor.

- Read acceleration values along the X, Y and Z axes.
- Read gyroscope values to understand rotational movement.
- Calculate movement-related parameters such as acceleration, jerk and orientation.
- Compare the calculated values with the predefined threshold.
- If the threshold is exceeded, trigger the fall alert.
- Otherwise, continue monitoring the sensor readings.

The project report describes the threshold calculation as:

**Threshold = Mean magnitude / 2**

Mean magnitude = 17.375

Threshold = 17.375 / 2 = 8.6875

Approximate threshold = **9**

## 8. Key Features

- Real-time motion monitoring.
- Automatic detection of possible fall events.
- Manual emergency assistance button.
- Audible alert through a buzzer.
- Wi-Fi-based emergency notification.
- MPU6050-based acceleration and gyroscope monitoring.
- Low-cost ESP32-based implementation.
- Wearable safety-system concept.

## 9. Testing and Results

The prototype was implemented on a perforated board and tested under different movement conditions.

### Test Case 1: Rest Conditions
The sensor was monitored when the user was sleeping, sitting or standing. The readings remained relatively stable with minor variations.

### Test Case 2: Normal Movements
The system was tested during walking, bending and casual movements. The sensor captured changes in movement without treating every normal movement as a fall.

### Test Case 3: Slow Tilts
The device was gradually tilted at 30°, 60° and 90° angles to observe changes in sensor readings and orientation.

### Test Case 4: Rapid Tilts
Quick tilting movements at 45°, 90° and 120° were performed to study sudden changes in acceleration and jerk.

### Test Case 5: Fall Detection
The system was tested for sudden impact conditions. The sensor readings showed noticeable spikes during fall-like movements, which were used to evaluate the threshold-based detection process.

The Serial Monitor and Serial Plotter were used to observe and analyse sensor readings during testing.

## 10. Applications

- Elderly care and personal safety.
- Home-based fall monitoring.
- Assisted living facilities.
- Healthcare monitoring systems.
- Safety monitoring for individuals with mobility challenges.

## 11. Advantages

- Affordable hardware components.
- Compact and wearable design concept.
- Automatic and manual emergency alert options.
- Wireless communication through ESP32 Wi-Fi.
- Continuous motion monitoring.
- Easy integration with IoT-based systems.

## 12. Future Enhancements

- Integrate GPS to share the user's exact location during emergencies.
- Develop a mobile application for caregivers.
- Improve fall detection accuracy using machine learning algorithms.
- Add heart-rate monitoring and other health sensors.
- Improve battery efficiency for longer operation.
- Develop a compact smartwatch, pendant or fitness-band design.
- Improve the detection algorithm to reduce false alerts.

## 13. Conclusion

The Emergency Alerting System for the Elderly demonstrates how embedded systems, motion sensors and IoT connectivity can be combined to improve personal safety.

By integrating the ESP32 microcontroller with the MPU6050 sensor, the system monitors movement and identifies possible fall events using predefined threshold values. The buzzer provides an immediate audible indication, while Wi-Fi connectivity supports emergency notifications to caregivers. A manual assistance button provides an additional way for users to request help.

The project provides a cost-effective prototype for elderly safety monitoring and demonstrates the practical application of embedded systems and IoT technology in healthcare.

## 14. Project Information

- **Project Title:** Emergency Alerting System for the Elderly
- **Domain:** Internet of Things (IoT) and Embedded Systems
- **Microcontroller:** ESP32
- **Motion Sensor:** MPU6050
- **Programming Language:** Embedded C/C++
- **Development Environment:** Arduino IDE
- **Academic Year:** 2024–2025
- **Department:** Electronics and Communication Engineering

## 15. Repository Structure

```text
Emergency-Alerting-System-for-the-Elderly/
│
├── README.md
├── Arduino_Code/
│   └── Emergency_Alert_System.ino
│
├── Circuit_Diagram/
│   └── circuit_diagram.png
│
├── Block_Diagram/
│   └── block_diagram.png
│
├── Screenshots/
│   ├── serial_monitor.png
│   ├── rest_condition.png
│   ├── normal_movement.png
│   └── fall_detection.png
│
└── Documentation/
    └── Mini_Project_Report.pdf
```

