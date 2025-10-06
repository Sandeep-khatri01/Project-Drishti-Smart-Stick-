// LIBRARIES - including the BLE libraries
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// PIN DEFINITIONS - As you provided
#define ULTRASONIC_TRIG_PIN 14
#define ULTRASONIC_ECHO_PIN 12
#define MOTOR_PIN           26
#define BUZZER_PIN          32

// SENSOR OBJECTS AND THRESHOLDS
Adafruit_MPU6050 mpu;
#define OBSTACLE_DISTANCE_CM 30.0
#define FALL_THRESHOLD      35.0 // This is very sensitive, perfect for testing!

// BLUETOOTH SETUP
BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// --- BLUETOOTH SERVER CALLBACKS ---
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      Serial.println("Phone Connected");
    }
    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      Serial.println("Phone Disconnected");
    }
};

void setup() {
  Serial.begin(115200);
  
  // Setup all component pins
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Initialize MPU-6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) { delay(10); }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  
  // --- Create the BLE Device ---
  BLEDevice::init("DRISHTI_Stick");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
  pCharacteristic->addDescriptor(new BLE2902());
  pService->start();
  BLEDevice::startAdvertising();
  Serial.println("DRISHTI Stick Initialized. Waiting for connection...");
}

void loop() {
  // --- Check 1: Forward Obstacle Detection ---
  long duration, distance;
  // Trigger the ultrasonic sensor to send out a pulse
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  
  // Read the echo time and calculate distance
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  bool isObstacleAhead = (distance < OBSTACLE_DISTANCE_CM && distance > 0);

  if (isObstacleAhead) {
    Serial.print("OBSTACLE WARNING: Detected at ");
    Serial.print(distance);
    Serial.println(" cm.");
    
    // Vibrate motor for 5 seconds, as you requested
    digitalWrite(MOTOR_PIN, HIGH);
    delay(2000);
    digitalWrite(MOTOR_PIN, LOW);
    
    // A short pause after the alert to prevent immediate re-triggering
    delay(1000); 
  }

  // --- Check 2: Automated Fall Detection ---
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float total_accel = sqrt(pow(a.acceleration.x, 2) + pow(a.acceleration.y, 2) + pow(a.acceleration.z, 2));

  if (total_accel > FALL_THRESHOLD) {
    Serial.println("FALL DETECTED! Activating local alarm and sending SOS signal...");
    
    // Action 1: Send the Bluetooth SOS signal to the phone
    if (deviceConnected) {
      pCharacteristic->setValue("FALL"); // Send the string "FALL"
      pCharacteristic->notify();
      Serial.println("SOS Signal 'FALL' sent to phone.");
    }

    // Action 2: Activate the local buzzer alarm
for(int i=0;i<20;i++){
      digitalWrite(BUZZER_PIN, HIGH); delay(500);
      digitalWrite(BUZZER_PIN, LOW); delay(500);
    
  }

  delay(100); 
}
}