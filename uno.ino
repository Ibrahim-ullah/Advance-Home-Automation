
String data = "30+20+10+5+.1+2+3+4.1+2+3+4.1+2+3+4.";
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
bool ledState1 = true;
bool ledState2 = true;
bool ledState3 = true;
bool ledState4 = true;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;

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
 collecting_data();
}

void loop()
{
  // put your main code here, to run repeatedly:
   unsigned long currentMillis = millis(); // grab current time
 
 
//  check if "interval" time has passed (1000 milliseconds)
 if (((unsigned long)(currentMillis - previousMillis1) >= interval1) && flag1 == 0)
 {
   ledState1 = !ledState1; // "toggles" the state
   digitalWrite(7, ledState1); // sets the LED based on ledState
   // save the "current" time
   previousMillis1 = millis();
   flag1++;
 }
 
   if (((unsigned long)(currentMillis - previousMillis2) >= interval2) && flag2 == 0)
 {
   ledState2 = !ledState2; // "toggles" the state
   digitalWrite(8, ledState2); // sets the LED based on ledState
   // save the "current" time
   previousMillis2 = millis();
   flag2++;
 }
  if (((unsigned long)(currentMillis - previousMillis3) >= interval3) && flag3 == 0)
 {
   ledState3 = !ledState3; // "toggles" the state
   digitalWrite(12, ledState3); // sets the LED based on ledState
   // save the "current" time
   previousMillis3 = millis();
   flag3++;
 }
  if (((unsigned long)(currentMillis - previousMillis4) >= interval4) && flag4 == 0)
 {
   ledState4 = !ledState4; // "toggles" the state
   digitalWrite(13, ledState4); // sets the LED based on ledState
   // save the "current" time
   previousMillis4 = millis();
   flag4++;
 }
// while(1)
//  {}
}

void collecting_data()
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



