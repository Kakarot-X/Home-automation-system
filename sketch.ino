
#include <Servo.h>


//pin mappings 
const int ldrPin = A0;
const int ledpin=13;
const int pirpin=8;
const int switchpin=4;
const int buzzerpin=2;
const int temppin=A1;
const int fanpin=10;


//servo motor config
int pos = 0;
Servo servo_9;
int direction=+4;//initial vector for fan direction

int ldrThreshold = 1014 ;

int tempThreshhold=35;//threshhold for turning on the funin celcius

void setup() {
  //pin setup
  pinMode(ledpin,OUTPUT);
  pinMode(switchpin,INPUT);
  pinMode(pirpin,INPUT);
  pinMode(buzzerpin,OUTPUT);
  pinMode(temppin,INPUT);
  servo_9.attach(fanpin, 500, 2500);
  
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int pirvalue=digitalRead(pirpin);
  int switchvalue =digitalRead(switchpin);
  int rawValue = analogRead(temppin);
  
  //analog to proper temp conversion with precision adjustment
  float voltage = rawValue * (5.0 / 1023.0);
  float temperatureC = round((voltage - 0.5) * 100.0 );
  
  
  //automatic lighting system core
  if(ldrValue<ldrThreshold && pirvalue>0){
    digitalWrite(ledpin,HIGH);
  }else{digitalWrite(ledpin,LOW);delay(100)}
  
  //Security alert System
  if(pirvalue>0 &&switchvalue==1){
    digitalWrite(buzzerpin,HIGH);delay(100);
  }else{digitalWrite(buzzerpin,LOW);}
  
  
  //fan activation using temperature monitoring core
  if(temperatureC>tempThreshhold){
    if(pos>=180){direction=-4;
    }else if(pos<=0){direction=+4;}
   
    
    pos=fanhandler(pos,direction);
  }

  delay(200); 
}


int  fanhandler(int pos,int direction)
{
  //moves the fan according to the direction
  pos=pos+direction;
  servo_9.write(pos);
  return pos;

}
