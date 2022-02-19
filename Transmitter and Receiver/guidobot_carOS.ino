/*
 * Car OS. 
 * Receive data from sensor, sends signal to activate air jack, lift, and GuidoBot
 * for GuidoBot
 * 
 * Using HC-12, HC-05, Relay module, and Servo motor (miniature lift) on Arduino Mega
 * PROTOTYPE
 * 
 * references:
 * https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-12-long-range-wireless-communication-module/
 * https://create.arduino.cc/projecthub/electropeak/getting-started-with-hc-05-bluetooth-module-arduino-e0ca81
 * https://howtomechatronics.com/tutorials/arduino/control-high-voltage-devices-arduino-relay-tutorial/
 * https://docs.arduino.cc/learn/electronics/servo-motors
 */

#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial HC12(14,15); // HC-12 connected to TX Pin 14, RX Pin 15
SoftwareSerial HC05(16,17); // HC-05 connected to TX pin 16, RX pin 17
int relay_pin = 5;          // Relay control connected to Pin 5
int servo_pin = 4;          // Servo control connected to pin 4

Servo servo_lift;
int pos;   //variable to store servo position

char incomingByte;
String readBuffer = "";   //variable to store data from HC-12

void setup() {
  
  HC12.begin(9600);
  HC05.begin(9600);
  pinMode(relay_pin, OUTPUT);  //set relay pin as output
  digitalWrite(relay_pin, LOW);
  servo_lift.attach(servo_pin);         //attach servo on pin 4 to object servo_lift

}

void loop() {
  
  readBuffer = "";        //string to store data: which tire has less-than-normal pressure
  boolean start = false;
  
  while(HC12.available()){
    incomingByte = HC12.read();          // Store each icoming byte from HC-12
    delay(5);
    // Reads the data between the start "s" and end marker "e"
    if (start == true) {
      if (incomingByte != 'e') {
        readBuffer += char(incomingByte);    // Add each byte to ReadBuffer string variable
      }
      else {
        start = false;
      }
    }
    // Checks whether the received message statrs with the start marker "s"
    else if ( incomingByte == 's') {
      start = true; // If true start reading the message
    }
  }

  float sensor_value = readBuffer.toFloat();  //convert sensor value from string to float
  
  if(sensor_value <= 32){             //if pressure is below standard (32 psi)
    digitalWrite(relay_pin, HIGH);    // activate relay to turn on air jack
    
    for (pos=0; pos <=150; pos+=1){   //rotate servo across 150 degrees
      //in steps of 1 degree each 15 ms
      servo_lift.write(pos);
      delay(15);
    }

    HC05.write("1");                //send signal to activate GuidoBot
  }

}
