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
        Mat first, second, third;
        Mat ch1, ch2, ch3;
        vector<Mat> channels(3);
        /* Divide a multi-channel array into several single-channel arrays */
        split(img_color, channels);
        channels[1] = 0, channels[2] = 0;
        merge(channels, first);

        namedWindow("First channel");
        imshow("First channel", first);

        split(img_color, channels);
        channels[0] = 0, channels[2] = 0;
        merge(channels, second);

        namedWindow("Second channel");
        imshow("Second channel", second);

        split(img_color, channels);
        channels[0] = 0, channels[1] = 0;
        merge(channels, third);

        namedWindow("Third channel");
        imshow("Third channel", third);
        
    }

    char key = waitKey(0);
    cout << "waitKey() value is: " << key << endl;

    return 0;
}
