#include <ros.h>
#include <std_msgs/Int8.h>
#include <Wire.h>
#include <Servo.h>


#define upper_limit 2000
#define lower_limit 1540
#define stop_sign 1500
#define no_of_servos 5

int finger_data;

Servo base;
Servo hand; 


int bottom_right, bottom_left, top_right, top_left;

void pub_rpm(std_msgs::Int8& fingers) {
  finger_data = fingers.data;
}

ros::NodeHandle move_arm;
ros::Subscriber<std_msgs::Int8> rpm_sub("/fingers", &pub_rpm);

void setup() {
  // put your setup code here, to run once:
  base.attach(13);
  hand.attach(9);  

  move_arm.initNode();
  
  base.write(90);
  hand.write(0);


  delay(5000);
}

void loop() {
  
  
  move_arm.subscribe(rpm_sub);
  
  base.write(90);
  hand.write(0);
  if (finger_data == 1) {
    base.write(90);
    hand.write(90);
  }
  else if (finger_data == 2) {
    base.write(0);
    hand.write(90);
  }
  else if (finger_data == 3) {
    base.write(90);
    hand.write(0);
  }
  else {
    base.write(90);
    hand.write(0);
  }

  move_arm.spinOnce();
  delay(5000);
  
  



}
