#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/types.hpp"
#include "opencv2/tracking.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) 
{
    double minRange, maxRange;
    int apertureSize;

    minRange = 100.0;
    maxRange = 200.0;
    apertureSize = 5;

  VideoCapture cam; // highgui.h
  cam.open(0);

  if(cam.isOpened()) 
  {
    cout << "Hello World,\n This is my first OpenCV program \n";
  } 
  else 
  {
    cout << "External camera not found. \n Going for internal camera.";
    cam.open(1);  // 2nd cam
  }

  Mat img, imgGrayscale, imgGaussian, edges, houghLines;

    while (1) 
    {
        cam >> img;
        // Converting to grayscale
        cvtColor(img, imgGrayscale, COLOR_BGR2GRAY);
        // Applying Gaussian blur
        GaussianBlur(imgGrayscale, imgGaussian, Size(5,5), 0, 0, BORDER_DEFAULT);

        // Applying Canny edge detection
        Canny(imgGaussian, edges, minRange, maxRange, apertureSize, false);
        imshow("Canny Edges", edges);

        waitKey(50);
    }

  return 0;

}
