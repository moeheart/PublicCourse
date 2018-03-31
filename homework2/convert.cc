// Copyright @2018 Pony AI Inc. All rights reserved.

#include "opencv/cv.h"
#include "opencv/highgui.h"

int main()
{
    IplImage *img = cvLoadImage("/home/ubuntu/PublicCourse/pony_data/test.jpg");
    unsigned char *pImg;

    for(int i = 0; i < img->height; i++)
    {
        pImg = (unsigned char *)img->imageData + i * img->widthStep;
        for(int j = 0; j < img->width; j++)
        {
            pImg[0] ^= 255;
            pImg[1] ^= 255;
            pImg[2] ^= 255;

            pImg += 3;
        }
    }
    return 0;
}
