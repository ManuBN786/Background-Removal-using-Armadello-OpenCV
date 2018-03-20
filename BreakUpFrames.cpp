
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    // capture from web camera init

    VideoCapture cap("/home/user/Downloads/foreground_detection_code/768x576.avi");
    //cap.open(0);

    Mat img;

    // Initialize the inbuilt Harr Cascade frontal face detection
    // Below mention the path of where your haarcascade_frontalface_alt2.xml file is located

    CascadeClassifier face_cascade;
    face_cascade.load(  "../DataFiles/haarcascade_frontalface_alt2.xml" );


    int i =0;

    for (;;)
    {

        // Image from camera to Mat

        cap >> img;

        // obtain input image from source
        cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);

        // Just resize input image if you want
       // resize(img, img, Size(1000,640));

        std::stringstream name1;

        name1 << "/home/user/Downloads/foreground_detection_code/seq/" <<"Frame_"<< i << ".jpg";
        bool maybe1 = imwrite(name1.str(),img);

        i++;

        imshow("wooohooo", img);
        int key2 = waitKey(1);

    }
    return 0;
}
