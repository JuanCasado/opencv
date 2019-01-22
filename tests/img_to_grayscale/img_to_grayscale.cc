#include <opencv2/opencv.hpp>
#include <iostream>
int main(int argc, char** argv) {
  if (argc != 2){
    std::cout << " No image name" << std::endl;
    return -1;
  }
  char* imageName = argv[1];
  cv::Mat image = cv::imread(imageName, cv::IMREAD_COLOR);
  if (!image.data) {
    std::cout << " No image data" << std::endl;
    return -1;
  }
  cv::Mat gray_image;
  cv::cvtColor(image, gray_image, cv::COLOR_RGB2GRAY);
  cv::imwrite("./Gray_Image.png", gray_image);
  cv::namedWindow(imageName, cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Gray image.png", cv::WINDOW_AUTOSIZE);
  cv::imshow(imageName, image);
  cv::imshow("Gray image.png", gray_image);
  cv::waitKey(0);
  return 0;
}