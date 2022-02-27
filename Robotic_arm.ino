#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <Servo.h>

Servo servo_1,servo_2,servo_3,servo_4;

//Create function for callback named
// TW for Take the wheel
// RABN for release and assembly bolt and nut
// DTW for drop the wheel
// ATW for assembly the wheel 

//while robotics arm take a wheel , named TW
void servo_1_TW(const std_msgs::Int8& data){
  if (data.data == 1){
    servo_1.attach(11);
    servo_1.write(0);
  }
  else if (data.data == 3){
    servo_1.detach();
  }
}

void servo_2_TW(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_2.attach(9);
    servo_2.write(180);

  }
  else if (data.data == 3){
    servo_2.detach();
  }
}

void servo_3_TW(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_3.attach(9);
    servo_3.write(180);

  }
  else if (data.data == 3){
    servo_3.detach();
  }
}

void servo_4_TW(const std_msgs::Int8& data){

  if (data.data == 4){
    servo_4.attach(9);
    servo_4.write(180);

  }
  else if (data.data == 3){
    servo_4.detach();
  }
}

//while robotics arm take a wheel , named RABN 
void servo_1_RABN(const std_msgs::Int8& data){
  if (data.data == 1){
    servo_1.attach(11);
    servo_1.write(0);
  }
  else if (data.data == 3){
    servo_1.detach();
  }
}

void servo_2_RABN(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_2.attach(9);
    servo_2.write(180);

  }
  else if (data.data == 3){
    servo_2.detach();
  }
}

void servo_3_RABN(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_3.attach(9);
    servo_3.write(180);

  }
  else if (data.data == 3){
    servo_3.detach();
  }
}

void servo_4_RABN(const std_msgs::Int8& data){

  if (data.data == 4){
    servo_4.attach(9);
    servo_4.write(180);

  }
  else if (data.data == 3){
    servo_4.detach();
  }
}
//while robotics arm drop and take the wheel, named DTW
void servo_1_DTW(const std_msgs::Int8& data){
  if (data.data == 1){
    servo_1.attach(11);
    servo_1.write(0);
  }
  else if (data.data == 3){
    servo_1.detach();
  }
}

void servo_2_DTW(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_2.attach(9);
    servo_2.write(180);

  }
  else if (data.data == 3){
    servo_2.detach();
  }
}

void servo_3_DTW(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_3.attach(9);
    servo_3.write(180);

  }
  else if (data.data == 3){
    servo_3.detach();
  }
}

void servo_4_DTW(const std_msgs::Int8& data){

  if (data.data == 4){
    servo_4.attach(9);
    servo_4.write(180);

  }
  else if (data.data == 3){
    servo_4.detach();
  }
}
//while robotics arm assembly the wheel  , NAMED ATW
void servo_1_ATW(const std_msgs::Int8& data){
  if (data.data == 1){
    servo_1.attach(11);
    servo_1.write(0);
  }
  else if (data.data == 3){
    servo_1.detach();
  }
}

void servo_2_ATW(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_2.attach(9);
    servo_2.write(180);

  }
  else if (data.data == 3){
    servo_2.detach();
  }
}

void servo_3_ATW(const std_msgs::Int8& data){

  if (data.data == 2){
    servo_3.attach(9);
    servo_3.write(180);

  }
  else if (data.data == 3){
    servo_3.detach();
  }
}

void servo_4_ATW(const std_msgs::Int8& data){

  if (data.data == 4){
    servo_4.attach(9);
    servo_4.write(180);

  }
  else if (data.data == 3){
    servo_4.detach();
  }
}


ros::NodeHandle nh;

std_msgs::Int16 altitude;

//subcsribe with ros servo1-4 data in TW,RABN,DTW,ATW robotic arm position

ros::Subscriber<std_msgs::Int8> servo_1_sub("servo_1TW", &servo_1_TW;
ros::Subscriber<std_msgs::Int8> servo_2_sub("servo_2TW", &servo_2_TW);
ros::Subscriber<std_msgs::Int8> servo_3_sub("servo_3TW", &servo_3_TW);
ros::Subscriber<std_msgs::Int8> servo_4_sub("servo_4TW", &servo_4_TW);

ros::Subscriber<std_msgs::Int8> servo_1_sub("servo_1RABN", &servo_1_RABN);
ros::Subscriber<std_msgs::Int8> servo_2_sub("servo_2RABN", &servo_2_RABN);
ros::Subscriber<std_msgs::Int8> servo_3_sub("servo_3RABN", &servo_3_RABN);
ros::Subscriber<std_msgs::Int8> servo_4_sub("servo_4RABN", &servo_4_RABN);

ros::Subscriber<std_msgs::Int8> servo_1_sub("servo_1DTW", &servo_1_DTW);
ros::Subscriber<std_msgs::Int8> servo_2_sub("servo_2DTW", &servo_2_DTW);
ros::Subscriber<std_msgs::Int8> servo_3_sub("servo_3DTW", &servo_3_DTW);
ros::Subscriber<std_msgs::Int8> servo_4_sub("servo_4DTW", &servo_4_DTW);

ros::Subscriber<std_msgs::Int8> servo_1_sub("servo_1DTW", &servo_1_ATW);
ros::Subscriber<std_msgs::Int8> servo_2_sub("servo_2DTW", &servo_2_ATW);
ros::Subscriber<std_msgs::Int8> servo_3_sub("servo_3DTW", &servo_3_ATW);
ros::Subscriber<std_msgs::Int8> servo_4_sub("servo_4DTW", &servo_4_ATW);

float alpha = 0.75;
const int trigPin = 2;
const int echoPin = 3;
unsigned long pulseWidth;
unsigned long distanceNow;
unsigned long distanceBefore;

//main setup for the program 
void setup()
{
  Serial.begin(57600); // Start serial communications

  pinMode(trigPin, OUTPUT); // Set pin 2 as trigger pin
  pinMode(echoPin, INPUT); // Set pin 3 as monitor pin
  digitalWrite(trigPin, LOW); // Set trigger LOW for continuous read

  nh.initNode();
  nh.subscribe(servo_1_sub);
  nh.subscribe(servo_2_sub);
  nh.subscribe(servo_3_sub);
  nh.subscribe(servo_4_sub);
}

//main program 
void loop()
{
    altitude.data = 0q;
    //pub_lidar.publish(&altitude);
    nh.spinOnce();
    delay(1); 


}
