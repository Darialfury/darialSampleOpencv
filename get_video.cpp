#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 int main() {
// Create a VideoCapture object and open the default camera (device index 0)
// Use 1, 2, etc. for additional cameras.
//cv::VideoCapture cap(0);
// 192.168.101.78 
cv::VideoCapture cap("rstp://")
  // Check if the camera opened successfully.
if (!cap.isOpened()) {
std::cerr << "ERROR! Unable to open camera\n";
return -1;
}
  std::cout << "Start grabbing frames from camera" << std::endl;
std::cout << "Press any key to terminate" << std::endl;
  // Loop continuously to read frames.
for (;;) {
cv::Mat frame;
	cv::Mat frameGray;
// Wait for a new frame from the camera and store it into 'frame'.
cap.read(frame);
   // Check if the frame is empty (e.g., end of stream).
if (frame.empty()) {
std::cerr << "ERROR! blank frame grabbed\n";
break;
}
	cv::cvtColor(frame, frameGray, cv::COLOR_BGR2GRAY);
// Display the captured frame in a window named "Live".
cv::imshow("Live", frame);
	cv::imshow("Gray", frameGray);
  // Wait for 5ms for a key press. If a key is pressed, break the loop.
if (cv::waitKey(5) >= 0) {
break;
}
}
}// The VideoCapture object is automatically deinitialized in its destructor.
return 0;
