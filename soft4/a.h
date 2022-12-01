#ifndef __MYDIR__
#define __MYDIR__


#include <iostream>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <random>
using namespace std;
int selectfile(const struct dirent *dir){
    int len = strlen(dir->d_name);
    for(int i=0;i<len-1;i++){
        if(dir->d_name[i] == '.'&&dir->d_name[i+1] == 'c'){
            return 1;
        }
    }
    return 0;
}

string strRand(int length) {			
    int tmp;							
    string buffer;						
    // 下面这两行比较重要:    
    for (int i = 0; i < length; i++) {
        tmp = random() % 52;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 26) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += 'a';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 26;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}

class MyDir
{
public:
     MyDir():name("undefine"){};
     MyDir(const char *s,const char *s2 = "stdin_format.txt"){
        name = s;
        this->read_dir(name);
        //numfile = scandir(("./"+name).c_str(),&files,selectfile,alphasort);
        Stdinformat = name+"/"+s2;
        srand((unsigned)time(NULL));
        cout<<"\033[1;42mFinish :\033[0m  successful to create MyDir  "<<name<<endl<<endl;
     }
     //~MyDir();
     void read_dir(string fileDir);
     const char* getfile(int ord){  return files[ord].c_str(); }
     void generatestdin(const char *output);
     string dirname(){  return name; }
     int number(){  return numfile; }
     int Stdin_num(){return stdin_num;}
     MyDir& operator = (const MyDir& src);

private:
    string name;
    vector<string> files;
    int numfile=0;
    string Stdinformat;
    int stdin_num;
};
inline MyDir& MyDir::operator = (const MyDir& src){
    if(this == &src)
        return *this;
    this->name        = src.name;
    this->files       = src.files;
    this->numfile     = src.numfile;
    this->Stdinformat = src.Stdinformat;
    return *this;
}

inline void MyDir::read_dir(string fileDir){
    struct dirent *ent = NULL;
    DIR *dir = opendir(fileDir.c_str());
    if(dir!=NULL){
        while((ent = readdir(dir))!=NULL){
            int f=selectfile(ent);
            if(f){
                string tmp = ent->d_name;
                files.push_back(tmp);
                numfile++;
            }
        }
    }
}
void MyDir::generatestdin(const char *output){
    ifstream srcfile(Stdinformat.c_str(),ios::in);
    if(!srcfile){
        cerr <<"\033[41;1mError message :\033[0m  fail to open stdinformat file" << endl<<endl;
        return ; 
    }
    ofstream destfile(output,ios::out);
    if(!destfile){
        srcfile.close();
        cerr <<"\033[41;1mError message :\033[0m  fail to touch output file" << endl<<endl;
        return ; 
    }
    char li[1024];
    string line;
    string subline;

    //srand((unsigned)time(NULL));
    int nn=0;
    while(srcfile.getline(li,1024)){
        line = li;
        int start=0;
        for(int i=0;i<=(int)line.length();i++){
            if(line[i] == ' ' || i == (int)line.length()){
                subline=line.substr(start,i-start);
                start=i+1;
                if(subline.compare(0,3,"int")==0){
                    int mid = subline.find(',');
                    int a = atoi(subline.substr(4,mid-4).c_str());
                    int b = atoi(subline.substr(mid+1,subline.length()-(mid+1)).c_str());
                    int c = (random()%(b-a+1))+a;
                    destfile << c <<" ";
                    nn++;

                }else if(subline=="char"){
                    string c = strRand(1); 
                    destfile << c <<" ";
                    nn++;
                }else{
                    int mid = subline.find(',');
                    int a = atoi(subline.substr(7,mid-7).c_str());
                    int b = atoi(subline.substr(mid+1,subline.length()-(mid+1)).c_str());
                    string c=strRand(b-a+1);
                    destfile << c <<" ";
                    nn++;
                }
            }
        }
        destfile <<endl;
    }
    stdin_num = nn;
    cout<<"\033[1;42mFinish :\033[0m  successful to generate "<<output<<endl<<endl;
    destfile.close();
    srcfile.close();
    return ;
}

#endif
