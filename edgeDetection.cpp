#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/types.hpp"
#include "opencv2/tracking.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    Mat img, imgGrayscale, imgGaussian, edges;

    cout<<"Reading image" << endl;
    img = imread("../Hallway2.png", 1);

    cout<<"Converting to grayscale" << endl;
    cvtColor(img, imgGrayscale, COLOR_BGR2GRAY);
    cout<<"Applying Gaussian blur" << endl;
    GaussianBlur(imgGrayscale, imgGaussian, Size(5,5), 0, 0, BORDER_DEFAULT);

    Rect2d rectangle = selectROI(imgGaussian);
    Mat croppedImg = imgGaussian(rectangle);
    Canny(croppedImg, edges, 100, 200, 5, false);

    cout<<"Showing processed image" << endl;
    while(true) {
        imshow("Cropped", croppedImg);
        // imshow("Grayscale", imgGrayscale);
        // imshow("Gaussian", imgGaussian);
        imshow("Canny", edges);
        waitKey(50);
    }


    // 316, 2107
    // 1756, 1375
    // 1832, 1375
    // 790, 2107
    return 0;
}