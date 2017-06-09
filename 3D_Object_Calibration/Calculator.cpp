


#include "Calculator.h"

	double Calculator::setAngle( Point pt1, Point pt2, Point pt0 )
	{
	    double dx1 = pt1.x - pt0.x;
	    double dy1 = pt1.y - pt0.y;
	    double dx2 = pt2.x - pt0.x;
	    double dy2 = pt2.y - pt0.y;

	    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
	}

	


    	void Calculator::setComputeReprojectionErrors( const vector<vector<Point3f> >& objectPoints,
                          const vector<vector<Point2f> >& imagePoints,
                          const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                          const Mat& cameraMatrix , const Mat& distCoeffs,
                          vector<float>& perViewErrors)
	{
		vector<Point2f> imagePoints2;
		int i, totalPoints = 0;
		double totalErr = 0, err;
		perViewErrors.resize(objectPoints.size());
	
		for( i = 0; i < (int)objectPoints.size(); ++i )
		{
  			projectPoints( Mat(objectPoints[i]), rvecs[i], tvecs[i], cameraMatrix,  // project
                                       distCoeffs, imagePoints2);
  			err = norm(Mat(imagePoints[i]), Mat(imagePoints2), CV_L2);              // difference

  			int n = (int)objectPoints[i].size();
 			perViewErrors[i] = (float) std::sqrt(err*err/n);                        // save for this view
 			totalErr        += err*err;                                             // sum it up
 			totalPoints     += n;
		}
	
		totalAvgErr = std::sqrt(totalErr/totalPoints);              // calculate the arithmetical mean
	}

         
        double Calculator::getComputeReprojectionErrors()
        {
         	return totalAvgErr;
        } 
      
      
