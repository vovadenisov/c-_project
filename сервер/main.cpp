#include <stdlib.h>

#include "Server.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

int SCALE = 4;
int WIDTH = 640 / SCALE;
int HEIGHT = 480 / SCALE;

void parse_video(uint8_t* data, int read, Mat& frame);

int main(int argc, char* argv[])
{
	
	Server server(53000);
	if(server.open() == 1)
		cout << "TCP server opened!\n";
	else{
		cout << "TCP server connection failed!\n";
	}
	
	Mat frame(HEIGHT, WIDTH, CV_8UC3);
	namedWindow("server",1);
	cv::imshow( "server", frame );

	bool end_program = false;
	while(!end_program)
	{		
		
		char data[BYTES2READ + 1];
		int read = server.readData(data);			
		if(read > 0)
		{
			//cout << "\033[32m" << data << "\033[0m" << endl;
			parse_video((uint8_t*)data, read, frame);
			//cv::imshow( "server", frame );
			//cout << "//parse commands\n";	
		}
		
		if(read < 0)
		{
			cout << "Trying reconnection...\n";
			if(rand() % 1000000 == 0)
				server.open();
		}
		
		if(rand() % 50 == 0)
		{
			char send[35];
			sprintf(send, "I'm Minion's Server!%d", rand() % 100);
			cout << send << endl;
			server.writeData(server.numsocks-1, send);
		}

		switch(cv::waitKey(30))
		{
		case 27://'Esc'
			{
				cout << "esc key is pressed by user" << endl;
				end_program = true;
			}; break;
			default: 
			{
				//if(95 < rand() % 100)
					//server.writeData("I'm Minion's Server!");
			};break;
		}
	}
	
	//cv::imshow( "server", frame );

	cv::waitKey(0);
	return 0;
}

void parse_video(uint8_t* data, int read, Mat& frame)
{
	/*static long int recieved = 0;
	if(read > 2)
		for(int i = 0; i < read - 2; i += 3)
		{
			if( data[i] == 255 && data[i+1] == 0 && data[i+2] == 0)
			{
				cout << "\033[32m" << "new frame" << "\033[0m" << endl;
				recieved = 0;
				break;
			}
		}
	printf("recv: %d; read: %d\n", recieved, read);
	if(recieved + read > WIDTH * HEIGHT * 3)
		recieved = 0;	
	Mat img(HEIGHT, WIDTH, CV_8UC3);
	memcpy( (uint8_t*)(img.data + recieved), data, read);
	recieved += read;
	Mat bigImg(SCALE*HEIGHT, SCALE*WIDTH, CV_8UC3);
	resize(img, bigImg, bigImg.size(), 0, 0, INTER_LINEAR);*/
	
	//cout << "recieved: " << read << endl;
	Mat bigImg = imdecode(Mat(480, 640, CV_8UC3, data),CV_LOAD_IMAGE_COLOR);
	if(bigImg.cols == 0 || bigImg.rows == 0)
		cout << "cannot convert jpeg\n";
	else
		cv::imshow( "server", bigImg );
}
