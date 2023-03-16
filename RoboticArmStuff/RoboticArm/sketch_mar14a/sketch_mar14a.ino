#include <ros.h>
#include <std_msgs/Int8.h>
#include <custom_msg/custom.h>
#include <Wire.h>
#include <Servo.h>

#define no_of_servos 5

int finger_data;

Servo base;
Servo gripper;
Servo first_left;
Servo first_right;
Servo second;
Servo third;

int finger_data_1;
int finger_data_2;
int finger_data_3;
int finger_data_4;
int finger_data_5;

void get_value(const custom_msg::custom& fingers) {
  finger_data_1 = fingers.A;
  finger_data_2 = fingers.B;
  finger_data_3 = fingers.C;
  finger_data_4 = fingers.D;
  finger_data_5 = fingers.E;
}

ros::NodeHandle move_arm;
ros::Subscriber<custom_msg::custom> get_finger_data("/fingers", &get_value);

void setup() {
  // put your setup code here, to run once:
  base.attach(8);
  gripper.attach(9);
  first_left.attach(10);
  first_right.attach(11);
  second.attach(12);
  third.attach(13);

  move_arm.initNode();

  base.write(0);
  gripper.write(0);
  first_left.write(0);
  first_right.write(0);
  second.write(0);
  third.write(0);


  delay(500);
}

void loop() {


  move_arm.subscribe(get_finger_data);

  base.write(0);
  gripper.write(0);
  first_left.write(0);
  first_right.write(0);
  second.write(0);
  third.write(90);

  //if (finger_data_1 == 1) {
//    base.write(90);
//  }
//  if (finger_data_2 == 1) {
//    first_left.write(90);
//    first_right.write(90);
//  }
//  if (finger_data_3 == 1) {
//    second.write(90);
//  }
//  if (finger_data_4 == 1) {
//    third.write(90);
//  }
//  if (finger_data_5 == 1) {
//    gripper.write(90);
//  }
  if (finger_data_1 == 0 && finger_data_2 == 0 && finger_data_3 == 0 && finger_data_4 == 0 && finger_data_5 == 0) {
    base.write(90);
    first_left.write(90);
    first_right.write(90);
    second.write(90);
    third.write(90);
    gripper.write(90);
  }
  else {
    base.write(0);
    first_left.write(0);
    first_right.write(0);
    second.write(0);
    third.write(0);
    gripper.write(0);
  }

  move_arm.spinOnce();
  delay(500);





}
