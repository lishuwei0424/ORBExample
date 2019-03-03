#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int main(int argc ,char *argv[])
{
    cv::Mat Image;

    if (argc!=2){
        cout<<" 请检查参数是否错误"<<endl;
        cout<<" 正确格式为：　./FastExample  ../1.png"<<endl;


    }
    Image=cv::imread(argv[1]);   //读取图像文件，文件取是命令行的参数　，注意是　可行性文件是ａｒｇｖ[1],图像为为第二参数

    //定义ｆａｓｔ特征点提取
    std::vector<cv::KeyPoint>  keyPoints;

    // cv::FastFeatureDetector    fast(40);
    //fast.detect(Image,keyPoints)

    cv::Ptr<cv::FeatureDetector> fast=cv::FastFeatureDetector::create(40);  //https://ask.csdn.net/questions/363642
    fast->detect(Image,keyPoints);

    //drawKeypoints参数　https://blog.csdn.net/qq_35154529/article/details/81215727
    cv::drawKeypoints(Image,keyPoints,Image,cv::Scalar::all(225),cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);
    cv::imshow("fast_image",Image);
    cv::waitKey();

    return 0;
}


