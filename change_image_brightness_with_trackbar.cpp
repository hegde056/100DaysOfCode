
//Change Brighness of Images with trackbar

#include <opencv2/opencv.hpp>
#include <iostream>


cv::Mat origImg;
cv::Mat editedImg;

static void onTrackbarSlide(int alpha, void* userdata)
{
    int beta = *(static_cast<int*>(userdata));


    //Edit Orig image and change brighness - contrast using alpha and beta : https://docs.opencv.org/3.4/d3/d63/classcv_1_1Mat.html#adf88c60c5b4980e05bb556080916978b
    origImg.convertTo(editedImg, -1, alpha, beta);

    cv::imshow("Edited", editedImg);

}




int main()
{
    std::string imagePath = "testSample/dark.jpg";

    //Load the image from given path : https://docs.opencv.org/4.5.2/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56
    origImg = cv::imread(imagePath);

    //Check for file validity 
    if (origImg.empty())
    {
        std::cout << "Error 404 : File not found" << std::endl;
        return -1;
    }
  
    std::string Orig = "Original Image";
    std::string Edited = "Edited";

    //create a window with the windowName : https://docs.opencv.org/4.5.2/d7/dfc/group__highgui.html#ga5afdf8410934fd099df85c75b2e0888b
    cv::namedWindow(Orig);
    cv::namedWindow(Edited);
    //display the image in the window created : https://docs.opencv.org/4.5.2/d7/dfc/group__highgui.html#ga453d42fe4cb60e5723281a89973ee563
    cv::imshow(Orig, origImg);

    int alpha = 1;
    int beta = 50;
    int alpha_max = 3;
    int beta_max = 150;

    cv::createTrackbar("Brighness", Edited,&alpha,alpha_max,onTrackbarSlide,&beta);

    onTrackbarSlide(alpha,&beta);

    //wait for keystroke
    cv::waitKey(0);

    //destroy the created window
    cv::destroyWindow(Orig);
    cv::destroyWindow(Edited);

    return 0;
}