

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "homecontrol-7622c.firebaseio.com"
#define FIREBASE_AUTH "guGbFq5GTTbA1EDTlVGfrqEUojgFxLUMs5K78Hja"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "0987654321"
String value = "";
String first,second,third,fourth;
String var;

void setup() 
{
Serial.begin(9600);
Wire.begin(D1,D2);
  // connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) 
{
Serial.print(".");
delay(500);
}

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
int n = 0;
void loop()
{
Wire.beginTransmission(8); 
first = Firebase.getString("first");      //getting string from first node
second = Firebase.getString("second");
third = Firebase.getString("third");
fourth = Firebase.getString("fourth");
var = first +"+"+ second+ "+" +third+ "+" +fourth;
Serial.println(first);
 Wire.write(var.c_str());  //convert the string into character buffer
 Wire.endTransmission();    

}
