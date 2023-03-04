#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>

#include <iostream>

using namespace cv;

int main(int argc, char** argv)
{
    /* Safety check on argc */
    if (argc < 2)
    {
        fprintf(stderr, "usage: <image filename>\n");
        exit(EXIT_FAILURE);
    }
    /* Reading images */
    std::string filename = argv[1];
    std::string imgs_path = samples::findFile(filename);

    Mat img_grayscale = imread(imgs_path, IMREAD_GRAYSCALE);
    /* Safety check on the image returned by cv::imread() */
    if (img_grayscale.empty())
    {
        fprintf(stderr, "could not read the image %s\n", imgs_path);
        exit(EXIT_FAILURE);
    }
    namedWindow("Grayscale image");
    imshow("Grayscale image", img_grayscale);

    Mat img_color = imread(imgs_path, IMREAD_COLOR);
    /* Safety check on the image returned by cv::imread() */
    if (img_color.empty())
    {
        fprintf(stderr, "could not read the image %s\n", imgs_path);
        exit(EXIT_FAILURE);
    }
    namedWindow("Colored image");
    imshow("Colored image", img_color);

    waitKey(0);

    return 0;
}