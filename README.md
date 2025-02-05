# OBSTACLE_AVOIDING_CAR
This project involves creating an advanced obstacle-avoiding car using Arduino, a motor driver, an ultrasonic sensor, and a servo motor. The car can dynamically detect obstacles, calculate optimal paths, and navigate around them with precision. The system is designed for scalability, allowing additional sensors and functionality to be integrated easily.

## 🕹️ Features
- **Intelligent Obstacle Detection:** Measures distances in multiple directions and chooses the optimal path dynamically.
- **Real-Time Navigation:** Continuously adapts to the environment for seamless movement.
- **Multi-Directional Servo Scanning:** Scans a wide range of angles to gather comprehensive environmental data.
- **Gradual Acceleration and Deceleration:** Ensures smooth motion and prevents mechanical wear.
- **Customizable Thresholds:** Critical distance values and speed parameters can be easily adjusted.
- **Modular Code Structure:** Facilitates adding more sensors or modifying functionality.

## 🔧 Components Required
1. Arduino Uno (or compatible board)
2. L293D Motor Driver Shield
3. HC-SR04 Ultrasonic Sensor
4. Servo Motor
5. DC Motors (4x)
6. Chassis for the car
7. Power supply (batteries or adapter)
8. Jumper wires and connectors

## 📊 Libraries Used
- **AFMotor:** For controlling motors via the L293D driver.
- **NewPing:** For interfacing with the ultrasonic sensor.
- **Servo:** For controlling the servo motor.

## 🔌 Circuit Diagram
Connect the components as follows:
1. Attach the motor driver shield to the Arduino board.
2. Connect the ultrasonic sensor's `TRIG` pin to `A0` and `ECHO` pin to `A1`.
3. Connect the servo motor's signal wire to pin `10`.
4. Connect the motors to the respective ports on the motor driver shield.
5. Provide power to the motor driver shield and Arduino.

## 🔄 Installation
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/your-username/advanced-obstacle-avoiding-car.git
   ```
2. Open the Arduino IDE and install the required libraries:
   - AFMotor
   - NewPing
   - Servo
3. Load the `advanced_obstacle_avoiding_car.ino` file into the Arduino IDE.
4. Verify and upload the code to your Arduino board.

## ⚛️ Advanced Functionality
### 🛠️ Setup Phase
- The servo is initialized to its center position.
- Distance is calibrated by taking multiple readings to ensure accuracy.

### ⏳ Main Loop
- Continuously measures the distance to obstacles in real time.
- Implements the following logic:
  - **Obstacle Handling:** If an obstacle is detected within a critical distance:
    - The car stops and reverses briefly.
    - The ultrasonic sensor scans both left and right.
    - The car turns towards the direction with the most clearance.
  - **Forward Movement:** If no obstacle is detected, the car moves forward smoothly.

### 🔄 Servo Scanning
- The servo rotates to predefined angles, providing multi-directional data.
- The sensor's scanning logic ensures precise navigation decisions.

### 🚗 Motor Control
- Uses the L293D shield to control all four motors independently.
- Handles forward, backward, left, and right movements with customizable speed and duration.

## 📂 Code Overview
The code is modular and organized for scalability, with the following key functions:
- `setup()`: Initializes the servo and calibrates the ultrasonic sensor.
- `loop()`: Manages real-time obstacle detection and navigation.
- `calibrateDistance()`: Ensures accurate distance readings during setup.
- `handleObstacle()`: Stops the car, analyzes surroundings, and determines the best route.
- `lookDirection(angle)`: Scans a specific angle and retrieves the distance.
- `readDistance()`: Reads and processes ultrasonic sensor data.
- `moveStop()`: Stops all motors.
- `moveForward()`: Gradually accelerates to move forward.
- `moveBackward()`: Smoothly reverses the car.
- `turnRight()`, `turnLeft()`: Executes turning maneuvers.
- `setMotorDirection(direction)`: Defines the direction for all motors.
- `rampUpSpeed()`: Implements a smooth acceleration curve.

## 🚀 Usage
1. Assemble the car and connect all components as per the circuit diagram.
2. Upload the code to your Arduino board.
3. Place the car on a flat surface.
4. Power on the car, and it will autonomously navigate while avoiding obstacles.

## ⚙️ Customization
- **Critical Distance Thresholds:** Adjust the `distance` variable to modify how close the car gets to obstacles.
- **Motor Speed:** Change `MAX_SPEED` and `MAX_SPEED_INCREMENT` for different performance levels.
- **Servo Angles:** Modify the angles in `lookDirection()` for broader or narrower scans.

## ❗ Troubleshooting
- **Car Not Moving:**
  - Verify motor connections and power supply.
- **Servo Not Responding:**
  - Check the servo's connection to pin 10 and ensure it receives power.
- **Sensor Not Detecting Obstacles:**
  - Ensure `TRIG` and `ECHO` pins are properly connected and the sensor is powered.

## 🎯 Future Enhancements
- **Additional Sensors:** Add infrared or LIDAR sensors for improved obstacle detection.
- **GPS Integration:** Enable navigation to specific coordinates.
- **Mobile App Control:** Incorporate Bluetooth or Wi-Fi for remote control.
- **Improved Algorithms:** Implement machine learning for smarter navigation.

## 🔒 License
This project is open-source and available under the [MIT License](LICENSE). Contributions and modifications are encouraged.

## 🖐️ Contribution
Contributions are welcome! If you have ideas for enhancements or new features, feel free to open an issue or submit a pull request.

## 👨‍💻 Author        
Developed by Daham. Reach out for suggestions and improvements! 

⭐ Don't forget to star the repository if you found this useful!


