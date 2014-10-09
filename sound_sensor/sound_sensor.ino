int Test_led = 13;
int Sound_sensor_val = 0;
int Threshold = 3;
int Val_before_calibration = 0;
int Val_after_calibration = 0;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(Test_led, OUTPUT);     
  Sound_sensor_calibration();
}

// the loop routine runs over and over again forever:
void loop() {

  Sound_sensor_val= analogRead(A0);
  Serial.println(Sound_sensor_val);
  
  
  if (Sound_sensor_val > (Val_after_calibration+Threshold))
  {
  digitalWrite(Test_led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(Test_led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  }
}

void Sound_sensor_calibration()
{
  Val_before_calibration = analogRead(A0);
  
  for (int i =0; i<50 ; i++) 
  { 
  Val_after_calibration = analogRead(A0);
  Val_after_calibration = (Val_after_calibration+Val_before_calibration)/2;
  //Serial.print("Val_after_calibration=");
  //Serial.println(Val_after_calibration);
  delay(10);
  }
}

