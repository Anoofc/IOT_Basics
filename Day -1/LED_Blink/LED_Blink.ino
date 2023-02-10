/***************************************************
          LED Blink - digitalWrite Example
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

int led = D2;           // Store the Pin Number to a Variable so that you only have to change this number. 

void setup() {
  // This part Runs only Once after the board is Powered Up.
  // This Part defines the Digital pins we use in this Code.
  pinMode(led, OUTPUT);       // Enable D2 as OUTPUT.
  

}

void loop() {
  
  // This Part Runs Continuesly after the Setup part is run first.
  
  digitalWrite(led, HIGH);    // Turn the LED ON, ie, Make the D2 Pin HIGH.
  delay(1000);                // Wait for 1 Second till next Command Runs

  digitalWrite(led,LOW);      // Turn the LED OFF, ie, Make the D2 pin LOW. 
  delay(1000);                // Wait for One Second till the next command run, ie, the First Line since the void loop() is Continuous.
  
}
