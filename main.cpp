#include <opencv/cv.h>
#include <iostream>
#include <stdio.h>
#include <opencv/cxcore.hpp>
#include "/Users/andrewadams/opencv/modules/highgui/include/opencv2/highgui.hpp"
#include </Users/andrewadams/opencv/modules/core/include/opencv2/core.hpp>
#include <opencv/cv.h>
#include </Users/andrewadams/opencv/modules/imgproc/include/opencv2/imgproc.hpp>
#include </Users/andrewadams/opencv/modules/imgproc/include/opencv2/imgproc/imgproc_c.h>
#include </Users/andrewadams/opencv/modules/imgcodecs/include/opencv2/imgcodecs/imgcodecs_c.h>

using namespace cv;
using namespace std;



int main( int argc, char** argv)
{
    
    char const *i = "/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/images.jpg";
    //grabs the document from the root file, it's also possible to just include your image directory
    
    Mat read_image;
    read_image = imread(i, cv::IMREAD_COLOR);
    // Call the source and apply your changes to the image using OpenCV (i.e. greyscale, tracking, rotating etc etc)
    
    
    
    if(! read_image.data )                              // Check for invalid input
    {
        cout <<  "No sloths in these woods" << std::endl ;
        return -1;
    }
    
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );    // Create a window for display.
    imshow( "Display window", read_image );              // Show our image inside it.
    
    
    Mat compress;
    int p[3];  //writes out parameters within the compress Mat
    p[0] = IMWRITE_JPEG_QUALITY;
    p[1] = 50; //decide on quality ranging from 0-->100
    compress = imread(i, p[1]);  //apply the changes you made to your images quality by calling the char const up above.
    
    
    Mat save;
    save = imwrite("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/out.jpg", compress); //saves the compression above
    
  
    exit(0);
}




