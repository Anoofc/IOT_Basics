/***************************************************
     Adafruit MQTT Sensor Data Reading Example
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
 
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#include "DHT.h"        // Import Library to the Code
#define DHTPIN 2        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // Define DHT Type as DHT11

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "__SSID__"
#define WLAN_PASS       "__Password__"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "Your_Username"
#define AIO_KEY         "You_AIO_Key"

/************ Global State (you don't need to change this!) ******************/

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'sensor' for publishing.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish photocell = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temperature");
Adafruit_MQTT_Publish photocell1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/humidity");

/*************************** Sketch Code ************************************/
DHT dht(DHTPIN, DHTTYPE);

void MQTT_connect();

void setup() {
  Serial.begin(9600);
  delay(10);     
  dht.begin();    //Initiate DHT11
  
  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());


}

uint32_t x=0;

void loop() {
  
  MQTT_connect();
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("\nSending Sensor Data "));
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  Serial.print("...");
  // Now we can publish stuff!

  if (! photocell.publish(t)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  if (! photocell1.publish(h)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
delay(2000);
}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
