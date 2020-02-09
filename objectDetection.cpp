// Example 2-2. Same as Example 2-1 but employing the “using namespace” directive

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

#define THRESHOLD 13
#define MAX_VALUE 15
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

void hsv_object_detection(VideoCapture capture, Mat img);

void bgr_object_detection(VideoCapture capture, Mat img, Scalar low_color, Scalar high_color);

int main( int argc, char** argv ) {

    VideoCapture capture(0);
    Mat img, hsv_img, blurred_img, blurred_img2, threshold_img;
    Mat hsv_planes[3];
    Scalar low_color = Scalar(10, 100, 180);
    Scalar high_color = Scalar(70, 120, 240);
    int top = 0, bottom = 0, left = 0, right = 0;

    if (!capture.isOpened())  // check if we succeeded
        return -1;

    while (true) {
        hsv_object_detection(capture, img);
//        bgr_object_detection(capture, img, low_color, high_color);
        waitKey(1);
    }

    return 0;
}

void hsv_object_detection(VideoCapture capture, Mat img) {
    Mat hsv_img, blurred_img, blurred_img2, threshold_img, dilated_img;
    Mat hsv_planes[3];

    capture >> img;

    if (img.empty()) return;

    // Covert the image to the HSV color scheme
    cvtColor(img, hsv_img, COLOR_BGR2HSV);

    split(hsv_img, hsv_planes);

    // Apply a blur to remove noise
//        GaussianBlur(hsv_planes[0], blurred_img, cv::Size(95, 95), 0);
    inRange(hsv_planes[0], THRESHOLD, MAX_VALUE, threshold_img);
    Mat element = getStructuringElement(1, Size(3, 3), Point(-1, -1));
    dilate(threshold_img, dilated_img, element);
    Rect rect = boundingRect(dilated_img);
    rectangle(img, rect, Scalar(255, 0, 0), 10);
//        cout << "Width: " << rect.width << endl;
//        cout << "Height: " << rect.height << endl;
    float distance = rect.width / DIST_RATIO;
//        cout << "Distance: " << distance << endl;

    namedWindow("Original Image", WINDOW_AUTOSIZE);
//        namedWindow("HSV Image", WINDOW_AUTOSIZE);
    namedWindow("Hue Column", WINDOW_AUTOSIZE);
    namedWindow("Dilated Image", WINDOW_AUTOSIZE);
    namedWindow("Threshold", WINDOW_AUTOSIZE);
//        namedWindow("Gaussian Blur", WINDOW_AUTOSIZE);


    imshow("Original Image", img);
//        imshow("HSV Image", hsv_img);
    imshow("Hue Column", hsv_planes[0]);
    imshow("Dilated Image", dilated_img);
    imshow("Threshold", threshold_img);
//        imshow("Gaussian Blur", blurred_img);
}

void bgr_object_detection(VideoCapture capture, Mat img, Scalar low_color, Scalar high_color) {
    Mat hsv_img, blurred_img, blurred_img2, threshold_img, dilated_img, eroded_img;
    capture >> img;

    if (img.empty()) return;

    // Threshold
    inRange(img, low_color, high_color, threshold_img);

    // Step before dilation
    Mat erosion_element = getStructuringElement(1, Size(3, 3), Point(-1, -1));
    Mat dilation_element = getStructuringElement(1, Size(5, 5), Point(-1, -1));
    // Erosion
    erode(threshold_img, eroded_img, erosion_element);

    // Dilation
    dilate(eroded_img, dilated_img, dilation_element);

    // Draw rectangle
    Rect rect = boundingRect(dilated_img);
    rectangle(img, rect, Scalar(255, 0, 0), 10);

    namedWindow("Original Image", WINDOW_AUTOSIZE);
    namedWindow("Dilated Image", WINDOW_AUTOSIZE);
    namedWindow("Threshold", WINDOW_AUTOSIZE);


    imshow("Original Image", img);
    imshow("Dilated Image", dilated_img);
    imshow("Threshold", threshold_img);
}
