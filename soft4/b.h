#ifndef __MYPROGRAM__
#define __MYPROGRAM__

#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;



//string CFLAGS = "-w";
class MyProgram
{
public:
    MyProgram():name("undefine"){};
    MyProgram(const char* s,const char* p="files/",const char* i="input.txt") :name(s),path(p),input(i){
        //string tmp = p;
        //path = "./" + tmp +"/";
        if(path[path.length()-1]!='/') path+="/";
        system(("g++ "+path+name+".cpp -w -o "+path+name).c_str());
        cout<<"\033[1;42mFinish :\033[0m  successful to create Program "<<path+name<<endl<<endl;
    };
    //~MyProgram();
    void Inputchange(const char *name){input = name;};
    void Run(const char* output);
    string Name() const {return name;}
    void Numinput(const string& in){
        system(("./test.sh "+path+name+" "+in+" >log.txt").c_str());
        ifstream file1("log.txt",ios::in);
        if(!file1){
            cerr <<"\033[41;1mError message :\033[0m fail to open log.txt" << endl<<endl;
            return ; 
        }
        int n;
        file1>>n;
        input_num=n;
        file1.close();
        //return n;
    }
    friend int Compare(const char* , MyProgram&, MyProgram&);

    MyProgram& operator = (const MyProgram& src);
    int input_num=0;
private:
    
    string name;
    //int type=0;
    string path;
    string input;
    string output;
    
};

inline MyProgram& MyProgram::operator=(const MyProgram& src){
    if(this == &src)
        return *this;
    this->name   = src.name;
    this->path   = src.path;
    this->input  = src.input;
    this->output = src.output;
    return *this;
}
inline void MyProgram::Run(const char* out){
    if(input == ""){
        cerr <<"\033[41;1mError message :\033[0m don't specify input file" << endl<<endl;
    }
    output = out;
    system(("touch "+path+output).c_str());
    system((path+name+" <"+input+" >"+path+output+" 2>>errlog.txt").c_str());
}
inline int Compare(const char* in, MyProgram& a, MyProgram& b){
    a.Inputchange(in);
    b.Inputchange(in);
    a.Run((a.name+".txt").c_str());
    b.Run((b.name+".txt").c_str());
    ifstream file1((a.path+a.output).c_str(),ios::in);
    if(!file1){
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return 0; 
    }
    
    ifstream file2((b.path+b.output).c_str(),ios::in);
    if(!file2){
        file1.close();
        cerr <<"\033[41;1mError message :\033[0m fail to open file1" << endl<<endl;
        return 0; 
    }
    string line;
    string s1;
    string s2;
    while(file1>>line){
        s1+=line;
    }
    while(file2>>line){
        s2+=line;
    }
    file1.close();
    file2.close();
    if(s1==s2) return 1;
    else return 0;
}
int isequal(MyProgram& a, MyProgram& b,const string *s,const int n){
    int flag=1;
    if(a.input_num != b.input_num){
        //flag = 0;
        //cout<<"\033[44;1mResult :\033[0m  "<<a.Name()<<"  "<<b.Name()<<"  \033[31;1m不等价\033[0m-"<<"输入个数不同-"<<a.input_num<<" "<<b.input_num<<endl<<endl;
    }else{
        for (int i=0;i<n;i++){
            if(Compare(s[i].c_str(),a,b)==0){
                flag = 0;
                cout<<"\033[44;1mResult :\033[0m  "<<a.Name()<<"  "<<b.Name()<<"  \033[31;1m不等价\033[0m-"<<s[i]<<endl<<endl;
                break;
            }else{
                //cout<<"\033[42;1mResult :\033[0m  "<<s[i]<<"相同"<<endl<<endl;
            }
        }
    }
    
    if(flag == 1){
        cout<<"\033[44;1mResult :\033[0m  "<<a.Name()<<"  "<<b.Name()<<"  \033[32;1m等价\033[0m"<<endl<<endl;
    }
    return flag;

}




#endif
