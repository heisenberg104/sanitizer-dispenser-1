//initilization for utrasonic sensor
int trigger_pin = 6;
int eco_pin = 7;
int RGB_Red = 10;

int time ;
int distance ;

int IRSensor = 2;
int Relay_pump = 9;
int LED_blue = 5;

int RGB_Green = 11;

int IRSensor_status = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trigger_pin,OUTPUT);
  pinMode(eco_pin,INPUT);
  pinMode(RGB_Red,OUTPUT);
  
  pinMode(IRSensor,INPUT);
  pinMode(Relay_pump,OUTPUT);
  pinMode(RGB_Green,OUTPUT);

  attachInterrupt(0,sensorDetect,RISING);

}

void loop() {

  IRSensor_status = digitalRead(IRSensor);

  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);

  time = pulseIn(eco_pin,HIGH);
  distance = (time*0.034)/2;

  if(distance >= 10)
   {
      Serial.println("REFILL");
      digitalWrite(RGB_Red,HIGH);
      delay(500);
      digitalWrite(RGB_Red,LOW);
      delay(500);
    }
  else
  {
   Serial.println("SANITIZER_OKK"); 
   digitalWrite(RGB_Green,HIGH); 
  }
  

}


void sensorDetect()
{
  
  if(IRSensor_status == 1)
    {
      digitalWrite(Relay_pump,LOW);
      delay(2000);
    }
  else
    {
      digitalWrite(Relay_pump,HIGH);
      delay(2000);
    }  
  
}
