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

int base_angle=90, gripper_angle=90, first_left_angle=90, second_angle=90, third_angle=90;

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

  base.write(90);
  gripper.write(90);
  first_left.write(90);
  first_right.write(90);
  second.write(90);
  third.write(90);


  delay(500);
}

void loop() {


  move_arm.subscribe(get_finger_data);
  if (finger_data_1 == 1)
  {
    base.write(base_angle);
    base_angle--;

  }
  else
  {
    base.write(base_angle);
    base_angle++;
  }
  if (finger_data_2 == 1)
  {
    gripper.write(gripper_angle);
    gripper_angle--;
  }
  else 
  {
    gripper.write(gripper_angle);
    gripper_angle++;
  }
  if (finger_data_3 == 1)
  {
    first_left.write(first_left_angle);
    first_right.write(first_left_angle);
    first_left_angle--;
  }
  else 
  {
    first_left.write(first_left_angle);
    first_right.write(first_left_angle);
    first_left_angle++;
  }
   if (finger_data_4 == 1)
  {
    second.write(second_angle);
    second_angle--;
  }
  else 
  {
    second.write(second_angle);
    second_angle++;
  }
   if (finger_data_5 == 1)
  {
    third.write(third_angle);
    third_angle--;
  }
  else 
  {
    third.write(third_angle);
    third_angle++;
  }
  delay(100);

  
  // base.write(0);
  // gripper.write(0);
  // first_left.write(0);
  // first_right.write(0);
  // second.write(0);
  // third.write(90);

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
  // if (finger_data_1 == 0 && finger_data_2 == 0 && finger_data_3 == 0 && finger_data_4 == 0 && finger_data_5 == 0) {
  //   for (int i=base_angle; i<90; i++) {
  //     base.write(i);
  //     delay(15);
  //   }
  //   for (int j=first_left_angle; j<90; j++) {
  //     first_left.write(i);
  //     first_right.write(i);
  //     delay(15);

  //   }
  //   for (int k=second_angle; k<90; k++) {
  //     second.write(i);
  //     delay(15);

  //   }
  //   for (int l=third_angle; l<90; l++) {
  //     third.write(i);
  //     delay(15);

  //   }
  //   for (int gay gay gay m=gripper_angle; m<90; m++) {
  //     gripper.write(i);
  //     delay(15);

  //   }
  //   base_angle = i;
  //   first_left_angle = j;
  //   second_angle = k;
  //   third_angle = l;
  //   gripper_angle = m;
    
  // }
  // else if(finger_data_1 == 1 && finger_data_2 == 0 && finger_data_3 == 0 && finger_data_4 == 0 && finger_data_5 == 0)
  // {
  //    for (int i=base_angle; i<90; i++) {
  //     base.write(i);
  //     delay(15);
  //   }
  //   for (int j=first_left_angle; j<90; j++) {
  //     first_left.write(i);
  //     first_right.write(i);
  //     delay(15);

  //   }
  //   for (int k=second_angle; k<90; k++) {
  //     second.write(i);
  //     delay(15);

  //   }
  //   for (int l=third_angle; l<90; l++) {
  //     third.write(i);
  //     delay(15);

  //   }
  //   for (int m=gripper_angle; m<90; m++) {
  //     gripper.write(i);
  //     delay(15);

  //   }
  // }


  // }
  // else if(finger_data_1 == 1 && finger_data_2 == 1 && finger_data_3 == 0 && finger_data_4 == 0 && finger_data_5 == 0)
  // {
  //    for (int i=base_angle; i<90; i++) {
  //     base.write(i);
  //     delay(15);
  //   }
  //   for (int j=first_left_angle; j<90; j++) {
  //     first_left.write(i);
  //     first_right.write(i);
  //     delay(15);

  //   }
  //   for (int k=second_angle; k<90; k++) {
  //     second.write(i);
  //     delay(15);

  //   }
  //   for (int l=third_angle; l<90; l++) {
  //     third.write(i);
  //     delay(15);

  //   }
  //   for (int m=gripper_angle; m<90; m++) {
  //     gripper.write(i);
  //     delay(15);

  //   }
  // }
  // else if(finger_data_1 == 1 && finger_data_2 == 1 && finger_data_3 == 1 && finger_data_4 == 0 && finger_data_5 == 0)
  // {
  //    for (int i=base_angle; i<90; i++) {
  //     base.write(i);
  //     delay(15);
  //   }
  //   for (int j=first_left_angle; j<90; j++) {
  //     first_left.write(i);
  //     first_right.write(i);
  //     delay(15);

  //   }
  //   for (int k=second_angle; k<90; k++) {
  //     second.write(i);
  //     delay(15);

  //   }
  //   for (int l=third_angle; l<90; l++) {
  //     third.write(i);
  //     delay(15);

  //   }
  //   for (int m=gripper_angle; m<90; m++) {
  //     gripper.write(i);
  //     delay(15);

  //   }
  // }
  // else if(finger_data_1 == 1 && finger_data_2 == 1 && finger_data_3 == 1 && finger_data_4 == 1 && finger_data_5 == 0)
  // {
  //    for (int i=base_angle; i<90; i++) {
  //     base.write(i);
  //     delay(15);
  //   }
  //   for (int j=first_left_angle; j<90; j++) {
  //     first_left.write(i);
  //     first_right.write(i);
  //     delay(15);

  //   }
  //   for (int k=second_angle; k<90; k++) {
  //     second.write(i);
  //     delay(15);

  //   }
  //   for (int l=third_angle; l<90; l++) {
  //     third.write(i);
  //     delay(15);

  //   }
  //   for (int m=gripper_angle; m<90; m++) {
  //     gripper.write(i);
  //     delay(15);

  //   }
  // }
  // else if(finger_data_1 == 1 && finger_data_2 == 1 && finger_data_3 == 1 && finger_data_4 == 1 && finger_data_5 == 1)
  // {
  //    for (int i=base_angle; i<90; i++) {
  //     base.write(i);
  //     delay(15);
  //   }
  //   for (int j=first_left_angle; j<90; j++) {
  //     first_left.write(i);
  //     first_right.write(i);
  //     delay(15);

  //   }
  //   for (int k=second_angle; k<90; k++) {
  //     second.write(i);
  //     delay(15);

  //   }
  //   for (int l=third_angle; l<90; l++) {
  //     third.write(i);
  //     delay(15);

  //   }
  //   for (int m=gripper_angle; m<90; m++) {
  //     gripper.write(i);
  //     delay(15);

  //   }
  //}
  // else {
  //   base.write(0);
  //   first_left.write(0);
  //   first_right.write(0);
  //   second.write(0);
  //   third.write(0);
  //   gripper.write(0);
  // }
  
  move_arm.spinOnce();
  delay(500);
}
