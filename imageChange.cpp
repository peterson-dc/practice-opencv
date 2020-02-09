// Example 2-10. The same object can load videos from a camera or a file
//
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;

void help(char** argv ) {
    std::cout << "\n"
              << "\nxample 2-10. The same object can load videos from a camera or a file"
              << "\nCall:\n"
              << argv[0] <<" [path/image]\n"
              << "\nor, read from camera:\n"
              << argv[0]
              << "\nFor example:\n"
              << argv[0] << " ../tree.avi\n"
              << std::endl;
}


int main( int argc, char** argv ) {

    Mat gray_img, threshold_img;

    help(argv);

    namedWindow( "Example 2-10", cv::WINDOW_AUTOSIZE );
    namedWindow( "Example 2-11", cv::WINDOW_AUTOSIZE );

    VideoCapture cap;

    if (argc==1) {
        cap.open(0); // open the first camera
    } else {
        cap.open(argv[1]);
    }

    if( !cap.isOpened() ) { // check if we succeeded
        std::cerr << "Couldn't open capture." << std::endl;
        return -1;
    }

    Mat frame;
    Mat prevframe;
    bool isFirst = true;

    for(;;) {

        cap >> frame;

        if(isFirst)
        {
            isFirst = false;
            frame.copyTo(prevframe);
            continue;
        }

        if( frame.empty() ) break; // Ran out of film
        Mat difference = frame.clone();
        subtract(prevframe, frame, difference);

        // Convert to grayscale
        cvtColor(difference, gray_img, COLOR_BGR2GRAY);

        imshow( "Difference", difference );
        imshow( "Grayscale", gray_img);

        inRange(gray_img, 100, 255, threshold_img);

        Rect rect = boundingRect(threshold_img);
        rectangle(frame, rect, Scalar(255, 0, 0), 10);

        frame.copyTo(prevframe);
        imshow( "Original", frame );

        if( (char) cv::waitKey(33) >= 0 ) break;



    }

    destroyAllWindows();

    return 0;

}