#ifndef SAVE_H
#define SAVE_H

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

class Save
{
 public: 
   
   void fprintf3Point( vector< vector< Point3f> > Points, string name); 
   void fprintf2Point( vector< vector< Point2f> > Points, string name);
   void fprintfVectorMat(vector< Mat> matrix, string name);
   void fprintMatrix(Mat matrix, string name);
  
};

#endif // SAVE_H
