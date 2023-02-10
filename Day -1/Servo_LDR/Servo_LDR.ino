/***************************************************
        IR Sensor - LED digitalRead Example
                  #TEAM Pi BOTS
               FOLLOW AND SUPPORT
                    @pi_bots

         CONTACT FOR TECHNICAL ASSISTANCE
                   Instagram
           -------------------------
            >>  @at_mega_328p
            >>  @tech.xplorer
            >>  @__the_limitless__
 ****************************************************/

#include <Servo.h>  // Include Servo Library

int servo = D2;      // Digital Pin 1 of nodemcu
int ldr = A0;       // Analog Pin 0 of nodemcu

int ldrval;         // Variable to store LDR value
int mapval;         // Variable to store Mapped value to degree

Servo servo1;

void setup() {
  Serial.begin(9600);   // Enable Serial Monitor
  pinMode(ldr,INPUT);   // Enable the LDR pin As input
  servo1.write(90);     // Set initial Position of servo

}

void loop() {
  ldrval = analogRead(ldr);                   // Read LDR Value
  Serial.println(ldrval);                     // Print Light Intensity On Serial Monitor
  mapval = map(ldrval, 0, 1023, 0, 180);      // Reducing LDR input value to 0-180. 
  servo1.write(mapval);                       // Write the Reduced value to Servo Signal Pin
  //delay(250);
  Serial.println(mapval);
}
