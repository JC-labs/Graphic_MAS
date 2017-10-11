#ifndef DATA_H
#define DATA_H

#include <fstream>
#include <ctime>
using namespace std;

#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>

class Data
{
private:
    int    t;
    double n;
    char   s;
    int    b;
    string f;

public:
    Data();
    Data(int);
    Data(double);
    Data(char);
    Data(char, char);
    Data(char, int);
    Data(int, char);
    Data(string);
    Data(char*);
    Data(string, double);
    Data(char*, double);

    int    T();
    int    B();
    double N();
    char   S();
    string F();
    void sN(double);
    void sS(char);
    void sF(string);
};

#endif // DATA_H
