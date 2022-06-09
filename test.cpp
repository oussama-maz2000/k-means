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
    Point (int id,vector<double> vecLine){
   pointId=id;
  values=vecLine;
  dimension=values.size();
  clusterId=0;

    }

int getPointId(){
    return pointId;
}
int getDemension(){
    return dimension;}
    
void setClusternum(int num){
        clusterId=num;
    }


}
;





bool getFileContent(string fileName,vector<string> & vecOfStrs){
    ifstream in(fileName.c_str());
    if (!in) {
        cout << "Cannot open file " << fileName << endl;
        return false;
    }
    string str;
    while (getline(in, str)) {
        vecOfStrs.push_back(str);
    }
    return true;
}










int main (){
    vector<string> vecOfStr;
 bool result = getFileContent("base.txt", vecOfStr);
    
    if(result)
    {
        for (int i = 0; i < 10; i++)
        {
            cout<<vecOfStr[i]<< endl;
            
        }
        
        
    }


}
