# Circuit Connections

## ESP32 to MPU6050

| MPU6050 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## ESP32 to Push Button

| Push Button Pin | ESP32 Connection |
|---|---|
| One terminal | GPIO 18 |
| Other terminal | GND |

## ESP32 to Buzzer

| Buzzer Pin | ESP32 Connection |
|---|---|
| Positive (+) | GPIO 19 |
| Negative (-) | GND |

## Working
- MPU6050 sends motion data to ESP32 through I2C communication.
- Push button provides manual emergency activation.
- Buzzer produces an audible alert.
- ESP32 uses Wi-Fi to send emergency notifications.
