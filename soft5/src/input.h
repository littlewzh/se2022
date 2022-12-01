
#ifndef MYINPUT
#define MYINPUT

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct comresult{
    string file1;
    string file2;
    int flag;
};

class MyIn
{
public:
    MyIn():pool(),ord(0){};
    void Add(const string &filename,int flag);
    struct comresult getone(int ord);
    void Print();
    int Size();
    int Ord();
    int Ordadd();
    int Orddown();
private:
    vector<struct comresult> pool;
    int ord;
};


#endif
