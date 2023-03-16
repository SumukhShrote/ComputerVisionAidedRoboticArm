#! /usr/bin/python3

from cvzone.HandTrackingModule import HandDetector
import mediapipe as mp
import cv2 as cv
import rospy
from std_msgs.msg import Int8

def run_node():
    rospy.init_node("slow_hands")
    publisher = rospy.Publisher('/fingers', Int8, queue_size=100)
    cam = cv.VideoCapture(0)
    detector = HandDetector(maxHands=1, detectionCon = 0.7)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
            success, img = cam.read()
            hands, img = detector.findHands(img)

            if hands:
                hand = hands[0]
                fingers1 = detector.fingersUp(hand)
                if fingers1[0] == 1 and fingers1[1] ==  1:
                    fingers = 1
                if fingers1[0] == 0 and fingers1[1] ==  1:
                    fingers = 2
                if fingers1[0] == 1 and fingers1[1] ==  0:
                    fingers = 3
                if fingers1[0] == 0 and fingers1[1] ==  0:
                    fingers = 4
                f = Int8()
                f.data = fingers
                publisher.publish(f)
                rate.sleep()
            cv.imshow("image", img)
            cv.waitKey(1)
    cam.release()
    cv.destroyAllWindows()  

if __name__ == '__main__':
    try:
        run_node()
    except rospy.ROSInterruptException:
        pass
