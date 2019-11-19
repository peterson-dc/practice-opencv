#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
  Mat img;
  Mat imgGrayscale;
  Mat imgBlurred;
  Mat imgThresh1;
  Mat imgThresh2;
  Mat imgThresh3;
  img = imread("../ExampleImg.jpg", 1);

  
  cvtColor(img, imgGrayscale, COLOR_BGR2GRAY);

  // GaussianBlur(imgGrayscale,              // input image
  //       imgBlurred,                             // output image
  //       cv::Size(1, 1),                         // smoothing window width and height in pixels
  //       0);      
                                       // sigma value, determines how much the image will be blurred, zero makes function choose the sigma value
  adaptiveThreshold(imgGrayscale,           // input image
    imgThresh1,                              // output image
    255,                                    // make pixels that pass the threshold full white
    ADAPTIVE_THRESH_GAUSSIAN_C,         // use gaussian rather than mean, seems to give better results
    THRESH_BINARY_INV,                  // invert so foreground will be white, background will be black
    7,                                     // size of a pixel neighborhood used to calculate threshold value
    10);

    adaptiveThreshold(imgGrayscale,           // input image
    imgThresh2,                              // output image
    255,                                    // make pixels that pass the threshold full white
    ADAPTIVE_THRESH_GAUSSIAN_C,         // use gaussian rather than mean, seems to give better results
    THRESH_BINARY_INV,                  // invert so foreground will be white, background will be black
    9,                                     // size of a pixel neighborhood used to calculate threshold value
    10);

    adaptiveThreshold(imgGrayscale,           // input image
    imgThresh3,                              // output image
    255,                                   // make pixels that pass the threshold full white
    ADAPTIVE_THRESH_GAUSSIAN_C,         // use gaussian rather than mean, seems to give better results
    THRESH_BINARY_INV,                  // invert so foreground will be white, background will be black
    11,                                     // size of a pixel neighborhood used to calculate threshold value
    10);

  vector<vector<Point> > contours1;
  vector<vector<Point> > contours2;
  vector<vector<Point> > contours3;
  vector<Vec4i> hierarchy1;
  vector<Vec4i> hierarchy2;
  vector<Vec4i> hierarchy3;

    findContours( imgThresh1, contours1, hierarchy1,
        RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );

        findContours( imgThresh2, contours2, hierarchy2,
        RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );

        findContours( imgThresh3, contours3, hierarchy3,
        RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );

Mat dst1 = Mat::zeros(imgThresh1.rows, imgThresh1.cols, CV_8UC3);

Mat dst2 = Mat::zeros(imgThresh2.rows, imgThresh2.cols, CV_8UC3);

Mat dst3 = Mat::zeros(imgThresh3.rows, imgThresh3.cols, CV_8UC3);

    // iterate through all the top-level contours,
    // draw each connected component with its own random color
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    for( ; idx1 >= 0; idx1 = hierarchy1[idx1][0] )
    {
        Scalar color( 255, 255, 255 );
        drawContours( dst1, contours1, idx1, color, LINE_4, 8, hierarchy1 );
    }

    for( ; idx2 >= 0; idx2 = hierarchy2[idx2][0] )
    {
        Scalar color( rand()&255, rand()&255, rand()&255 );
        drawContours( dst2, contours2, idx2, color, LINE_4, 8, hierarchy2 );
    }

    for( ; idx3 >= 0; idx3 = hierarchy3[idx3][0] )
    {
        Scalar color( rand()&255, rand()&255, rand()&255 );
        drawContours( dst3, contours3, idx3, color, LINE_4, 8, hierarchy3 );
    }

  while (1) {
    imshow("Image1", dst1);
    imshow("Image2", dst2);
    imshow("Image3", dst3);

    waitKey(50);
  }
 
  return 0;

}