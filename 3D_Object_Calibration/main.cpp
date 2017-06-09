

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <opencv2/calib3d/calib3d.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "Parameter_Calibrator.h"


using namespace cv;
using namespace std;



int main( int, char** argv )
{
  
    	VideoCapture cap(1);
  	Parameter_Calibrator calibrator();

	if ( !cap.isOpened() )  			// if not success, exit program
  	{
        	cout << "Cannot open the video file" << endl;
      		return -1;
    	}
     
        Mat src;
	while(1)
    	{
    		bool bSuccess = cap.read(src); 		// read a new frame from video
    	
		if (!bSuccess) 				//if not success, break loop
   			break;	
      	
		calibrator.Calibrator(src);             // accessing Calibrator

  		if( waitKey(3)==27) 
			break;

       	}

}


