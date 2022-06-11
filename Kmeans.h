#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<double> > readFileContent(string fileName,vector<string>&vecOfStrs); // function read file and return the content of file in vector of vectors of double 

class Point {
public:
    int pointId; // the ID of point
    int dimension; // size of vector
    int clusterId; // the ID of cluster
    vector<double> values; //the values of point

    public :Point (int id,vector<double>vecLine);  // constructor with params
    int getPointId(); // function return the ID of point
    int getDemension(); // function return the size of vector
    void setClusternum(int num); // function set the ID of cluster 
    double getvalue(int index); // function return the value of index in point (values[index])
};

class Cluster {
public :
    int clusterId; // the ID of cluster
    vector<double> centroid; // the values of centroid
    vector <Point> points; // the points in cluster
public:
    Cluster(int idClus,Point centre); // constructor with params
    void addPoint(Point p); // function add point to the cluster
    bool removePoint(int pointId); // function remove point from the cluster
    void removeAllPoint(); // function remove all points from the cluster (clean the cluseter from points)
    int getClusterId(); // function return the ID of cluster(clusterId)
    Point getPoint(int position) ;// function return value of point[position]
    int getSize (); // function return the size of points in cluster
    double getCentroidBypos(int position); // function return the value of centroid[position]
    void setCentroidBypos(int position ,double value);// function set the value of centroid[position]=value;
};

class Kmeans{
public : 
    int k; // number of clusters
    int iterations; // number of iterations it will run
    int demination; // dimension of point
    int total_point; // total number of points
    vector<Cluster> clusters; // vector of clusters
public : 
    Kmeans(int k,int iterations); // constructor with params
    void clearCluster(); //functions remove all values from the cluster
};
