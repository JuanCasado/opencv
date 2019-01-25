#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

void on_slider (int amount,void *data);

struct Lines {
    cv::Mat img;
    int rho = 1;
    int theta = 1;
    int threshold = 0;
    int minLineLength = 0;
    int maxLineGap = 0;
};

int main (int argc, char **argv){
    cv::Mat img;
    if (argc == 2){
        img = cv::imread(argv[1]);
    } else {
        img = cv::imread("../../../tests_img/rbot2.jpg");
    }
    if (!img.data){
        std::cout << "ERROR READING IMG" << std::endl;
        return 1;
    }

    cv::namedWindow("lineas");
    cv::namedWindow("toggles");

    Lines lines_config;
    cv::Canny( img, lines_config.img, 50, 200, 3 );
    //cv::cvtColor(canny, lines_config.img, cv::COLOR_BGR2GRAY);

    //cv::imshow("lineas", lines_config.img);
    cv::createTrackbar("rho", "toggles", &lines_config.rho, 100, on_slider, &lines_config);
    cv::createTrackbar("theta", "toggles", &lines_config.theta, 100, on_slider, &lines_config);
    cv::createTrackbar("threshold", "toggles", &lines_config.threshold, 100, on_slider, &lines_config);
    cv::createTrackbar("minLineLength", "toggles", &lines_config.minLineLength, 100, on_slider, &lines_config);
    cv::createTrackbar("maxLineGap", "toggles", &lines_config.maxLineGap, 100, on_slider, &lines_config);

    on_slider (0, &lines_config);

    cv::waitKey(0);
    return 0;
}

void on_slider (int amount,void *data) {
    Lines *lines_config = (Lines*) data;

    lines_config->rho = (lines_config->rho? lines_config->rho : 1);
    lines_config->theta = (lines_config->theta? lines_config->theta : 1);

    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP (lines_config->img, lines, lines_config->rho, lines_config->theta,lines_config->threshold,lines_config->minLineLength,lines_config->maxLineGap);

    cv::Mat img;
    cv::Mat img_color;
    cvtColor(lines_config->img, img_color, cv::COLOR_GRAY2BGR );
    for(int i = 0; i < lines.size(); i++ ){
        cv::line( img_color, cv::Point(lines[i][0], lines[i][1]), cv::Point( lines[i][2], lines[i][3]), cv::Scalar(0,0,255), 3, 8);
    }

    cv::imshow("lineas", img_color);
}