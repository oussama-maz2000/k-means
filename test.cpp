#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Point
{
    double x,y;
    int cluster;
    double minimal_destance;

Point():
x(0.0),
y(0.0),
cluster(2),
minimal_destance(__DBL_MAX__) // maximum double value
{}

Point (double x ,double y):
x(x),
y(y),
cluster(2),
minimal_destance(__DBL_MAX__){}


double distance(Point n){
    return (n.x -x)*(n.x -x) + (n.y - y)*(n.y - y);
}
};

bool getFileContent(string fileName,vector<string> & vecOfStrs){
    ifstream in(fileName.c_str());
    if (!in) {
        cout << "Cannot open file " << fileName << std::endl;
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
            cout<<vecOfStr[i]<<endl;
            
        }
        
        
    }


}
