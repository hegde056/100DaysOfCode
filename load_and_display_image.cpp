
//Load and Display Image

#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    std::string imagePath = "testSamples\test.jpg";

    //Load the image from given path : https://docs.opencv.org/4.5.2/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56
    cv::Mat img = cv::imread(imagePath); //@todo : experiment with imread flags 

    //Check for file validity 
    if (img.empty())
    {
        std::cout << "Error 404 : File not found" << std::endl;
        return -1;
    }
  
    std::string windowName = "Cuteness Overloaded";

    //create a window with the windowName : https://docs.opencv.org/4.5.2/d7/dfc/group__highgui.html#ga5afdf8410934fd099df85c75b2e0888b
    cv::namedWindow(windowName); //@todo : try out windowSize flags

    //display the image in the window created : https://docs.opencv.org/4.5.2/d7/dfc/group__highgui.html#ga453d42fe4cb60e5723281a89973ee563
    cv::imshow(windowName,img);

    //wait for keystroke
    cv::waitKey(0);

    //destroy the created window
    cv::destroyWindow(windowName);
}
