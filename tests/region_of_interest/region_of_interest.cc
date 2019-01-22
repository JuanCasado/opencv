#include <iostream>
#include <opencv2/opencv.hpp>

int main (int argc, char** argv){
  cv::Mat img = cv::imread("./cat.png", cv::IMREAD_COLOR);
  if (!img.data){
    std::cout << "ERROR LOADING ./cat.png" << std::endl;
    return 1;
  }
  cv::Mat region_of_interest_1 (img, cv::Rect (0, 0, 300, 300));
  cv::Mat region_of_interest_2 = img(cv::Range(300,600), cv::Range(300,600));
  
  cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("region_of_interest_1", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("region_of_interest_2", cv::WINDOW_AUTOSIZE);
  cv::imshow("region_of_interest_1", region_of_interest_1);
  cv::imshow("region_of_interest_2", region_of_interest_2);
  cv::imshow("original", img);

  cv::waitKey(0);

  return 0;
}