

#include "Save.h"

	void Save::fprintf3Point( vector< vector< Point3f> > Points, string name)
	{
		 FILE * fp;
 		fp = fopen(name.c_str() ,"w");
 		for(int i=0; i< Points.size(); ++i)
 		{
  			for(int j=0; j< Points[i].size(); ++j)
  			{
  			 fprintf(fp,"%lf %lf %lf\n", Points[i][j].x, Points[i][j].y, Points[i][j].z);
  			}
  		fprintf(fp,"\n");
 		}
 	fclose(fp);
	}


	
	void Save::fprintf2Point( vector< vector< Point2f> > Points, string name)
	{
		 FILE * fp;
	 	 fp = fopen(name.c_str() ,"w");
		 for(int i=0; i< Points.size(); ++i)
		 {
 	 		for(int j=0; j< Points[i].size(); ++j)
  			{
  	 		fprintf(fp,"%lf %lf\n", Points[i][j].x, Points[i][j].y);
  			}
  		fprintf(fp,"\n");
 		}
 	fclose(fp);
	}


	void Save::fprintfVectorMat(vector< Mat> matrix, string name)
	{
		 FILE * fp;
 		fp = fopen(name.c_str() ,"w");
 		int i,j; 
 		printf("%s size %d, %d\n",name.c_str(),matrix.size(), matrix[0].cols, matrix[0].rows);
 		for(i=0; i< matrix.size(); ++i)
 		{
  			for(int j=0; j< matrix[i].rows; ++j)  
  			{
   				for(int k=0; k< matrix[i].cols; ++k)
   				{
    				fprintf(fp,"%lf ", matrix[i].at<  double >(j,k)); 
   				}
   			fprintf(fp,"\n");
  			}
  			fprintf(fp,"\n");
 		}		

 		fclose(fp);
	}	

	void Save::fprintMatrix(Mat matrix, string name)
	{
		 FILE * fp;
 		fp = fopen(name.c_str() ,"w");
 		int i,j; 
 		printf("%s size %d %d\n",name.c_str(), matrix.cols, matrix.rows);
 		for(i=0; i< matrix.rows; ++i)
 		{
  			for(j=0; j< matrix.cols; ++j)
  			{
  			 fprintf(fp,"%lf ", matrix.at<  double >(i,j)); 
  			}
  		fprintf(fp,"\n");
	 	}
 
	 fclose(fp);
	 }

