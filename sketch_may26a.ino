int sensor = A0;  // define analog pin A0. (input/sensor)
int led1 = 8; // define pin 8 for led1 (output)
int led2 = 11;  // define pin 11 for led2 (output)
int led3 = 13;  // define pin 13 for led3 (output)
const int switchPin = 2; //Switch Connected to PIN 2
int switchState = 0; // Variable for reading Switch status


void setup()
{
  Serial.begin(9600); //sets serial communication between arduino and computer
  pinMode(sensor,INPUT); // sets analog pin A0 as input.
  pinMode(led1,OUTPUT); //sets pin 8 as output.
  pinMode(led2,OUTPUT); //sets pin 11 as output.
  pinMode(led3,OUTPUT); //sets pin 13 as output.
  pinMode(switchPin, INPUT);//Switch PIN is input with PULLUP
}

void loop()
{
  switchState = digitalRead(switchPin); //Reads the status of the switch.
  int value = analogRead(sensor); // sets variable "value" to store value of sensor.
  value = value / 10; // divide the value so it is not so big
  Serial.println(value); //prints values in serial monitor
  delay(500); //half a second delay
  if((value >=61) && (value <=70))
  {
     digitalWrite(led1,HIGH); //turns LED on.
     digitalWrite(led2,LOW); //turns LED off.
     digitalWrite(led3,LOW); //turns LED off.
  }
  else if(value>=50 && value <=60)
  {
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH); 
    digitalWrite(led3,LOW); 
  }
  else if(value < 50)
  {
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH); 
    digitalWrite(led3,HIGH); 
  }
  else
  {
    digitalWrite(led1,LOW); 
    digitalWrite(led2,LOW); 
    digitalWrite(led3,LOW); 
  }
   if (switchState == HIGH) //If the switch is pressed turns off all leds
   {
     digitalWrite(led1,LOW); 
     digitalWrite(led2,LOW); 
     digitalWrite(led3,LOW); 
   }
}
