#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
  Mat imgGrayscale;
  Mat imgThresh;

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

    cvtColor(img, imgGrayscale, COLOR_BGR2GRAY);
    adaptiveThreshold(imgGrayscale,           // input image
        imgThresh,                              // output image
        255,                                    // make pixels that pass the threshold full white
        ADAPTIVE_THRESH_GAUSSIAN_C,         // use gaussian rather than mean, seems to give better results
        THRESH_BINARY_INV,                  // invert so foreground will be white, background will be black
        101,                                     // size of a pixel neighborhood used to calculate threshold value
        2);
    // imshow("Original CV", img);
    // imshow("Grayscale CV", imgGrayscale);
    imshow("Threshold CV", imgThresh);

    waitKey(50);
  }

  return 0;

}
