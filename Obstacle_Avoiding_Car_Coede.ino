#include <AFMotor.h> // Library for motor control using L293D Motor Shield

// Define Ultrasonic Sensor Pins
#define TRIG 12 // Trigger pin for Ultrasonic Sensor
#define ECHO 13 // Echo pin for Ultrasonic Sensor

// Initialize Motors (Using Motor Shield Ports 1, 2, 3, and 4)
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  pinMode(TRIG, OUTPUT); // Set TRIG as output
  pinMode(ECHO, INPUT); // Set ECHO as input
  Serial.begin(9600); // Start Serial Communication
}

// Function to measure distance using Ultrasonic Sensor
long measureDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  return pulseIn(ECHO, HIGH) * 0.034 / 2; // Convert time to distance in cm
}

// Function to move the car forward
void moveForward() {
  motor1.setSpeed(255); // Set motor speed to maximum
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// Function to move the car backward
void moveBackward() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

// Function to turn the car left
void turnLeft() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(BACKWARD); // Left motors move backward
  motor2.run(FORWARD); // Right motors move forward
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  delay(300); // Turn duration
}

// Function to turn the car right
void turnRight() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(FORWARD); // Left motors move forward
  motor2.run(BACKWARD); // Right motors move backward
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(300); // Turn duration
}

// Function to stop the car
void stopCar() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  long distance = measureDistance(); // Get distance from sensor
  Serial.println(distance); // Print distance to Serial Monitor
  if (distance > 20) { // If no obstacle detected, move forward
    moveForward();
  } else { // If obstacle detected, take action
    stopCar(); // Stop the car
    delay(200);
    moveBackward(); // Move backward
    delay(400);
    stopCar();
    if (random(0, 2) == 0) { // Randomly choose a direction to turn
      turnLeft();
    } else {
      turnRight();
    }
  }
}
