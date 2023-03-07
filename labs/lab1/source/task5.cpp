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

    Mat img_grayscale = imread(image_path, IMREAD_GRAYSCALE);
    /* Safety check on the image returned by cv::imread() */
    if (img_grayscale.empty())
    {
        cout << "could not read the image" << endl;
        exit(EXIT_FAILURE);
    }
    namedWindow("Grayscale image");
    imshow("Grayscale image", img_grayscale);

    Mat img_color = imread(image_path, IMREAD_COLOR);
    /* Safety check on the image returned by cv::imread() */
    if (img_color.empty())
    {
        cout << "could not read the image" << endl;
        exit(EXIT_FAILURE);
    }
    namedWindow("Colored image");
    imshow("Colored image", img_color);

    waitKey(0);

    return 0;
}
