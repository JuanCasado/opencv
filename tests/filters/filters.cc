#include <iostream>
#include <opencv2/opencv.hpp>

void on_slider (int amount,void *data);

struct IMG_FILTER {
  cv::Mat img;
  int filter = 0;
  int p1 = 1;
  int p2 = 1;
  int p3 = 1;
};

int main (int srgc, char** argv){
  IMG_FILTER filter;
  filter.img = cv::imread("../../../tests_img/cat.png");
  if (!filter.img.data){
    std::cerr << "IMG NOT LOADED ./cat.png" << std::endl;
    return 1;
  }
  cv::namedWindow("Filters");
  cv::namedWindow("Trackbars");
  cv::createTrackbar("filter", "Trackbars", &filter.filter, 3, on_slider, &filter);
  cv::createTrackbar("p1", "Trackbars", &filter.p1, 100, on_slider, &filter);
  cv::createTrackbar("p2", "Trackbars", &filter.p2, 100, on_slider, &filter);
  cv::createTrackbar("p3", "Trackbars", &filter.p3, 100, on_slider, &filter);
  on_slider(0,&filter);
  cv::waitKey(0);
  return 0;
}

void on_slider (int amount,void *data){
  IMG_FILTER *img = (IMG_FILTER*) data;
  cv::Mat filter;
  int p1 = (img->p1>0?img->p1:1);
  std::cout << "filter = " << img->filter << std::endl;
  std::cout << "p1 = " << img->p1 << std::endl;
  std::cout << "p2 = " << img->p2 << std::endl;
  std::cout << "p3 = " << img->p3 << std::endl;
  switch (img->filter){
    case 0:{
      cv::blur(img->img, filter, cv::Size(p1,p1), cv::Point(-1,-1), cv::BORDER_DEFAULT);
    }break;
    case 1:{
      p1 = (p1%2?p1:p1+1);
      cv::GaussianBlur(img->img, filter, cv::Size(p1,p1), img->p2, img->p3, cv::BORDER_DEFAULT);
    }break;
    case 2:{
      p1 = (p1%2?p1:p1+1);
      cv::medianBlur(img->img, filter, p1);
    }break;
    case 3:{
      cv::bilateralFilter(img->img, filter, p1, img->p2, img->p3, cv::BORDER_DEFAULT);
    }break;
  }
  cv::imshow("Filters", filter);
}
