/***************************************************
                 Smart Dust Bin
                  #TEAM Pi BOTS
               FOLLOW AND SUPPORT
                    @pi_bots

         CONTACT FOR TECHNICAL ASSISTANCE
                   Instagram
           -------------------------
              >>  @at_mega_328p
            
 ****************************************************/

#define trigPin 5
#define echoPin 6
#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(7);
  
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
 
  Serial.println(distance);
  delay(100);
}
