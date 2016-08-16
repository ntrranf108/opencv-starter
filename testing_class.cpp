#include <iostream>
#include <cv.h>   // headers
#include <highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio/videoio.hpp>

using namespace cv;
using namespace std;

int main(  int argc, char** argv ) {
	int frameCount;
	Mat frame;
//	Mat grayFrame;
//	Mat edges;
//	Mat blurGrayFrame;
//
//	int motion = 0;

	//open video - change the videoFileName
//	char videoFileName[50] = ("testingVideo.MOV");
//op	VideoCapture cap(videoFileName);

	//open default camera
	VideoCapture cap(0);

	if(!cap.isOpened()){return -1;}
	cap >> frame;

	namedWindow("Original",CV_WINDOW_AUTOSIZE);
	int key;

	bool rectOn;
	rectOn = false;

	bool cirOn;
	cirOn = false;

	for (; ; frameCount++){
		cap >> frame;

		key = waitKey(10);

		//draw a rectangle if press 'r'
		if (key == 'r'){
			cout <<"Draw a rectangle" <<endl;
			rectOn = !rectOn;
		}
		if (rectOn) {
			int mixBlue = rand()%256;
			int mixGreen = rand()%256;
			int mixRed = rand()%256;

			rectangle(frame,Rect(100,100,50,50),Scalar(mixBlue, mixGreen, mixRed),5,8,0);
			cout <<"red = " <<mixBlue <<endl;
			cout <<"green = " <<mixGreen <<endl;
			cout <<"blue = " <<mixRed << endl;
		}

		//draw a circle if press 'c'
		if (key == 'c') {
			cout <<"Draw a circle" <<endl;
			cirOn = !cirOn;
		}
		if (cirOn) {
			circle(frame,Point(200,200),100,Scalar(0,0,255),5,8,0);
		}

		//quit the program if press 'q'
		if (key == 'q') {break;}
		imshow("Original", frame);
	}
	cout <<"The pressed key is: %c" <<key  <<endl;

	//print number
    float g = 9.767895;
	printf ("red = %6.3f, char = %c \n", g, key);



    return 0;

}
