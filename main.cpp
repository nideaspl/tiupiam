#include <iostream>
#include <opencv2/opencv.hpp>

using String = std::string;

cv::Mat solve(const cv::Mat& sourceImage)
{
    cv::Mat result = sourceImage.clone();
    std::vector<cv::Mat> channels;

    /* YOUR CODE BEGIN */
    cv::split(result,channels);
    
    /* YOUR CODE END */
   cv::Mat src = channels.at(0);
       /* YOUR CODE BEGIN */
    cv::threshold(src,src,80,255,0);
       /* YOUR CODE END */
   std::vector<std::vector<cv::Point>> contours;
   std::vector<cv::Vec4i> hierarchy; 

       /* YOUR CODE BEGIN */
       cv::findContours(src,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_NONE);
       /* YOUR CODE END */


   for(int i=0; i < contours.size();i++){
            cv::drawContours(sourceImage, contours, -1, cv::Scalar(0, 255, 0), 2,8,hierarchy, 0,cv::Point());
   }
   
   cv::imshow("src",sourceImage); 
  

    //for (int i = 0; i < channels.size(); i++){
	  //  cv::cvtColor(channels[i], channels[i], cv::COLOR_GRAY2RGB);
        //cv::hconcat(result, channels[i], result); 
   // }

	return result;
}

int main()
{
    // set file path
    String imageName = "cap.jpg";

    // read image from file
    cv::Mat image = cv::imread(imageName);
    
    // show the original image
    cv::imshow("original", image);

    // wait for the user to press a key

    // call the solve function
    cv::Mat result = solve(image);

    // show the result image
    cv::imshow("result", result);
         cv::waitKey(0);

    return 0;
}
