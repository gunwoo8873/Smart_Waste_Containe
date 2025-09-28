#include <Servo.h>

#define triggerPin1 8
#define echoPin1 9
#define triggerPin2 10
#define echoPin2 11
#define ledPin 7
#define servoPin 13

Servo servo;

void setup() {
    Serial.begin(9600);
    pinMod(triggerPin1, OUTPUT);
    pinMod(echoPin1, INPUT);
    pinMod(triggerPin2, OUTPUT);
    pinMod(echoPin2, INPUT);
    pinMod(ledPin, OUTPUT);
    servo.attach(servoPin);
}

void loop() {
    long duration, distance;
    digitalWrite(triggerPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin1, LOW);
    duration = pulseIn(echoPin1, HIGH);
    distance = (duration / 2) / 58.8;
    Serial.print("Distance 1: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 20) {
        servo.write(95);
        delay(3000);
    } else {
        servo.write(0);
    }

    digitalWrite(triggerPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin2, LOW);
    duration = pulseIn(echoPin2, HIGH);
    distance = (duration / 2) / 58.8;
    Serial.print("Distance 2: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 20) {
        digitalWrite(ledPin, HIGH);
        servo.write(90);
    } else {
        digitalWrite(ledPin, LOW);
        servo.write(0);
    }
    
    delay(500);
}
