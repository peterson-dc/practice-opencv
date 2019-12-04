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

int main() 
{
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

  Mat img, imgGrayscale, imgGaussian, edges;

    while (1) 
    {
        cam >> img;

        cvtColor(img, imgGrayscale, COLOR_BGR2GRAY);
        GaussianBlur(imgGrayscale, imgGaussian, Size(5,5), 0, 0, BORDER_DEFAULT);

        // Rect2d rectangle = selectROI(imgGaussian);
        // Mat croppedImg = imgGaussian(rectangle);
        Canny(imgGaussian, edges, 100, 200, 5, false);
        imshow("Canny", edges);

        waitKey(50);
    }

  return 0;

}
