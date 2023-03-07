// OpenImg.cpp
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>

using namespace cv;

int main(int argc, char** argv)
{
Mat img = imread(argv[1]);
if (img.empty())
{
exit(1);
}
namedWindow("Example 1");
imshow("Example 1", img);
waitKey(0);
return 0;
}
