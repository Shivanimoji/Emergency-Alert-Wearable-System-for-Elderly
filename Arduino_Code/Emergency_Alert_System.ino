
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

// Wi-Fi details
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Configure your notification server URL
const char* alertURL = "YOUR_NOTIFICATION_URL";

// ESP32 pin connections
#define BUTTON_PIN 18
#define BUZZER_PIN 19

// Prototype impact threshold (m/s^2)
const float FALL_THRESHOLD = 20.0;

unsigned long lastAlertTime = 0;
const unsigned long ALERT_DELAY = 10000;

void sendAlert(String message) {
  Serial.println("EMERGENCY: " + message);

  // Activate buzzer
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);

  // Send notification if server is configured
  if (WiFi.status() == WL_CONNECTED &&
      String(alertURL) != "YOUR_NOTIFICATION_URL") {

    HTTPClient http;
    http.begin(alertURL);
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"message\":\"" + message + "\"}";

    int response = http.POST(payload);

    Serial.print("Server response: ");
    Serial.println(response);

    http.end();
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Wire.begin();

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 not detected!");
    while (true) {
      delay(1000);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("MPU6050 initialized");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi connected");
}

void loop() {
  unsigned long now = millis();

  // Read sensor data
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temperature;

  mpu.getEvent(&accel, &gyro, &temperature);

  // Calculate acceleration magnitude
  float magnitude = sqrt(
    accel.acceleration.x * accel.acceleration.x +
    accel.acceleration.y * accel.acceleration.y +
    accel.acceleration.z * accel.acceleration.z
  );

  Serial.print("Acceleration: ");
  Serial.println(magnitude);

  // Manual emergency button
  if (digitalRead(BUTTON_PIN) == LOW &&
      now - lastAlertTime > ALERT_DELAY) {

    sendAlert("Manual emergency assistance requested");
    lastAlertTime = now;
  }

  // Possible impact detection
  if (magnitude > FALL_THRESHOLD &&
      now - lastAlertTime > ALERT_DELAY) {

    sendAlert("Possible fall or sudden impact detected");
    lastAlertTime = now;
  }

  delay(100);
}

