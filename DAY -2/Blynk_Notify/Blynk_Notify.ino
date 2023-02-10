/***************************************************
 
                  #TEAM PI BOTS
               FOLLOW AND SUPPORT
                    @pi_bots

         CONTACT FOR TECHNICAL ASSISTANCE
                 Instagram.com
           -------------------------
            >>  @at_mega_328p
            >>  @tech.xplorer
            >>  @__the_limitless__
            
 ****************************************************/
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>                    // Include ESP8266 wifi Library
#include <BlynkSimpleEsp8266.h>             // Include Blynk Library

char auth[] = "...auth_token...";           // Security KEY
char ssid[] = "...SSID...";                 // Your Network Name
char pass[] = "...Password...";             // Your Network Password

int ir = D1;
int value=0;

void setup() {
  Serial.begin(9600);               // Enable Serial Communication
  Blynk.begin(auth, ssid, pass);    // Initialises the WiFi Connection, Connects to the Server
  pinMode(ir, INPUT);     
}
  
void loop() {
  
  Blynk.run();                      // Runs the Blynk Core as Loop
  
  value = digitalRead(ir);
  if (value==HIGH){
    Blynk.notify("Action Detected...!!");    // Send Notification on Blynk App
    }
  delay(500);
}
