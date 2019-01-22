#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat& ScanImageAndReduceC(cv::Mat& I, const uchar* const table);
cv::Mat& ScanImageAndReduceIterator(cv::Mat& I, const uchar* const table);
cv::Mat& ScanImageAndReduceRandomAccess(cv::Mat& I, const uchar* const table);

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "NEED A NUMBER" << std::endl;
    return 0;
  }

  double t;
  int divideWith = std::atoi(argv[1]);

  uchar table [256];
  for (auto &i : table){
    i = divideWith*(i/divideWith);
  }
  cv::Mat lookUpTable(1, 256, CV_8U);
  uchar* p = lookUpTable.ptr();
  for (int i = 0; i < 256; ++i){
    p[i] = table[i];
  }

  cv::Mat I = cv::imread("../../../tests_img/cat.png");
  cv::Mat I1 = I.clone();
  cv::Mat I2 = I.clone();
  cv::Mat I3 = I.clone();
  cv::Mat J;

  t = (double)cv::getTickCount();
  LUT(I, lookUpTable, J);
  std::cout << "Times passed in seconds: " << ((double)cv::getTickCount() - t)/cv::getTickFrequency() << std::endl;
  cv::namedWindow("LUT");
  cv::imshow("LUT", J);

  t = (double)cv::getTickCount();
  J = ScanImageAndReduceC(I1, table);
  std::cout << "Times passed in seconds: " << ((double)cv::getTickCount() - t)/cv::getTickFrequency() << std::endl;
  cv::namedWindow("ScanImageAndReduceC");
  cv::imshow("ScanImageAndReduceC", J);

  t = (double)cv::getTickCount();
  J = ScanImageAndReduceIterator(I2, table);
  std::cout << "Times passed in seconds: " << ((double)cv::getTickCount() - t)/cv::getTickFrequency() << std::endl;
  cv::namedWindow("ScanImageAndReduceIterator");
  cv::imshow("ScanImageAndReduceIterator", J);

  t = (double)cv::getTickCount();
  J = ScanImageAndReduceRandomAccess(I3, table);
  std::cout << "Times passed in seconds: " << ((double)cv::getTickCount() - t)/cv::getTickFrequency() << std::endl;
  cv::namedWindow("ScanImageAndReduceRandomAccess");
  cv::imshow("ScanImageAndReduceRandomAccess", J);

  cv::waitKey(0);
}

cv::Mat& ScanImageAndReduceC(cv::Mat& I, const uchar* const table) {
  CV_Assert(I.depth() == CV_8U);
  int channels = I.channels();
  int nRows = I.rows;
  int nCols = I.cols * channels;
  if (I.isContinuous()) {
    nCols *= nRows;
    nRows = 1;
  }
  int i, j;
  uchar* p;
  for (i = 0; i < nRows; ++i) {
    p = I.ptr<uchar>(i);
    for (j = 0; j < nCols; ++j) {
      p[j] = table[p[j]];
    }
  }
  return I;
}

cv::Mat& ScanImageAndReduceIterator(cv::Mat& I, const uchar* const table) {
  CV_Assert(I.depth() == CV_8U);
  const int channels = I.channels();
  switch (channels) {
    case 1: {
      cv::MatIterator_<uchar> it, end;
      for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
        *it = table[*it];
      break;
    }
    case 3: {
      cv::MatIterator_<cv::Vec3b> it, end;
      for (it = I.begin<cv::Vec3b>(), end = I.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = table[(*it)[0]];
        (*it)[1] = table[(*it)[1]];
        (*it)[2] = table[(*it)[2]];
      }
    }
  }
  return I;
}

cv::Mat& ScanImageAndReduceRandomAccess(cv::Mat& I, const uchar* const table) {
  CV_Assert(I.depth() == CV_8U);
  const int channels = I.channels();
  switch (channels) {
    case 1: {
      for (int i = 0; i < I.rows; ++i)
        for (int j = 0; j < I.cols; ++j)
          I.at<uchar>(i, j) = table[I.at<uchar>(i, j)];
      break;
    }
    case 3: {
      cv::Mat_<cv::Vec3b> _I = I;
      for (int i = 0; i < I.rows; ++i)
        for (int j = 0; j < I.cols; ++j) {
          _I(i, j)[0] = table[_I(i, j)[0]];
          _I(i, j)[1] = table[_I(i, j)[1]];
          _I(i, j)[2] = table[_I(i, j)[2]];
        }
      I = _I;
      break;
    }
  }
  return I;
}
