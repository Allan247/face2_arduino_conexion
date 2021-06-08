#include <Stepper.h>

const int stepsPerRevolution = 2048;  


Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;       


const int trigPin = 13;
const int echoPin = 12;


long duration;
int distance;

void setup() {
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myStepper.setSpeed(1);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration*0.034/2;
 
  int motorSpeed = map(distance, 0, 30, 15, 1);
  if(motorSpeed <1){
    motorSpeed = 1;
  }
  myStepper.setSpeed(motorSpeed);
  myStepper.step(stepsPerRevolution/10);

}
