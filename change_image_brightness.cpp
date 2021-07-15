
//Change Brighness of Images 

#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    std::string imagePath = "testSamples\dark.jpg";

    //Load the image from given path : https://docs.opencv.org/4.5.2/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56
    cv::Mat origImg = cv::imread(imagePath);  
    cv::Mat editedImg;

    //Check for file validity 
    if (origImg.empty())
    {
        std::cout << "Error 404 : File not found" << std::endl;
        return -1;
    }
  
    std::string Orig = "Original Image";
    std::string Edited = "Edited Image";

    //create a window with the windowName : https://docs.opencv.org/4.5.2/d7/dfc/group__highgui.html#ga5afdf8410934fd099df85c75b2e0888b
    cv::namedWindow(Orig);
    cv::namedWindow(Edited);

    double alpha, beta;

    std::cout << "\t\t\t:::: OpenCV Editor ::::" << std::endl;
    std::cout << "\t\t\t:: Enter alpha [1 <-> 3] : ";
    std::cin >> alpha; 
    std::cout << "\t\t\t:: Enter beta [-50 <-> 150] : ";
    std::cin >> beta;

    //Edit Orig image and change brighness - contrast using alpha and beta : https://docs.opencv.org/3.4/d3/d63/classcv_1_1Mat.html#adf88c60c5b4980e05bb556080916978b
    origImg.convertTo(editedImg, -1, alpha, beta);


    //display the image in the window created : https://docs.opencv.org/4.5.2/d7/dfc/group__highgui.html#ga453d42fe4cb60e5723281a89973ee563
    cv::imshow(Orig,origImg);
    cv::imshow(Edited, editedImg);

    //wait for keystroke
    cv::waitKey(0);

    //destroy the created window
    cv::destroyWindow(Orig);
    cv::destroyWindow(Edited);
}
