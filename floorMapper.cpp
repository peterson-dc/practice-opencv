#include <iostream>
#include <sstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    //create Background Subtractor objects
    Ptr<BackgroundSubtractor> pBackSub;
    pBackSub = createBackgroundSubtractorMOG2();

    VideoCapture capture( samples::findFile("/Users/davis/GitHub/practice-opencv/ThirdFloorHartung.mov"));
    if (!capture.isOpened()){
        //error in opening the video input
        cerr << "Unable to open: " << "ThirdFloorHartung" << endl;
        return 0;
    }
    Mat frame, flippedFrame, hsvFrame, hlsFrame, threshFrame, fgMask1, fgMask2;
    while (true) {
        capture >> frame;
        if (frame.empty())
            break;
        flip(frame, flippedFrame, 0);
        // cvtColor(flippedFrame, hsvFrame, COLOR_BGR2HSV);
        cvtColor(flippedFrame, hlsFrame, COLOR_BGR2HLS);
        //update the background model
        // pBackSub->apply(hsvFrame, fgMask1);
        // pBackSub->apply(hlsFrame, fgMask2);
        adaptiveThreshold(hlsFrame, threshFrame, 
            100, 
            ADAPTIVE_THRESH_GAUSSIAN_C,
            THRESH_BINARY_INV,
            7,
            10);
        //get the frame number and write it on the current frame
        rectangle(hlsFrame, cv::Point(10, 2), cv::Point(100,20),
                  cv::Scalar(255,255,255), -1);
        stringstream ss;
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(hlsFrame, frameNumberString.c_str(), cv::Point(15, 15),
                FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(0,0,0));
        //show the current frame and the fg masks
        // imshow("HSV Frame", hsvFrame);
        imshow("HLS Frame", hlsFrame);
        // imshow("FG Mask1", fgMask1);
        imshow("Thresh", threshFrame);
        //get the input from the keyboard
        int keyboard = waitKey(30);
        if (keyboard == 'q' || keyboard == 27)
            break;
    }
    return 0;
}