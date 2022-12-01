#ifndef __MYOUT__
#define __MYOUT__
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct comresult{
    string file1;
    string file2;
    int flag;
};


class MyOut
{
public:
    MyOut(const char* s1="equal.csv",const char* s2="inequal.csv",const char* s3="abnormal.csv")
    :eq(s1),neq(s2),abn(s3)
    {Result.clear();}
    //~MyOut();
    void Add(const char* f1,const char* f2,int t);
    void Print();

private:
    vector <struct comresult> Result;
    int number=0;
    string eq;
    string neq;
    string abn;
};
void MyOut::Add(const char* f1,const char* f2,int t){
    struct comresult tmp;
    tmp.file1 = f1;
    tmp.file2 = f2;
    tmp.flag  = t;
    Result.push_back(tmp);
    number++;
}
void MyOut::Print(){
    ofstream file1(eq.c_str(),ios::out);
    if(!file1){
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return ; 
    }
    ofstream file2(neq.c_str(),ios::out);
    if(!file2){
        file1.close();
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return ; 
    }
    ofstream file3(abn.c_str(),ios::out);
    if(!file3){
        file1.close();
        file2.close();
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return ; 
    }
    file1<<"file1,file2"<<endl;
    file2<<"file1,file2"<<endl;
    file3<<"file"<<endl;
    vector<struct comresult>::iterator it = Result.begin();
    while(it != Result.end()){
        if(it->flag == 1){
            file1<<it->file1<<","<<it->file2<<endl;
        }else if(it->flag == 0){
            file2<<it->file1<<","<<it->file2<<endl;
        }else if(it->flag == -1){
            file3<<it->file1<<endl;
        }
        it++;
    }
    file1.close();
    file2.close();
    file3.close();
    cout<<"\033[42;1mFinish :\033[0m  successful write the result to "<<eq<<" "<<neq<<" "<<abn<<endl<<endl;
}




#endif