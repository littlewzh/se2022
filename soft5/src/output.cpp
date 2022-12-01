#include "output.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <QFile>
void MyOu::Add(string f1,string f2,int t){
    struct out tmp;
    tmp.file1 = f1;
    tmp.file2 = f2;
    mm[tmp]=t;
    number++;
}
void MyOu::Print(){
   /* if(mm.empty()){cout<<"the result is empty"<<endl;}
    for(auto k=mm.begin();k!=mm.end();k++){
        cout<<k->first.file1<<"  "<<k->first.file2<<endl;
    }
    QFile file1(QString::fromStdString(eq));
    if(!file1.open(QFile::WriteOnly)){
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return ;
    }
    QFile file2(QString::fromStdString(neq));
    if(!file2.open(QFile::WriteOnly)){
        file1.close();
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return ;
    }
    QFile file3(QString::fromStdString(abn));
    if(!file3.open(QFile::WriteOnly)){
        file1.close();
        file2.close();
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return ;
    }
    file1.write("file1,file2\n");
    file2.write("file1,file2\n");
    file3.write("file1\n");
    auto it = mm.begin();
    while(it != mm.end()){
        if(it->second == 1){
            file1.write((it->first.file1+","+it->first.file2+"\n").c_str());
            //file1<<it->first.file1<<","<<it->first.file2<<endl;
        }else if(it->second == 0){
            file2.write((it->first.file1+","+it->first.file2+"\n").c_str());
            //file2<<it->first.file1<<","<<it->first.file2<<endl;
        }else if(it->second == -1){
            //file3<<it->first.file1<<endl;
        }
        it++;
    }*/
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
       auto it = mm.begin();
       while(it != mm.end()){
           if(it->second == 1){
               file1<<it->first.file1<<","<<it->first.file2<<endl;
           }else if(it->second == 0){
               file2<<it->first.file1<<","<<it->first.file2<<endl;

           }else if(it->second == -1){
               //file3<<it->file1<<endl;
           }
           it++;
       }
    file1.close();
    file2.close();
    file3.close();
    cout<<"\033[42;1mFinish :\033[0m  successful write the result to "<<eq<<" "<<neq<<" "<<abn<<endl<<endl;
}
