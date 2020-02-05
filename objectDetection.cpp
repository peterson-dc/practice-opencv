// Example 2-2. Same as Example 2-1 but employing the “using namespace” directive

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

#define THRESHOLD 100
#define MAX_VALUE 255
#define DIST_RATIO 1726

using namespace std;
using namespace cv;

void help(char** argv ) {
    std::cout << "\n"
              << "2.2: Like 2.1, but 'using namespace cv: \n"
              << argv[0] <<" <path/image>\n"
              << "For example:\n"
              << argv[0] << " ../fruits.jpg\n"
              << std::endl;
}


int main( int argc, char** argv ) {

    Mat img, hsv_img, blurred_img, blurred_img2, threshold_img;
    Mat hsv_planes[3];
    int top = 0, bottom = 0, left = 0, right = 0;

    if (argc != 2) {
        help(argv);
        return 0;
    }

    img = imread( argv[1], -1 );

    if( img.empty() ) return -1;

    // Covert the image to the HSV color scheme
    cvtColor(img, hsv_img, COLOR_BGR2HSV);

    split(hsv_img, hsv_planes);

    // Apply a blur to remove noise
    GaussianBlur( hsv_planes[0], blurred_img, cv::Size(95,95), 0);
    inRange(blurred_img, THRESHOLD, MAX_VALUE, threshold_img);
    Rect rect = boundingRect(threshold_img);
    rectangle(img, rect, Scalar( 255, 0, 0 ), 10);
    cout << "Width: " << rect.width << endl;
    cout << "Height: " << rect.height << endl;
    float distance = rect.width / DIST_RATIO;
    cout << "Distance: " << distance << endl;

    namedWindow( "Original Image", WINDOW_AUTOSIZE );
    namedWindow("HSV Image", WINDOW_AUTOSIZE);
    namedWindow("Hue Column", WINDOW_AUTOSIZE);
    namedWindow("Threshold", WINDOW_AUTOSIZE);
    namedWindow("Gaussian Blur", WINDOW_AUTOSIZE);



    imshow( "Original Image", img );
    imshow("HSV Image", hsv_img);
    imshow("Hue Column", hsv_planes[0]);
    imshow("Threshold", threshold_img);
    imshow("Gaussian Blur", blurred_img );

    waitKey( 0 );

    destroyWindow( "Original Image" );
    destroyWindow("HSV Image" );
    destroyWindow("Hue Column");
    destroyWindow("Threshold" );
    destroyWindow("Gaussian Blur" );
}
