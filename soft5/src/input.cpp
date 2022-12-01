#include "input.h"
#include <fstream>
#include <sstream>
using namespace std;
int MyIn::Size(){
    return pool.size();
}
void MyIn::Add(const string &filename,int flag){
    ifstream srcfile(filename.c_str(),ios::in);
    if(!srcfile){
        cerr <<"\033[41;1mError message :\033[0m  fail to open file " <<filename<< endl<<endl;
        //exit(1);
        return;
    }
    string line;
    getline(srcfile,line);
    while(getline(srcfile,line)){
        struct comresult tmp;

        istringstream sin(line);
        getline(sin,tmp.file1,',');
        getline(sin,tmp.file2);
        tmp.flag=flag;
        pool.push_back(tmp);
    }

}
void MyIn::Print(){
    vector<struct comresult>::iterator it;
    for(it = pool.begin();it!=pool.end();it++){
        cout<<it->file1<<"  "<<it->file2<<"  "<<it->flag<<endl;
    }
}
struct comresult MyIn::getone(int ord){
    return pool[ord];
}
int MyIn::Ord()
{
    return ord;
}
int MyIn::Ordadd(){
    ord++;
    return ord;
}
int MyIn::Orddown(){
    ord--;
    return ord;
}
