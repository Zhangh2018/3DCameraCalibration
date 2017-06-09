

#ifndef CALCULATOR_H
#define CALCULATOR_H

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

class Calculator
{
 public:  
   
   static double setAngle(Point pt1, Point pt2, Point pt0 );
    

   void setComputeReprojectionErrors(const vector<vector<Point3f> >& objectPoints,
                          const vector<vector<Point2f> >& imagePoints,
                          const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                          const Mat& cameraMatrix , const Mat& distCoeffs,
                          vector<float>& perViewErrors);

   double getComputeReprojectionErrors();
   

 private:

   double totalAvgErr;
   
   
   
};

#endif // CALCULATOR_H
