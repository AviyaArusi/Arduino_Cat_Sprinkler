// // version 1 the sprinkler turn off when detect something.

// #include <Wire.h>
// #include <VL53L0X.h>

// VL53L0X sensor;

// const int sprinklerPin = 3; // Relay module connected to pin 3
// const int threshold = 100; // Threshold for movement detection (in millimeters)

// unsigned long sprinklerOnTime = 0;
// const long sprinklerOnDuration = 5000; // Sprinkler ON duration: 5 seconds

// int previousDistance = 0;

// void setup() {
//   Serial.begin(9600);
//   Wire.begin();

//   pinMode(sprinklerPin, OUTPUT);
//   digitalWrite(sprinklerPin, LOW); // Sprinkler normally OFF

//   if (!sensor.init()) {
//     Serial.println("Failed to detect and initialize sensor!");
//     while (1);
//   }

//   sensor.startContinuous();
//   previousDistance = sensor.readRangeContinuousMillimeters(); // Initialize previous distance
// }

// void loop() {
//   int currentDistance = sensor.readRangeContinuousMillimeters();
  
//   // Check for significant change in distance
//   if (abs(currentDistance - previousDistance) > threshold) {
//     if (sprinklerOnTime == 0) { // Ensures the sprinkler turns on only if it is currently off
//       turnOnSprinkler();
//     }
//   }

//   // If the sprinkler is on and the duration has passed, turn it back off
//   if (sprinklerOnTime > 0 && (millis() - sprinklerOnTime) > sprinklerOnDuration) {
//     turnOffSprinkler();
//   }

//   previousDistance = currentDistance; // Update the previous distance
//   delay(50); // Small delay to avoid too rapid readings
// }

// void turnOnSprinkler() {
//   digitalWrite(sprinklerPin, HIGH); // Sprinkler turns ON
//   sprinklerOnTime = millis(); // Start timing the ON period
//   Serial.println("Sprinkler ON");
// }

// void turnOffSprinkler() {
//   digitalWrite(sprinklerPin, LOW); // Sprinkler turns OFF
//   sprinklerOnTime = 0; // Reset the timer
//   Serial.println("Sprinkler OFF");
// }

// Version 2 the sprinkler turn on when detect somthing
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

const int sprinklerPin = 3; // Relay module connected to pin 3
const int threshold = 100;  // Threshold for movement detection (in millimeters)

unsigned long sprinklerOffTime = 0;
const long sprinklerOffDuration = 5000; // Sprinkler OFF duration: 5 seconds

int previousDistance = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(sprinklerPin, OUTPUT);
  digitalWrite(sprinklerPin, HIGH); // Sprinkler normally ON

  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }

  sensor.startContinuous();
  previousDistance = sensor.readRangeContinuousMillimeters(); // Initialize previous distance
}

void loop() {
  int currentDistance = sensor.readRangeContinuousMillimeters();

  // Check for significant change in distance (movement)
  if (abs(currentDistance - previousDistance) > threshold) {
    if (sprinklerOffTime == 0) { // Sprinkler is currently ON
      turnOffSprinkler();
    }
  }

  // Turn the sprinkler back ON after the OFF duration has passed
  if (sprinklerOffTime > 0 && (millis() - sprinklerOffTime) > sprinklerOffDuration) {
    turnOnSprinkler();
  }

  previousDistance = currentDistance; // Update the previous distance
  delay(50); // Small delay to avoid too rapid readings
}

void turnOnSprinkler() {
  digitalWrite(sprinklerPin, HIGH); // Sprinkler turns ON
  sprinklerOffTime = 0;             // Reset the OFF timer
  Serial.println("Sprinkler ON");
}

void turnOffSprinkler() {
  digitalWrite(sprinklerPin, LOW);       // Sprinkler turns OFF
  sprinklerOffTime = millis();           // Start timing the OFF period
  Serial.println("Sprinkler OFF");
}

