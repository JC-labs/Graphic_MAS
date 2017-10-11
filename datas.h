#ifndef DATAS_H
#define DATAS_H

#include "Data.h"

class Datas
{
private:
    list<Data> d;
    string s;
    int mb;

    double num(string);
    double num(char);

    Data solveGroup(list<Data>, list<Data>::iterator, list<Data>::iterator);
    int maxB(list<Data> l);
    void sMB(int);
    double absolute(double d);

public:
    Datas();
    Datas(string);

    double solve(double x);
    void translate();

    list<Data> D();
};

class point
{
public:
    point();
    point(double tx, double ty);

    double x;
    double y;

    void S(double tx, double ty);
    double Gx();
    double Gy();
};

#endif // DATAS_H
