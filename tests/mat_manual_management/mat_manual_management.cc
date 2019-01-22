#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main (int argc, char ** argv){
  cv::Mat img = cv::imread("./cat.png", cv::IMREAD_COLOR);
  if (!img.data){
    std::cout << "ERROR LOADING ./cat.png" << std::endl;
    return 1;
  }
  cv::Mat portion = img(cv::Range(300, 305), cv::Range(300,305));
  std::cout << "CAT IMG" << std::endl;
  std::cout << portion << std::endl;

  std::cout << "2x2" << std::endl;
  cv::Mat _2x2 (2,2, CV_8UC3, cv::Scalar(0, 150, 255));
  std::cout << _2x2 << std::endl;

  std::cout << "from arr" << std::endl;
  int arr[3] = {6,6,6};
  cv::Mat from_arr (2,                    //MATRIX DIMENSIONS 1(NORMAL MATRIX) or 2(RGB)
                    arr,                  //VERTICAL SIZE
                    CV_8UC(2),            //HORIZONAL SIZE
                    cv::Scalar::all(5));  //MATRIX FILLED WITH
  std::cout << from_arr << std::endl;

  std::cout << "zeros" << std::endl;
  cv::Mat zeros = cv::Mat::zeros(3,3, CV_8UC1);
  std::cout << zeros << std::endl;

  std::cout << "ones" << std::endl;
  cv::Mat ones = cv::Mat::ones(3,3, CV_32F);
  std::cout << ones << std::endl;

  std::cout << "eye" << std::endl;
  cv::Mat eye = cv::Mat::eye(3,3, CV_64F);
  std::cout << eye << std::endl;

  std::cout << "list" << std::endl;
  cv::Mat list = (cv::Mat_<double> (4,3)<<1,2,3,4,5,6,7,8,9,10,11,12);
  std::cout << list << std::endl;

  std::cout << "reshape" << std::endl;
  std::cout << list.reshape(2) << std::endl;

  std::cout << "randu" << std::endl;
  cv::Mat randu = cv::Mat(3, 3, CV_8UC1);
  cv::randu (randu, cv::Scalar::all(0), cv::Scalar::all(255));
  std::cout << randu << std::endl;

  std::cout << "randu_PY" << std::endl; //GOOD ONE
  std::cout << cv::format(randu, cv::Formatter::FMT_PYTHON) << std::endl;
  std::cout << "randu_CSV" << std::endl;
  std::cout << cv::format(randu, cv::Formatter::FMT_CSV) << std::endl;
  std::cout << "randu_NUMPY" << std::endl; //GOOD ONE
  std::cout << cv::format(randu, cv::Formatter::FMT_NUMPY) << std::endl;
  std::cout << "randu_C" << std::endl;
  std::cout << cv::format(randu, cv::Formatter::FMT_C) << std::endl;

  std::cout << "point2f" << std::endl;
  cv::Point2f point2f(5,6);
  std::cout << point2f << std::endl;

  std::cout << "point3f" << std::endl;
  cv::Point3f point3f(5,6, 99);
  std::cout << point3f << std::endl;


  std::cout << "vector" << std::endl;
  std::vector<float> v;
  v.emplace_back((float)CV_PI);
  v.emplace_back(3);
  v.emplace_back(4);
  cv::Mat vector (v);
  std::cout << vector << std::endl;



  return 0;
}