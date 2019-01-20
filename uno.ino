#include <Wire.h>
String data = "";   //String for collecting data from wire.read
int index = 20;       //defining a maximum index that is possible
void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Serial.begin(9600);           /* start serial for debug */
}

void loop() {
 delay(100);
 for (int i = 0; i < 20; i++)
 {
  Serial.print(data[i]);
 }
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available())
 {
  if ( index  > 1)
  {
    char c = Wire.read();      /* receive byte as a character */
    data += c;
    index--;
  }          /* print the character */
  }
 Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master

