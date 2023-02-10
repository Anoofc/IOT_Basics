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

int led = D1;      // Digital Pin 1 of nodemcu
int ldr = A0;       // Analog Pin 0 of nodemcu

int ldrval;         // Variable to store LDR value
int mapval;         // Variable to store Mapped value to degree


void setup() {
  Serial.begin(9600);   // Enable Serial Monitor
  pinMode(ldr,INPUT);   // Enable the LDR pin As input
  pinMode(led,OUTPUT);  // Enable the LED pin as OUTPUT

}

void loop() {
  ldrval = analogRead(ldr);                   // Read LDR Value
  Serial.println(ldrval);                     // Print Light Intensity On Serial Monitor
  //mapval = map(ldrval, 0, 1023, 0, 255);      // Reducing LDR input value to 0-180. 
  //analogWrite(mapval);                        // Write the value to led Pin
  if (ldrval<700 && ldrval>400){
    digitalWrite(led,HIGH);
    }

    else{
      digitalWrite(led,LOW);
      }
  delay(250);
}
