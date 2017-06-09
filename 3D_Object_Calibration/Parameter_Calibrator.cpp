



#include "Parameter_Calibrator.h"
#include "Save.h"
#include "Calculator.h"



	Parameter_Calibrator::Parameter_Calibrator()
        {
/////////////////////////////setting world coordinates//////////
/////0
	objectPoints.push_back(cv::Point3f( 78.0f,52.0f,0.0f));
	objectPoints.push_back(cv::Point3f(78.0f,78.0f,0.0f));
 	objectPoints.push_back(cv::Point3f(104.0f,78.0f,0.0f));
  	objectPoints.push_back(cv::Point3f(104.0f,52.0f,0.0f));
        
/////1
	objectPoints.push_back(cv::Point3f( 52.0f,78.0f,0.0f));
	objectPoints.push_back(cv::Point3f(52.0f,104.0f,0.0f));
 	objectPoints.push_back(cv::Point3f(78.0f,104.0f,0.0f));
  	objectPoints.push_back(cv::Point3f(78.0f,78.0f,0.0f));

/////2

	objectPoints.push_back(cv::Point3f( 52.0f,26.0f,0.0f));
	objectPoints.push_back(cv::Point3f(52.0f,52.0f,0.0f));
 	objectPoints.push_back(cv::Point3f(78.0f,52.0f,0.0f));
  	objectPoints.push_back(cv::Point3f(78.0f,26.0f,0.0f));

/////3
       
	objectPoints.push_back(cv::Point3f( 26.0f,52.0f,0.0f));
	objectPoints.push_back(cv::Point3f(26.0f,78.0f,0.0f));
 	objectPoints.push_back(cv::Point3f(52.0f,78.0f,0.0f));
  	objectPoints.push_back(cv::Point3f(52.0f,52.0f,0.0f));

/////4 

	
	objectPoints.push_back(cv::Point3f( 78.0f,0.0f,78.0f));
	objectPoints.push_back(cv::Point3f(78.0f,0.0f,52.0f));
 	objectPoints.push_back(cv::Point3f(104.0f,0.0f,52.0f));
  	objectPoints.push_back(cv::Point3f(104.0f,0.0f,78.0f));

/////5

	objectPoints.push_back(cv::Point3f( 52.0f,0.0f,52.0f));
	objectPoints.push_back(cv::Point3f(52.0f,0.0f,26.0f));
 	objectPoints.push_back(cv::Point3f(78.0f,0.0f,26.0f));
  	objectPoints.push_back(cv::Point3f(78.0f,0.0f,52.0f));

/////6

	objectPoints.push_back(cv::Point3f( 26.0f,0.0f,78.0f));
	objectPoints.push_back(cv::Point3f(26.0f,0.0f,52.0f));
 	objectPoints.push_back(cv::Point3f(52.0f,0.0f,52.0f));
  	objectPoints.push_back(cv::Point3f(52.0f,0.0f,78.0f));

/////7

	objectPoints.push_back(cv::Point3f( 0.0f,26.0f,78.0f));
	objectPoints.push_back(cv::Point3f(0.0f,52.0f,78.0f));
 	objectPoints.push_back(cv::Point3f(0.0f,52.0f,52.0f));
  	objectPoints.push_back(cv::Point3f(0.0f,26.0f,52.0f));

/////8

	objectPoints.push_back(cv::Point3f( 0.0f,52.0f,52.0f));
	objectPoints.push_back(cv::Point3f(0.0f,78.0f,52.0f));
 	objectPoints.push_back(cv::Point3f(0.0f,78.0f,26.0f));
  	objectPoints.push_back(cv::Point3f(0.0f,52.0f,26.0f));

/////9

	objectPoints.push_back(cv::Point3f( 0.0f,78.0f,78.0f));
	objectPoints.push_back(cv::Point3f(0.0f,104.0f,78.0f));
 	objectPoints.push_back(cv::Point3f(0.0f,104.0f,52.0f));
  	objectPoints.push_back(cv::Point3f(0.0f,78.0f,52.0f));
  	
/////10

	objectPoints.push_back(cv::Point3f( 52.0f,0.0f,104.0f));
	objectPoints.push_back(cv::Point3f(52.0f,0.0f,78.0f));
 	objectPoints.push_back(cv::Point3f(78.0f,0.0f,78.0f));
  	objectPoints.push_back(cv::Point3f(78.0f,0.0f,104.0f));
  	
/////11

	objectPoints.push_back(cv::Point3f( 0.0f,52.0f,104.0f));
	objectPoints.push_back(cv::Point3f(0.0f,78.0f,104.0f));
 	objectPoints.push_back(cv::Point3f(0.0f,78.0f,78.0f));
  	objectPoints.push_back(cv::Point3f(0.0f,52.0f,78.0f));
 
        objectPoints_vector.push_back(objectPoints);

	intrinsic_Matrix  =Mat(3,3, CV_64F);

  	intrinsic_Matrix.at<double>(0,0)= 700.0;
	intrinsic_Matrix.at<double>(0,1)= 0.0;
	intrinsic_Matrix.at<double>(0,2)= 320.0;
	intrinsic_Matrix.at<double>(1,0)= 0 ;
	intrinsic_Matrix.at<double>(1,1)= 700.0;
	intrinsic_Matrix.at<double>(1,2)= 240.0;
	intrinsic_Matrix.at<double>(2,0)= 0.0 ;
	intrinsic_Matrix.at<double>(2,1)= 0.0 ;
	intrinsic_Matrix.at<double>(2,2)= 1.0 ;

        distortion_coeffs= Mat(8,1, CV_64F);
        
 	drawing = Mat::zeros( thresh_img.size(), CV_8UC1 );
  
    	k=0 ;   
       	j=0 ;
        d=0 ;
        sum=0;
	totalAvgErr = 0;
  
        

        }


	void Parameter_Calibrator::Calibrator(Mat src)

	{
          
	imageSize = Size(src.cols, src.rows); ////def imagesize
 	cvtColor( src, src_gray, COLOR_BGR2GRAY );////def src_gray

 	imshow("src_gray",src_gray);
 	threshold( src_gray, thresh_img, 200, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);// def thresh_img
 	
 	dilate(thresh_img,thresh_img, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)) );
 	erode(thresh_img,thresh_img, getStructuringElement(MORPH_ELLIPSE, Size(3, 3 )) );
	imshow("thresh_img",thresh_img);

	
       	findContours( thresh_img, contours0, hierarchy1,CV_RETR_LIST,CV_CHAIN_APPROX_NONE); // Find the contours in the image
	

	contours.resize(contours0.size()); // size should be same for transfering conoturs *** after removing gives segementation fault
        contours1.resize(contours0.size());
        
	Save saver;
        Calculator finder;    
        std::vector< Point2f > preciseCorners(4);// vector for storing precise corners
        
       
    	for( k=0; k < contours0.size(); k++ )
        {    
               
              // double eps = contours0[k].size() * 0.09; 
		approxPolyDP(contours0[k], contours[k],arcLength(Mat(contours0[k]), true)*0.02, true); // approximate the polygons 
          
              	if (contours[k].size() != 4)            // 1st test must have 4 corners
			continue;

                if (!cv::isContourConvex(contours[k])) // 2nd test not to be convex
			continue;
                
                for(int m = 0; m < 4; m++)  
		{
        	         d = (double)(contours[k][m].x - contours[k][(m + 1) % 4].x) *(double)(contours[k][m].x - contours[k][(m + 1) % 4].x) +
                       	   (double)(contours[k][m].y - contours[k][(m + 1) % 4].y) *(double)(contours[k][m].y - contours[k][(m + 1) % 4].y);
            
       		}
                
                if (d < 50)    // 3rd test minimum distance between alternative corners 
        	        continue;
        	        
                if( contours[k].size() == 4 &&
                    fabs(contourArea(Mat(contours[k]))) > 2000 && fabs(contourArea(Mat(contours[k]))) < 4000 &&
                    isContourConvex(Mat(contours[k])) )
                {
                    double maxCosine = 0;

                    for( int l = 2; l < 5; l++ )
                    {
                        // find the maximum cosine of the angle between joint edges
                        
                        double cosine = fabs(finder.setAngle(contours[k][l%4], contours[k][l-2], contours[k][l-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence
                    if( maxCosine < 0.5 )
                        {
        	                squares.push_back(contours[k]);         
                   
				contours1[j]=contours[k];
				//index[j]=k;            // storing index of contours which passes the test.
        	        	j=j+1;
                 	
			}
		}
    
  
	}

cout<<"J ------- "<< j <<endl;


		if (j == 12 )
			 {
		 for( int i = 0; i< j; i++ )
     			{
     			  Scalar color = Scalar(255,255,255);
    
			       drawContours( drawing, contours1, i,color, 2, 8, hierarchy1, 1, Point() );

///////////// algo to get pt to pt correspondence //////////// (0,1) contours

     				if ( contours1[0][2].x < contours1[1][2].x )
				 {
       	 	 		  	index[0]=0; 
          				index[1]=1;
       	  			 }
        			else
   	       			{
          				index[0]=1; 
          				index[1]=0;       
          			}
////////////////////////////////////(2,3) contours

        			if ( contours1[2][2].x < contours1[3][2].x )
        	 		{
          				index[2]=2; 
          				index[3]=3;
          			}		
        			else
        			{
          				index[2]=3; 
          				index[3]=2;          
        			}

       				int r_index;
       				for (r_index=0;r_index < 6;r_index++) {
       					 contour_arrange[r_index]=contours1[r_index+4][3].x;
                 			 contour_arrange_original[r_index]=contours1[r_index+4][3].x;
				}
       
				std::sort(contour_arrange,contour_arrange + 6 );


/////////////////////////////////////
/*
        C        X       X^     
 	0	125	112	1	
	1	112	125	0
	2	391	300	4
	3	412	352	5
	4	300	391	2
	5	352	412	3


*/
//////////////////////////////////

  				for (int s=0; s<6; s++)
  				{      
   			 		int* low = std::lower_bound (&contour_arrange[0], &contour_arrange[6], contour_arrange_original[s]);   
   					// cout << "Element: " << contour_arrange_original[i] << " is at: " << distance(&contour_arrange[0], low) + 4  << endl
   					//cout << "Contour: " << s + 4 << " is at: " << distance(&contour_arrange[0], low) + 4  << endl;
   	 				index[s+4]= distance(&contour_arrange[0], low) + 4 ;  
  				}
  

////////////////////////////////// pattern of cube detected//////////////////////////////////////
/*
    


      |---|               |---| 
      | 10|	          | 11|	 
      |---|	          |---|
|---|      |---|     |---|     |---|
| 4 |      | 6 |     | 7 |     | 9 |
|---|      |---|     |---|     |---|
      |---|               |---|
      | 5 |               | 8 |
      |---|               |---|


          |---|      |---|         
          | 2 |	     | 3 |       	 
          |---|      |---|
	          
	  |---|      |---|     
	  | 0 |      | 1 |     
	  |---|      |---|         
                   
*/             
//////////////////////////////arranging indices to get the pattern in 1234567891011 fomat////////////////////////////////




 				for(int k=0;k<6;k++){
					for(int n=0; n<6; n++){	
						if(((k+4)-index[n+4])==0)
							flag[k]=n+4;
					}		
   				}

  // for(int h=0;h <6; h++){
    //     cout<<"filtered array: "<< flag[h] << "  "<< endl;
   //}





///////////////////algo for last 2 contours///////////////////



				if ( contours1[10][0].x < contours1[11][0].x )
        			{
          				index[10]=10; 
          				index[11]=11;
          
        			}
     				else
        			{
          				index[10]=11; 
          				index[11]=10;
          
        			}

//////////////////////////////// printing contours drawing order ////////////////////

//cout<< " contours order : " << endl;
				 for (int u=0; u < 12 ; u++){
   
        				if(u > 3 && u < 10)
             					index[u]=flag[u-4];

						//cout << index[u] <<"  "; 
				}  

//////////////////////////////estimating corners/////////////////////


   				for (int c=0;c<4;c++)
						
				{		
					 preciseCorners[c] = contours1[index[i]][c];     // storing in precise corner array
				}
         	
                			
					cv::cornerSubPix(thresh_img, preciseCorners, cvSize(5,5),cvSize(-1,-1),    
        				cvTermCriteria(CV_TERMCRIT_ITER,30,0.1));
                					
				      
        			for (int c=0;c<4;c++)
				{
					contours1[index[i]][c] = preciseCorners[c];   // storing precise corner in contours list 
				}
                         


    				imagePoints.push_back(Point2f(contours1[index[i]][0].x,contours1[index[i]][0].y));
    				imagePoints.push_back(Point2f(contours1[index[i]][1].x,contours1[index[i]][1].y));
    				imagePoints.push_back(Point2f(contours1[index[i]][2].x,contours1[index[i]][2].y));
    				imagePoints.push_back(Point2f(contours1[index[i]][3].x,contours1[index[i]][3].y));

    				cout<<" X :"<< contours1[index[i]][0].x <<  " Y : "<< contours1[index[i]][0].y <<endl; 	
    				cout<<" X :"<< contours1[index[i]][1].x <<  " Y : "<< contours1[index[i]][1].y <<endl;	
    				cout<<" X :"<< contours1[index[i]][2].x <<  " Y : "<< contours1[index[i]][2].y <<endl;
   	   			cout<<" X :"<< contours1[index[i]][3].x <<  " Y : "<< contours1[index[i]][3].y <<endl;		
  
    				circle(src, Point(contours1[index[i]][0].x,contours1[index[i]][0].y),4, Scalar(0, 255,255), -1, 8, 0);
    				circle(src, Point(contours1[index[i]][1].x,contours1[index[i]][1].y),4, Scalar(0, 255,255), -1, 8, 0);
    				circle(src, Point(contours1[index[i]][2].x,contours1[index[i]][2].y),4, Scalar(0, 255,255), -1, 8, 0);
    				circle(src, Point(contours1[index[i]][3].x,contours1[index[i]][3].y),4, Scalar(0, 255,255), -1, 8, 0);
                                        
   
     				cout<<" imgsize: "<< imagePoints_vector.size() << endl;
     
    				imshow( "source_window", src );
    				cout<<" next contour coordinates "<< endl;
  
        			imshow( "Contours", drawing );
        			
     			}
 
 //claibration part
     				imagePoints_vector.push_back(imagePoints);         	
	 
	 			calibrateCamera(objectPoints_vector, imagePoints_vector, imageSize, intrinsic_Matrix, distortion_coeffs, 							rvecs, tvecs,CV_CALIB_USE_INTRINSIC_GUESS );

           
        			finder.setComputeReprojectionErrors(objectPoints_vector, imagePoints_vector,rvecs, tvecs, intrinsic_Matrix, 							distortion_coeffs, reprojErrs);
      	
				totalAvgErr = finder.getComputeReprojectionErrors();
          
        			cout<< "reprojection error " << totalAvgErr << endl;
				
				saver.fprintMatrix(intrinsic_Matrix, "intrinsic.txt");
 				saver.fprintMatrix(distortion_coeffs, "distortion_coeffs.txt");

 				saver.fprintfVectorMat(rvecs, "rotation.txt");
 				saver.fprintfVectorMat(tvecs, "translation.txt");
	
 				saver.fprintf3Point(objectPoints_vector, "objectpt.txt");
 				saver.fprintf2Point(imagePoints_vector, "imagept.txt");
	
  	

		}

		

	   }
	  	

