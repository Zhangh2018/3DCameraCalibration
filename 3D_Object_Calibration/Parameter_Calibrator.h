

#ifndef PARAMETER_SETTER_H
#define PARAMETER_SETTER_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <opencv2/calib3d/calib3d.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <vector>



using namespace std;
using namespace cv;

class Parameter_Calibrator
{
public:
  
 	Parameter_Calibrator();
     	void Calibrator(Mat src);

private:
	vector<Point3f> objectPoints ;
        std::vector< vector< Point3f> > objectPoints_vector;
        
	Mat intrinsic_Matrix ;
	Mat distortion_coeffs;
        Mat src_gray;
	Mat thresh_img;
        Mat drawing;
        Size imageSize;

   	vector<Vec4i> hierarchy1;//hierarchy of contours
        vector< vector<Point> > contours; // Vector for storing selected contour
  	vector< vector<Point> > contours0;// Vector for storing original contour
        vector< vector<Point> > contours1;
      
        std::vector< vector< Point2f> > imagePoints_vector;	
 	std::vector< Point2f > imagePoints; // vector for storing image points 

        vector<vector<Point> > squares;       
        vector< Mat> rvecs, tvecs;
        vector<float> reprojErrs;

        int index[2000];
        int contour_arrange[6];
        int contour_arrange_original[6];
        int flag[20];
     
        int k ;   
        int j ;
        int d ;
	int sum;
        double totalAvgErr;
        
        

};
#endif // PARAMETER_SETTER_H
