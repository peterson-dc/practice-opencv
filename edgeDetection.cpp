#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/types.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    Mat img, imgGrayscale, imgGaussian;

    cout<<"Reading image" << endl;
    img = imread("../Hallway2.png", 1);

    cout<<"Converting to grayscale" << endl;
    cvtColor(img, imgGrayscale, COLOR_BGR2GRAY);
    cout<<"Applying Gaussian blur" << endl;
    GaussianBlur(imgGrayscale, imgGaussian, Size(5,5), 0, 0, BORDER_DEFAULT);

    cout<<"Showing processed image" << endl;
    while(true) {
        imshow("Grayscale", imgGrayscale);
        imshow("Gaussian", imgGaussian);
        waitKey(50);
    }

    return 0;
}