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

int ir = D1;            // Define IR Sensor Pin
int led = D2;           // Define LED Pin
int irval;              // Variable to store IR sensor Value
int state = 0;          // Variable To store the IR switch State 

void setup() {
  
  pinMode(ir, INPUT);       // Enable IR Sensor pin as INPUT
  pinMode(led, OUTPUT);     // Enable LED Pin as OUTPUT


}

void loop() {

  

  

 
  irval = digitalRead(ir); 
  if (irval == LOW) {       
  if (state == 0) {         // change state if sensor reads low
      state = 1;
    }
    else {
      state = 0;
    }
  }
  if (state == 1) {
    digitalWrite(led, HIGH);      //  turn on led if state is equal to one.
  }
  else if (state == 0) {
    digitalWrite(led, LOW);
  } 

  delay(350);
  

}
