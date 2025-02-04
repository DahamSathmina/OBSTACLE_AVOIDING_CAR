# OBSTACLE_AVOIDING_CAR
Obstacle Avoiding Car - Arduino Project 🤖
📌 Overview
This project is an Arduino-based autonomous car that detects obstacles and avoids collisions using ultrasonic sensors. It employs an L293D Motor Shield to control the movement of four DC motors, enabling smooth navigation with smart turning logic and dynamic speed control.

🔹 Features
✅ Autonomous Navigation – Moves forward and avoids obstacles automatically.
✅ Three Ultrasonic Sensors – Front, Left, and Right sensors for better decision-making.
✅ Dynamic Speed Control – Adjusts speed based on the distance from obstacles.
✅ Smart Turning Logic – Decides whether to turn left or right based on sensor data. 
✅ Efficient Power Management – Uses a battery pack for mobile operation.

🛠 Hardware Requirements
Component	Quantity	Purpose
Arduino Uno / Mega	1	Microcontroller
L293D Motor Shield	1	Motor driver module
HC-SR04 Ultrasonic Sensors	3	Distance measurement (Front, Left, Right)
DC Motors + Wheels	4	Movement
Battery Pack	1	Power supply
⚡ Circuit Diagram & Connections
Ultrasonic Sensor (Front)
TRIG → D12
ECHO → D13
Ultrasonic Sensor (Left)
TRIG → D10
ECHO → D11
Ultrasonic Sensor (Right)
TRIG → D8
ECHO → D9
Motor Shield (L293D) Connections
Motor 1 & 2 → Left side wheels
Motor 3 & 4 → Right side wheels
📝 Code Explanation
The Arduino sketch consists of:

🔹 Distance Measurement Function – Uses ultrasonic sensors to detect obstacles.
🔹 Dynamic Speed Control – Adjusts the motor speed based on proximity to obstacles.
🔹 Obstacle Avoidance Logic

If no obstacle detected → Moves forward.
If obstacle detected → Stops, moves backward, then turns left/right based on space availability.
🔹 Smart Turning Mechanism – Uses left & right ultrasonic sensors to decide the best turn direction.
🚀 Installation & Uploading Code
Install the Arduino IDE – Download here.
Install Required Library:
Open Arduino IDE → Sketch → Include Library → Manage Libraries
Search for AFMotor and install Adafruit Motor Shield Library.
Upload the Code:
Connect Arduino via USB.
Select Board & Port in Arduino IDE.
Click Upload to flash the code.
Power the Car using batteries and test the navigation.
🛠 How It Works
1️⃣ The car moves forward while continuously checking for obstacles.
2️⃣ If an obstacle is detected, it stops and reverses.
3️⃣ The car analyzes left & right sensor readings to decide the best direction.
4️⃣ It then turns and resumes forward movement.
5️⃣ The cycle repeats, allowing autonomous movement in an environment.

🔧 Future Enhancements
🔹 Bluetooth Remote Control – Switch between manual & autonomous mode using a mobile app.
🔹 Machine Learning Navigation – Implement AI to optimize movement paths.
🔹 IR Sensors for Edge Detection – Prevent falling off tables or ledges.
🔹 Voice Command Support – Integrate Google Assistant or Alexa for control.

📜 License
This project is open-source under the MIT License.

🔹 Contribute, Improve, and Make it Better! 🌟
If you find this project useful, don’t forget to give it a ⭐ on GitHub! 🚀


