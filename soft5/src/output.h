#ifndef OUTPUT_H
#define OUTPUT_H
#include <map>
#include "main.h"
using namespace std;
struct out{
    string file1;
    string file2;
    bool operator<(const struct out& n)const{
        if(file1!=n.file1)
            return file1<n.file1;
        else
            return file2<n.file2;
    }
};

class MyOu
{
public:
    MyOu(string s1="equal.csv",string s2="inequal.csv",string s3="abnormal.csv")
       :eq(PWDPATH+s1),neq(PWDPATH+s2),abn(PWDPATH+s3)
       {mm.clear();}
       //~MyOut();
       void Add(string f1,string f2,int t);
       void Print();
private:
    map<struct out,int > mm;
    int number=0;
    string eq;
    string neq;
    string abn;
};
#endif // OUTPUT_H
