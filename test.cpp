#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Point
{

    private :
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

    int getId() { return clusterId; }

    Point getPoint(int pos) { return points[pos]; }

    int getSize() { return points.size(); }

    double getCentroidByPos(int pos) { return centroid[pos]; }

    void setCentroidByPos(int pos, double val) { this->centroid[pos] = val; }
};


/* class Kmeans{
int K, iters, dimensions, total_points;




}; */




bool getFileContent(string fileName,vector<string> & vecOfStrs)
{ 
  ifstream in(fileName.c_str());

    if(!in)
    {
        cerr << "Cannot open the File : "<<fileName<<endl;
        return false;
    }
    string str;

    while (getline(in, str))
    {

vecOfStrs.push_back(str);
    }

    in.close();
    return true;
} 
;

    
 





    
 


int main (){
    vector<string> vecOfStr;
	bool result = getFileContent("base.txt",vecOfStr);
	vector< vector<double> > v;
	vector<double> v1;
	int c;
	if (result)
	{
		for (int i = 0; i < vecOfStr.size(); i++)
		{
			istringstream iss(vecOfStr[i]);
			copy(istream_iterator<double>(iss),
				istream_iterator<double>(),
				back_inserter(v1));
			if (i == 0) c = v1.size();
			int k = v1.size() - c;
			v.push_back(vector<double>());
			for (int j = 0; j < c; j++)
				v[i].push_back(v1[k+j]);
		}
	}
   
   Point p1= Point(0,v[0]);
   Cluster c1= Cluster(1,p1);
   double size=c1.getCentroidByPos(3);
   cout << size << endl;






/* cout << '[';
        for (int j = 0; j < v[0].size(); j++){
            cout<< v[0][j]<<" ";

        }
        cout << ']' << endl; */
   

}
;