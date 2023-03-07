#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

Mat horizontalGradient(int dim)
{
    Mat image(dim, dim, CV_8UC1);

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            image.at<unsigned char>(i,j) = min(j, 255);
        }
    }

    return image;
}

Mat verticalGradient(int dim)
{
    Mat image(dim, dim, CV_8UC1);

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            image.at<unsigned char>(i,j) = min(i, 255);
        }
    }

    return image;
}

Mat chessboard(int dim, int square)
{
    Mat image(dim, dim, CV_8UC1);

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            if (((i / square) % 2 == 0 && (j / square) % 2 == 0)
                || (((i / square) % 2 == 1 && (j / square) % 2 == 1)))
            {
                image.at<unsigned char>(i,j) = 255;
            }
            else
            {
                image.at<unsigned char>(i,j) = 0;
            }
        }
    }

    return image;
}


int main(int argc, char** argv)
{
    Mat image1 = horizontalGradient(256);
    namedWindow("Horizontal Gradient");
    imshow ("Horizontal Gradient", image1);
    Mat image2 = verticalGradient(256);
    namedWindow("Vertical Gradient");
    imshow ("Vertical Gradient", image2);

    Mat chess20 = chessboard(300, 20);
    namedWindow("Chessboard with square of 20 pixels");
    imshow ("Chessboard with square of 20 pixels", chess20);
    Mat chess50 = chessboard(300, 50);
    namedWindow("Chessboard with square of 50 pixels");
    imshow ("Chessboard with square of 50 pixels", chess50);

    waitKey(0);

    return 0;
}
