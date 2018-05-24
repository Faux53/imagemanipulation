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
#include <thread>
#include </Users/andrewadams/Desktop/Pinto/sloth_comp_read.cpp/cpp-sockets/net/serversocket.hpp>


using namespace cv;
using namespace std;


static bool s_finished = false;  //declare the thread as in process


void read_comp() {
    
    //int cntr = 1;
    //std::string i = "/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images (" + std::to_string(++cntr) + ").jpg";
    //this calls the images in one string, it's also possible to manually enter them from a vector.  in this case i went with manually reading and writing them one by one as the documentation asked, also it adds a reason for me to build the multithreading functionality.
    
    
    //grabs the image from the root file, it's also possible to just include your image directory

    Mat read_image;
    read_image = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images.jpg", cv::IMREAD_COLOR);
    read_image = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images (1).jpg", cv::IMREAD_COLOR);
    read_image = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images (2).jpg", cv::IMREAD_COLOR);
    read_image = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images (3).jpg", cv::IMREAD_COLOR);
    
    // Call the source and apply your changes to the image using OpenCV (i.e. greyscale, tracking, rotating etc etc)
    
    
    if(! read_image.data )   // Check for invalid input
    {
        cout <<  "No sloths in these woods" << std::endl ;
        return;
    }
    
    Mat compress;
    int p[3];  //writes out parameters within the compress Mat
    p[0] = IMWRITE_JPEG_QUALITY;
    p[1] = 50; //decide on quality ranging from 0-->100
    compress = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images.jpg", p[1]);
    
    Mat compress1;
    int p1[3];  //writes out parameters within the compress Mat
    p1[0] = IMWRITE_JPEG_QUALITY;
    p1[1] = 50; //decide on quality ranging from 0-->100
    compress1 = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images (1).jpg", p1[1]);
    
    Mat compress2;
    int p2[3];  //writes out parameters within the compress Mat
    p2[0] = IMWRITE_JPEG_QUALITY;
    p2[1] = 50; //decide on quality ranging from 0-->100
    compress2 = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images (2).jpg", p2[1]);
    
    Mat compress3;
    int p3[3];  //writes out parameters within the compress Mat
    p3[0] = IMWRITE_JPEG_QUALITY;
    p3[1] = 50; //decide on quality ranging from 0-->100
    compress3 = imread("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/sloths/images (3).jpg", p3[1]);
    
    
    //apply the changes you made to your images quality by calling the char const up above.
 
    //std::string out = ("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/squishedsloths/out" + std::to_string(++cntr) + ".jpg");
    //line 27
    
    Mat save;
    save = imwrite("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/squishedsloths/out.jpg", compress);
    save = imwrite("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/squishedsloths/out1.jpg", compress1);
    save = imwrite("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/squishedsloths/out2.jpg", compress2);
    save = imwrite("/Users/andrewadams/Desktop/pinto/sloth_comp_read.cpp/sloth_comp_read.cpp/squishedsloths/out3.jpg", compress3);
    //saves the compression above
    
    
    while (!s_finished) {
        std::cout << "working... \n";
        std::this_thread::sleep_for(1s);
    }
    //thread wait
};




int main( int argc, char** argv)
{
    
    std::thread worker(read_comp);
    
    
    std::cin.get();
    s_finished = true;
    
    worker.join();
    std::cout << "Finished" << std::endl;
    
    std::cin.get();
    
    
  
    exit(0);
}

//thread joiner


net::serversocket::~serversocket() {
    close();
}

int net::serversocket::listen() {
    
    net::socketaddress* sockaddr = new net::socketaddress("http://localhost:8888/notebooks/Untitled1.ipynb?kernel_name=conda-root-py", 8888);
    struct sockaddr_in addr = sockaddr->get_struct();
    
    socketfd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (socketfd == -1) {
        return errno;
    }
    
    int yes = 1;
    if (::setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) != 0) {
        close();
        return errno;
    }
    
    if (::bind(socketfd, (struct sockaddr*)&addr, sizeof(struct sockaddr)) != 0) {
        close();
        return errno;
    }
    
    if (::listen(socketfd, backlog) != 0) {
        close();
        return errno;
    }
    
    return 0;
}

net::socket* net::serversocket::accept() {
    struct sockaddr_in from;
    socklen_t l = sizeof(from);
    int clientfd = ::accept(socketfd, (struct sockaddr*)&from, &l);
    
    return new net::socket(clientfd, from);
}

//server socket that goes to my jupyter virtual environment. Note: it's important to set jupyter to run after the the host accepts the client socket, or else it'll just sit there doing nothing.
