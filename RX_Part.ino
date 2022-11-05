/*
 * Hey Everybody! This is the Code of Receiver/Car Part 
 * Hope you have understood everything. If you didn't watch the video again www.youtube.com/channel/UC2wOUBB0Ck44l4usUx6l2sQ
 * Thank You!
 * Please Like, Share and Subscribe
 */
#include <VirtualWire.h>//Adding Library

int m1 = 13;//
int m2 = 12;//
int m3 = 11;//
int m4 = 10;//definig motor pins
int ledPin = 9;//
int ledPin1 = 6;//definig led pins
int buzzPin = 8;//defining buzzer pins
int rxPin = 7;//definig receiver pin
int dt = 0; //definig delay

void setup()
{
  vw_set_rx_pin(rxPin);//setting up receiver pin
  vw_setup(2000);// setting up bitrate for receiver
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);//setting motor pins as "output"
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(buzzPin,OUTPUT);// defing led & buzzer pins as "output"
  vw_rx_start();//starting up receiver
  Serial.begin(9600);//setting up serial monitor/setting baudrate
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;//setting up message lengths

  if(vw_get_message(buf, &buflen))
  {
    if(buf[0] == 'f')
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);            
      Serial.println("FORWARD");
    }

    else if(buf[0] == 'b')
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH);
      digitalWrite(m3,LOW);
      digitalWrite(m4,HIGH);
      digitalWrite(buzzPin,HIGH);
      delay(250);
      digitalWrite(buzzPin,LOW);
      delay(250);
      Serial.println("BACKWARD");
    }

    else if(buf[0] == 'r')
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,HIGH);
      Serial.println("RIGHT");
    }

    else if(buf[0] == 'l')
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
      Serial.println("LEFT");
    }

   else if(buf[0] == 's')
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,LOW);
      Serial.println("STOP");
    }

    else if(buf[0] == 'h')
    {
      digitalWrite(buzzPin,HIGH);
    }

    else if(buf[0] == 'c')
    {
      digitalWrite(buzzPin,LOW);
    }

    if(buf[0]=='a')
    {  
      digitalWrite(ledPin,HIGH);
      digitalWrite(ledPin1,HIGH);
    }  
    else if(buf[0]=='k')
    {
      digitalWrite(ledPin,LOW);
      digitalWrite(ledPin1,LOW);
    }
  }                                     //conditions
  
  delay(dt); //delay 
}

 
