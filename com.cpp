#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int obstacleThreshold = 20;  // Distance threshold in centimeters to stop the rover

void setup() {
  SerialBT.begin("RoverESP32");  // Bluetooth device name
  Serial.begin(9600);  // Serial communication with Arduino
  
  // Initialize other setup tasks as needed
}

void loop() {
  if (Serial.available() > 0) {
    // Read data from Arduino
    String data = Serial.readStringUntil('\n');
    
    // Process the received data (e.g., parse distance measurements)
    int distance = data.toInt(); // Assuming Arduino sends distance as an integer
    
    // Check if an obstacle is detected within the threshold
    if (distance < obstacleThreshold) {
      // Implement code to stop the rover here
      // For example, you can print a message to indicate the stop.
      SerialBT.println("Obstacle detected! Stopping rover.");
      stopRover(); // Call the stopRover() function to implement motor control.
    }
    
    // Example: Print the received data to Bluetooth
    SerialBT.print("Received data from Arduino: ");
    SerialBT.println(distance);
  }
  
  // Add your rover control logic here
}

void stopRover() {
  // Implement the logic to stop the rover here
  // For example, you can print a message to indicate stopping.
  Serial.println("Stopping rover...");
  
  // You should replace this example code with your actual motor control logic.
  // For example, if you're using an L298N motor driver:
  // digitalWrite(motorEnablePin, LOW); // Disable motors
}
