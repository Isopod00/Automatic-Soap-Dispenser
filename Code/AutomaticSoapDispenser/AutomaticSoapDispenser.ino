//Automatic Soap Dispenser
//By Anthony Brogni

#include <Servo.h>  //Import the servo library
Servo myservo;      //Create a servo object to control the servo motor

const int trigPin = A0; //Trigger Pin of the Ultrasonic Sensor
const int echoPin = A1; //Echo Pin of the Ultrasonic Sensor

const int servoPin = 3; //The pin the servo motor is connected to 

const int maxDistance = 2; //How close (in inches) a hand should be to dispense soap

//Runs once at startup
void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(servoPin, 700, 2400);  //Assign the servo motor on pin 3 to the servo object
  myservo.write(20); //Move the servo to the starting position
}

//Loops repeatedly
void loop() {
  Serial.println(readDistance());
  
  if (readDistance() <= maxDistance) {
    dispense();
  }
   
  delay(100);
}

//Read the distance from the ultrasonic sensor (in inches)
long readDistance() {
  long duration;
   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   
  duration = pulseIn(echoPin, HIGH);
  return duration / 74 / 2;
}

//Dispense one pump of soap using the servo motor
void dispense() {
  delay(100);
  myservo.write(110);
  delay(1000);
  myservo.write(20);
  delay(1000);
}
