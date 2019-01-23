
String data = "1+2+3+4+.1+2+3+4.1+2+3+4.1+2+3+4.";
int val[] = {0, 0, 0, 0};
char variable[20];
char c = '+';
int j = 0;
String load1,load2,load3,load4;
unsigned long interval1,interval2,interval3,interval4;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
bool ledState1 = false;
bool ledState2 = false;
bool ledState3 = false;
bool ledState4 = false;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(7, OUTPUT);
 digitalWrite(7, ledState1);
  pinMode(8, OUTPUT);
 digitalWrite(8, ledState2);
  pinMode(12, OUTPUT);
 digitalWrite(12, ledState3);
  pinMode(13, OUTPUT);
 digitalWrite(13, ledState4);
 collecting_duratoin();
}

void loop()
{
  // put your main code here, to run repeatedly:
   unsigned long currentMillis = millis(); // grab current time
 
 

 if ((unsigned long)(currentMillis - previousMillis1) >= interval1)
 {
   ledState1 = !ledState1; // "toggles" the state
   digitalWrite(7, ledState1); // sets the LED based on ledState
   // save the "current" time
   previousMillis1 = millis();
 }
 
   if ((unsigned long)(currentMillis - previousMillis2) >= interval2)
 {
   ledState2 = !ledState2; // "toggles" the state
   digitalWrite(8, ledState2); // sets the LED based on ledState
   // save the "current" time
   previousMillis2 = millis();
 }
  if ((unsigned long)(currentMillis - previousMillis3) >= interval3)
 {
   ledState3 = !ledState3; // "toggles" the state
   digitalWrite(12, ledState3); // sets the LED based on ledState
   // save the "current" time
   previousMillis3 = millis();
 }
  if ((unsigned long)(currentMillis - previousMillis4) >= interval4)
 {
   ledState4 = !ledState4; // "toggles" the state
   digitalWrite(13, ledState4); // sets the LED based on ledState
   // save the "current" time
   previousMillis4 = millis();
 }
// while(1)
//  {}
}

void collecting_duration()
{
   for (int i = 0; i < 20 ; i++)
  {
    variable[i] = data[i];
  }
   for ( int i = 0; i < 20; i++)
  {
     if (variable[i] == c)
     {
      val[j] = i;
      j++;
     }
   }
   String load1= data.substring(0,val[0]);
   String load2=data.substring(val[0]+1,val[1]);
   String load3=data.substring(val[1]+1,val[2]);
   String load4=data.substring(val[2]+1,val[3]);
   interval1 = (load1.toInt())*1000;
   interval2 = (load2.toInt())*1000;
   interval3 = (load3.toInt())*1000;
   interval4 = (load4.toInt())*1000;
}





