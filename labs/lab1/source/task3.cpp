#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    /* Safety check on argc */
    if (argc < 2)
    {
        fprintf(stderr, "usage: <image filename>\n");
        exit(EXIT_FAILURE);
    }
    /* Reading images */
    string filename = argv[1];
    string image_path = "../images/" + filename;

    Mat img_color = imread(image_path, IMREAD_COLOR);
    /* Safety check on the image returned by cv::imread() */
    if (img_color.empty())
    {
        cout << "could not read the image" << endl;
        exit(EXIT_FAILURE);
    }
    namedWindow("Colored image");
    imshow("Colored image", img_color);
    
    int channels_number = img_color.channels();
    cout << "The number of channels of image " << filename << " is: " << channels_number << endl;
    if (channels_number == 3)
    {
        Mat dst;
        Mat ch1, ch2, ch3;
        vector<Mat> channels(3);
        /* Divide a multi-channel array into several single-channel arrays */
        split(img_color, channels);
        ch1 = channels[0];
        ch2 = channels[1];
        ch3 = channels[2];
        /* Set the first channel to 0 and merge them back */
        channels[0] = 0;
        merge(channels, dst);
        namedWindow("First channel equal to 0 image");
        imshow("First channel equal to 0 image", dst);
    }

    char key = waitKey(0);
    cout << "waitKey() value is: " << key << endl;

    return 0;
}
