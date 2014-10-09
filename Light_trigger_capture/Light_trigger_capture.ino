
// HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
//#include <Ultrasonic.h>

#define US_TRIGGER_PIN  4
#define US_ECHO_PIN     3
#define PHOTOCELL_PIN 2; // 光敏電阻 (photocell) 接在 anallog pin 2
int photocellVal = 0; // photocell variable

//Ultrasonic ultrasonic(US_TRIGGER_PIN, US_ECHO_PIN);

void setup()
{
  Serial.begin(115200);
   pinMode(13, OUTPUT);    
}

void Capture()
{
  digitalWrite(5, HIGH); 
  delay(200);
  digitalWrite(5, LOW); 
}

void loop()
{
  //float cmMsec, inMsec;
  //long microsec = ultrasonic.timing();

  //cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離&#65292;單位: 公分
  //inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離&#65292;單位: 英吋
  

  // 讀取光敏電阻並輸出到 Serial Port 
  photocellVal = analogRead(2);
  Serial.print("photocellVal=");
  Serial.println(photocellVal);  

  delay(10);
  if ( photocellVal> 50)
  {
    Capture(); 
    Serial.print("HUGH?");
  digitalWrite(13, HIGH); 
  }
  else 
  {
     Serial.print("LOW?");
  digitalWrite(13, LOW); 
  }
}
