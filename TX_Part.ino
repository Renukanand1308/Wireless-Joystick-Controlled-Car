/*
 * Hey Everybody! This is the Code of Transmitter/Remote Part 
 * Hope you have understood everything. If you didn't watch the video again www.youtube.com/channel/UC2wOUBB0Ck44l4usUx6l2sQ
 * Thank You!
 * Please Like, Share and Subscribe
 */
#include <VirtualWire.h>//Adding Library

char *data;//definig a variable to store and send data

int xPin = A1;//defining joystick's x pin
int yPin = A2;//defining joystick's y pin
int sPin = 6;//defining joystick's switch pin
int s1Pin = 5;//defining joystick's switch pin


int xVal;//defining variable to store x data
int yVal;//defining variable to store y data
int sVal;//defining variable to store switch data
int s1Val;//defining variable to store switch1 data
int value = 0;//defining variable to set switch as low

int dt = 0;
int t = 0;

void setup()
{
  vw_set_tx_pin(7);//setting up transmitter pin
  vw_setup(2000);//setting up bitrate for transmitter
  pinMode(xPin,INPUT);//setting joystick's x pin as "output"
  pinMode(yPin,INPUT);//setting joystick's y pin as "output"
  pinMode(sPin,INPUT_PULLUP);
  pinMode(s1Pin,INPUT_PULLUP);//setting up inbuilt PULLUP resistors for the switches
  Serial.begin(9600);//setting up serial monitor/setting baudrate
}

void loop()
{
  xVal = analogRead(xPin);//reading x value of joystick
  yVal = analogRead(yPin);//reading y value of joystick
  sVal = digitalRead(sPin);//reading switch value of joystick
  s1Val = digitalRead(s1Pin);//reading switch1 value of joystick

  Serial.print(" X Value = ");
  Serial.print(xVal);
  Serial.print("   Y Value = ");
  Serial.print(yVal);
  Serial.print("   S Value = ");
  Serial.print(sVal);
  Serial.print("   S1 Value = ");
  Serial.println(s1Val);//printing all the values read
  delay(dt);   

  if(xVal<490)
  {
    data = "f";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);    
  }

  if(xVal>515)
  {
    data = "b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);    
  }

  if(yVal<490)
  {
    data = "r";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);    
  }

  if(yVal>515)
  {
    data = "l";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);    
  }

  
  if(xVal<515 && xVal>490 && yVal<515 && yVal>490)
  {
    data = "s";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);    
  }  

  if(s1Val == 0)
  {
    data = "h";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);
  }

  if(s1Val == 1)
  {
    data = "c";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);
  }

  if(sVal == LOW && value == 0)
  {
    data="a";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);
    value = 1;
  }
  else if(sVal == LOW && value == 1)
  {
    data="k";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(t);
    value = 0;
  }                                     //conditions
  delay(t);//delay
}
