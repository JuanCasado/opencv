#include <iostream>
#include <opencv2/opencv.hpp>

void on_slider (int amount,void *data);

struct IMG_CANNY {
  cv::Mat img;
  int treshold1 = 90;
  int apertureSize = 3;
  int p1 = 8;
  bool active_precision = true;
};

/*
  treshold1 = 518
  treshold2 = 356
  apertureSize = 3
  active_precision = 1
 */

int main (int argc, char** argv){
  IMG_CANNY canny;
  if (argc == 2){
    canny.img = cv::imread(argv[1]);
  } else {
    canny.img = cv::imread("./cat.png");
  }
  if (!canny.img.data){
    std::cerr << "IMG NOT LOADED ./cat.png" << std::endl;
    return 1;
  }
  cv::namedWindow("Canny");
  cv::namedWindow("Trackbars");
  cv::createTrackbar("treshold1", "Trackbars", (int*)&canny.treshold1, 2000, on_slider, &canny);
  cv::createTrackbar("apertureSize", "Trackbars", &canny.apertureSize, 7, on_slider, &canny);
  cv::createTrackbar("active_precision", "Trackbars",(int*) &canny.active_precision, 1, on_slider, &canny);
  cv::createTrackbar("p1", "Trackbars", &canny.p1, 100, on_slider, &canny);
  on_slider(0,&canny);
  cv::waitKey(0);
  return 0;
}

void on_slider (int amount,void *data){
  IMG_CANNY *img = (IMG_CANNY*) data;
  cv::Mat tmp;
  cv::Mat canny;
  int apertureSize = (img->apertureSize%2? img->apertureSize:img->apertureSize-1);
  int p1 = (img->p1>0?img->p1:1);
  p1 = (p1%2?p1:p1+1);
  apertureSize = (apertureSize>7? 7:apertureSize);
  apertureSize = (apertureSize<3? 3:apertureSize);
  std::cout << "treshold1 = " << img->treshold1 << std::endl;
  std::cout << "apertureSize = " << apertureSize << std::endl;
  std::cout << "active_precision = " << img->active_precision << std::endl;
  std::cout << "p1 = " << p1 << std::endl;
  cv::medianBlur(img->img, tmp, p1);
  cv::Canny(tmp, canny, img->treshold1, img->treshold1, apertureSize,img->active_precision);
  cv::imshow("Canny", canny);
}