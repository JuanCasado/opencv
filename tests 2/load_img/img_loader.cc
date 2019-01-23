#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
using namespace cv;
using namespace std;
int main(int argc, char** argv) {
  String imageName;  // by default
  if (argc > 1) {
    imageName = argv[1];
  } else {
    imageName = "../../../tests_img/img.jpg";
  }
  Mat image = imread(imageName, IMREAD_COLOR);
  if (image.empty()) {
    cout << "Could not open or find the image" << std::endl;
    return -1;
  }
  namedWindow("Display window", WINDOW_AUTOSIZE);
  imshow("Display window", image);
  waitKey(0);
  return 0;
}
