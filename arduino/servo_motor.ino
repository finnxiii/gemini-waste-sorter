#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  // Attaching pins and setting servos to default postition
  servo1.attach(9);
  servo2.attach(10);
  Serial.begin(9600);
  servo1.write(0);
  servo2.write(90);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    String incoming = Serial.readStringUntil('\n');
    incoming.trim(); // remove any spaces or newlines

    char command = incoming.charAt(0);  // Get the first character

    switch (command) {
      case '1': // Organic
        servo1.write(0);
        delay(3000);
        servo2.write(135);
        delay(3000);
        servo2.write(90);
        servo1.write(0);
        break;

      case '2': // Plastic recyclable
        servo1.write(0);
        delay(3000);
        servo2.write(135);
        delay(3000);
        servo2.write(90);
        servo1.write(0);
        break;

      case '3': // Paper recyclable
        servo1.write(180);
        delay(3000);
        servo2.write(135);
        delay(3000);
        servo2.write(90);
        servo1.write(0);
        break;

      case '4': // Other
        servo1.write(180);
        delay(3000);
        servo2.write(45);
        delay(3000);
        servo2.write(90);
        servo1.write(0);
        break;

      default:
        // Unknown input - This case is unlikely to happen
        break;
    }
  }
}
