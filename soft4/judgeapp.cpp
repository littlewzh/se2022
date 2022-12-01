#include "a.h"
#include "b.h"
#include "c.h"

static string *Generatestdin(MyDir &d, int num){
    string path = d.dirname()+"/";
    string *s = new string[num];
    //char **s = new char* [num];
    string fex = ".txt";
    for(int i=0;i<num;i++){
        //s[i] = new char[96];
        s[i] = path+to_string(i+1)+fex;
        //strcpy(s[i],(path+to_string(i+1)+fex).c_str());
        d.generatestdin(s[i].c_str());
    }
    return s;
}

static void Equal(MyDir &d,MyOut &o,string *s,int num){
    string path = d.dirname()+"/";
    int m = d.number();
    MyProgram *prog[m];
    for(int i=0;i<m;i++){
        string tmp = d.getfile(i);
        const char* tmps = tmp.substr(0,tmp.length()-4).c_str();
        prog[i] = new MyProgram(tmps,d.dirname().c_str());
        //prog[i]->Numinput(s[0]);
    }
    for(int i=0;i<m;i++){
        /*
        if(prog[i]->input_num!= d.Stdin_num()){
            o.Add((path+prog[i]->Name()).c_str(),(path+prog[i]->Name()).c_str(),-1);
            cout<<"\033[44;1mResult :\033[0m  "<<prog[i]->Name()<<"  \033[32;1m不正常\033[0m"<<endl<<endl;
            continue;
        }*/
        for(int j=i+1;j<m;j++){
            int result=isequal(*prog[i],*prog[j],(const string *)s,num);
            o.Add((path+prog[i]->Name()).c_str(),(path+prog[j]->Name()).c_str(),result);
        }
    }
    for(int i=0;i<m;i++){
        delete prog[i];
    }
    //delete[] prog;
}
int main(int argc, char *argv[]){
    if(argc < 2){
        cerr << "\033[41;1mError message :\033[0m the input format is ./a.out dirs" << endl<<endl;
        exit(1);
    }
    int n = argc-1;
    int num=10;
    MyDir dir[n];             //定义输入的文件夹类
    for (int i=0;i<n;i++){
        dir[i] = MyDir(argv[i+1]);
    }
    
    string *s[n];            //为每个文件夹生成对应的stdin
    for (int i=0;i<n;i++){
        s[i] = Generatestdin(dir[i],num);
    }

    MyOut Re;                //生成输出类

    for (int i=0;i<n;i++){   //每个文件夹内进行比较
        Equal(dir[i],Re,s[i],num);
    }

    cout<<"\033[1;42mFinish :\033[0m  successful to complete all compare"<<endl<<endl;
    Re.Print();
    
    for(int i=0;i<n;i++){
        delete[] s[i];
    }
    //int result = isequal(p1,p2,(const char **)s,n);
    return 0;
}

