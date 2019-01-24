#include <opencv2/opencv.hpp>
#include <iostream>

int main (int argc, char **argv){
  cv::Mat input;
  if (argc == 2){
    input = cv::imread(argv[1]);
  } else {
    input = cv::imread("../../../tests_img/cat.png");
  }
  if (!input.data){
    std::cout << "IMAGE NOT LOADED" << std::endl;
    return 0;
  }
  cv::Mat gray;
  cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);

  cv::Ptr<cv::LineSegmentDetector> det = cv::createLineSegmentDetector();

  cv::Mat lines;
  det->detect(gray, lines);
  det->drawSegments(input, lines);
  cv::imshow("lines_grey", input);
  
  cv::waitKey(0);
  return 0;
}