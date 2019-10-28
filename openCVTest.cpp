#include<iostream>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
  VideoCapture cam; // highgui.h
  cam.open(0);

  if(cam.isOpened()) {
    cout << "Hello World,\n This is my first OpenCV program \n";
  } else {
    cout << "External camera not found. \n Going for internal camera.";
    cam.open(1);  // 2nd cam
  }
  cout << "I am in Camera...\n";

  namedWindow("Hello CV", 1);   // highgui.h
  Mat img;   // available in cv std

  while (1) {
    cam >> img;

    imshow("Hello CV", img);
    waitKey(50);
  }

  return 0;

}
