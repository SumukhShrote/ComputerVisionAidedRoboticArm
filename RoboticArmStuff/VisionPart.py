#! usr/bin/python3

from cvzone.HandTrackingModule import HandDetector
import mediapipe as mp
import cv2 as cv
import rospy
from custom_msg.msg import custom

def run_node():
    rospy.init_node("hands")
    publisher = rospy.Publisher('/fingers', custom, queue_size=100)
    cam = cv.VideoCapture(0)
    detector = HandDetector(maxHands=1, detectionCon = 0.7)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
            success, img = cam.read()
            hands, img = detector.findHands(img)

            if hands:
                hand = hands[0]
                fingers1 = detector.fingersUp(hand)
                f = custom()
                f.A = fingers1[0]
                f.B = fingers1[1]
                f.C = fingers1[2]
                f.D = fingers1[3]
                f.E = fingers1[4]
                publisher.publish(f)
                rate.sleep()
            cv.imshow("image", img)
            key = cv.waitKey(1)
            if key == ord("q"):
              break
    cam.release()
    cv.destroyAllWindows()  

if __name__== '__main__':
    try:
        run_node()
    except rospy.ROSInterruptException:
        pass