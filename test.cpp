#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Point
{
public :
    int pointId ,dimension,clusterId;
    vector<double> values;
public: Point (int id,vector<double> vecLine){
    pointId=id;
    values=vecLine;
    dimension=values.size();
    clusterId=0;}

int getPointId(){
    return pointId;
}
int getDemension(){
    return dimension;}
    
void setClusternum(int num){
        clusterId=num;
    }
double getvalue(int index){
    return values[index];
}};

class Cluster {
public : 
    int clusterId;
    vector<double> centroid;
    vector<Point> points;


    public: Cluster(int idClus,Point centre){
        this->clusterId=idClus;
        for (int i = 0; i < centre.getDemension(); i++)
        {
            this->centroid.push_back(centre.getvalue(i));
        }
        
        this->addPoint(centre);
    }

    void addPoint(Point p){
     p.setClusternum(this->clusterId);
        this->points.push_back(p);
    }
      bool removePoint(int pointId)
    {
        int size = points.size();

        for (int i = 0; i < size; i++)
        {
            if (points[i].getPointId() == pointId)
            {
                points.erase(points.begin() + i);
                return true;
            }
        }
        return false;
    }
int getClusterId(){return clusterId;}
    void removeAllPoints() { points.clear(); }

    int getclusterId() { return clusterId; }

    Point getPoint(int pos) { return points[pos]; }

    int getSize() { return points.size(); }

    double getCentroidByPos(int pos) { return centroid[pos]; }

    void setCentroidByPos(int pos, double val) { this->centroid[pos] = val; }
};

class BKmeans{
public :
int k, iterations, dimension, total_points;
vector<Cluster>cluster;
 
 public : BKmeans (int k ,int nbr_iterations){
    this->k=k;
    this->iterations=nbr_iterations;
 }

 int calculatedistance(Point p){
    double somme , distance;
    int nearclusterId;


 for (int i=0;i<dimension;i++){
somme=pow(cluster[0].getCentroidByPos(i)-p.getvalue(i),2);
}
// initialisation du distance avec la distance du premier cluster
distance=sqrt(somme);
// initialisation du clusterId avec le clusterId du premier cluster
nearclusterId=cluster[0].getClusterId();
for (int i;i<k;i++){
    double tmp;
    somme=0.0;
    for(int j=0;j<dimension;j++){
        somme=pow(cluster[i].getCentroidByPos(j)-p.getvalue(j),2);
    }
    tmp=sqrt(somme);
if(tmp<distance){
    distance=tmp;
    nearclusterId=cluster[i].getClusterId();
}
}
return nearclusterId;
}; 
};

vector<vector <double> > getFileContent(string fileName,vector<string> vecOfStrs)
{ 
    vector< vector<double> > v;
    

	vector<double> v1;
	int c;
  ifstream in(fileName.c_str());

    if(!in)
    {
        return  v;
    }
    string str;
    while (getline(in, str))
    {
vecOfStrs.push_back(str);
    }
    in.close();

for (int i = 0; i < vecOfStrs.size(); i++)
		{
			istringstream iss(vecOfStrs[i]);
			copy(istream_iterator<double>(iss),
				istream_iterator<double>(),
				back_inserter(v1));
			if (i == 0) c = v1.size();
			int k = v1.size() - c;
			v.push_back(vector<double>());
			for (int j = 0; j < c; j++)
				v[i].push_back(v1[k+j]);
		}
    return v;
} ;
int main (){
    vector<string>vecOfStrs;
    vector<vector<double> > result;
    result=getFileContent("./base.txt",vecOfStrs);
    Point p=Point(1,result[1]);
int dem=p.getDemension();
int pointid=p.getPointId();
cout << "pointid : "<< pointid<<endl;
cout << dem ;

}

;