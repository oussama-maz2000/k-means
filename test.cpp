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

}
}
;


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

    void removeAllPoints() { points.clear(); }

    int getclusterId() { return clusterId; }

    Point getPoint(int pos) { return points[pos]; }

    int getSize() { return points.size(); }

    double getCentroidByPos(int pos) { return centroid[pos]; }

    void setCentroidByPos(int pos, double val) { this->centroid[pos] = val; }
};


class Kmeans{
public :
int k, iterations, dimensions, total_points;
vector<Cluster>cluster;
 
 public : Kmeans (int k ,int nbr_iterations){
    this->k=k;
    this->iterations=nbr_iterations;
 }

  




}; 




vector<vector <double> > getFileContent(string fileName,vector<string> & vecOfStrs)
{ 
    vector< vector<double> > v;
	vector<double> v1;
	int c;
  ifstream in(fileName.c_str());

    if(!in)
    {
        /* cout << "Cannot open the File : "<<fileName<<endl; */
        return v;
        
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
} 
;

    
 





    
 


int main (){
    vector<string> vecOfStr;
	vector<vector<double> > result = getFileContent("base.txt",vecOfStr);


    Point p1= Point(0,result[0]);
   Cluster c1= Cluster(1,p1);
int size =p1.getDemension();
   cout << "the size of " <<size << endl; 






   

}
;