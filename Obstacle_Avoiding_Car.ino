//************************** ARDUINO OBSTACLE AVOIDING CAR **************************//
// L293D MOTOR DRIVER CONTROLLER
// Required Libraries: AFMotor, NewPing, Servo
// To Install the libraries go to sketch >> Include Library >> Manage Libraries.... >> Search Libbrary Name and Install //

#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// Pin Definitions
#define TRIG_PIN A0 // Ultrasonic sensor trigger pin
#define ECHO_PIN A1 // Ultrasonic sensor echo pin

// Constants
#define MAX_DISTANCE 300 // Maximum measurable distance in cm
#define MAX_SPEED 255 // Maximum speed for the motors
#define MAX_SPEED_INCREMENT 2 // Speed increment for gradual acceleration

// Objects
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // Ultrasonic sensor object
AF_DCMotor motor1(1, MOTOR12_1KHZ); // Motor 1 on port 1
AF_DCMotor motor2(2, MOTOR12_1KHZ); // Motor 2 on port 2
AF_DCMotor motor3(3, MOTOR34_1KHZ); // Motor 3 on port 3
AF_DCMotor motor4(4, MOTOR34_1KHZ); // Motor 4 on port 4
Servo myservo; // Servo motor object for ultrasonic sensor rotation

// Variables
bool isMovingForward = false; // Tracks if the car is moving forward
int distance = 100; // Distance to the nearest obstacle

void setup() {
  // Attach the servo to pin 10 and initialize its position
  myservo.attach(10);
  myservo.write(115); // Center position
  delay(2000);

  // Calibrate the initial distance readings
  calibrateDistance();
}

void loop() {
  delay(40); // Short delay for stability

  // Check if an obstacle is within the critical distance
  if (distance <= 15) {
    handleObstacle(); // Handle the obstacle by avoiding it
  } else {
    moveForward(); // Continue moving forward
  }

  // Update the distance measurement
  distance = readDistance();
}

// Calibrates the initial distance readings by averaging multiple measurements
void calibrateDistance() {
  for (int i = 0; i < 4; i++) {
    distance = readDistance();
    delay(100);
  }
}

// Handles obstacle avoidance logic
void handleObstacle() {
  moveStop(); // Stop the car
  delay(100);

  moveBackward(); // Move backward briefly
  delay(300);

  moveStop(); // Stop again
  delay(200);

  // Check distances on the right and left
  int distanceRight = lookDirection(50); // Look to the right
  int distanceLeft = lookDirection(170); // Look to the left

  // Turn towards the direction with more space
  if (distanceRight >= distanceLeft) {
    turnRight();
  } else {
    turnLeft();
  }

  moveStop(); // Stop after turning
}

// Rotates the servo to the specified angle and measures distance
int lookDirection(int angle) {
  myservo.write(angle); // Rotate servo to the angle
  delay(500); // Wait for servo to stabilize
  int measuredDistance = readDistance(); // Measure distance
  delay(100);
  myservo.write(115); // Reset servo to center position
  return measuredDistance; // Return the measured distance
}

// Reads the distance using the ultrasonic sensor
int readDistance() {
  delay(70); // Short delay for sensor stability
  int cm = sonar.ping_cm(); // Measure distance in cm
  return (cm == 0) ? 250 : cm; // Return 250 if no object detected
}

// Stops all motors
void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

// Moves the car forward gradually
void moveForward() {
  if (!isMovingForward) {
    isMovingForward = true; // Update movement state
    setMotorDirection(FORWARD); // Set all motors to move forward
    rampUpSpeed(); // Gradually increase speed
  }
}

// Moves the car backward gradually
void moveBackward() {
  isMovingForward = false; // Update movement state
  setMotorDirection(BACKWARD); // Set all motors to move backward
  rampUpSpeed(); // Gradually increase speed
}

// Turns the car to the right
void turnRight() {
  motor1.run(FORWARD); // Right-side motors forward
  motor2.run(FORWARD);
  motor3.run(BACKWARD); // Left-side motors backward
  motor4.run(BACKWARD);
  delay(500); // Short delay for turning
}

// Turns the car to the left
void turnLeft() {
  motor1.run(BACKWARD); // Right-side motors backward
  motor2.run(BACKWARD);
  motor3.run(FORWARD); // Left-side motors forward
  motor4.run(FORWARD);
  delay(500); // Short delay for turning
}

// Sets the direction for all motors
void setMotorDirection(uint8_t direction) {
  motor1.run(direction);
  motor2.run(direction);
  motor3.run(direction);
  motor4.run(direction);
}

// Gradually ramps up the motor speed to avoid sudden surges
void rampUpSpeed() {
  for (int speed = 0; speed < MAX_SPEED; speed += MAX_SPEED_INCREMENT) {
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    motor3.setSpeed(speed);
    motor4.setSpeed(speed);
    delay(5); // Small delay for gradual acceleration
  }
}
