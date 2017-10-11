#include "Datas.h"

Datas::Datas()
{
    d.clear();
}

Datas::Datas(string str) : s(str)
{
    translate();
}

void Datas::translate()
{
    unsigned int i;
    string ts = "";
    int tb = 0;

    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
         || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0' || s[i] == '.')
        {
            ts += s[i];
        } else

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back(s[i]);
        } else

        if (s[i] == 'x' || s[i] == 'X')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            Data *pd = new Data(s[i],s[i]);
            d.push_back(*pd);
        } else

        if (s[i] == '(')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            Data *pd = new Data(s[i],++tb);
            d.push_back(*pd);
            mb = (mb<tb) ? tb : mb;
        } else

        if (s[i] == ')')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            Data *pd = new Data(tb--, s[i]);
            d.push_back(*pd);
        } else

        if (s[i] == 's' && s[i+1] == 'i' && s[i+2] == 'n')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("sin");
            i+=2;
        } else

        if (s[i] == 'c' && s[i+1] == 'o' && s[i+2] == 's')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("cos");
            i+=2;
        } else

        if (s[i] == 't' && s[i+1] == 'g')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("tg");
            i++;
        } else

        if (s[i] == 'c' && s[i+1] == 't' && s[i+2] == 'g')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("ctg");
            i+=2;
        } else

        if (s[i] == 'a' && s[i+1] == 'r' && s[i+2] == 'c' && s[i+3] == 's' && s[i+4] == 'i' && s[i+5] == 'n')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("arcsin");
            i+=5;
        } else

        if (s[i] == 'a' && s[i+1] == 'r' && s[i+2] == 'c' && s[i+3] == 'c' && s[i+4] == 'o' && s[i+5] == 's')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("arccos");
            i+=5;
        } else

        if (s[i] == 'a' && s[i+1] == 'r' && s[i+2] == 'c' && s[i+3] == 't' && s[i+4] == 'g')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("arctg");
            i+=4;
        } else

        if (s[i] == 'a' && s[i+1] == 'r' && s[i+2] == 'c' && s[i+3] == 'c' && s[i+4] == 't' && s[i+5] == 'g')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("arcctg");
            i+=5;
        } else

        if (s[i] == 'l' && s[i+1] == 'o' && s[i+2] == 'g' && s[i+3] == '_')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            i+=4;
            unsigned int j;
            string tts;
            for (j = i; j < s.size() &&
                (s[j] == '1' || s[j] == '2' || s[j] == '3' || s[j] == '4' || s[j] == '5' || s[j] == '6' ||
                 s[j] == '7' || s[j] == '8' || s[j] == '9' || s[j] == '0' || s[j] == '.'); j++)
            {
                tts += s[j];
            }
            Data *pd = new Data("log", num(tts));
            d.push_back(*pd);
            i = j-1;
        } else

        if (s[i] == 'l' && s[i+1] == 'g')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            Data *pd = new Data("log", 10);
            d.push_back(*pd);
            i += 1;
        } else

        if (s[i] == 'l' && s[i+1] == 'n')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            Data *pd = new Data("log", 2.71828182845904523536);
            d.push_back(*pd);
            i += 1;
        } else

        if (s[i] == 's' && s[i+1] == 'r')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("sr");
            i += 1;
        } else

        if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 's')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back("abs");
            i += 2;
        } else

        if (s[i] == 'p' && s[i+1] == 'i')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back(3.14159265358979323846);
            i += 1;
        } else

        if (s[i] == 'e')
        {
            if (!(ts.empty()))
            {
                d.push_back(num(ts));
                ts.clear();
            }
            d.push_back(2.7182818284590452354);
        }
    }

    if (!(ts.empty()))
    {
        d.push_back(num(ts));
        ts.clear();
    }
}

double Datas::num(string ss)
{
    double r = 0;
    bool p = false;
    double pn = 0.0;
    for (unsigned int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '.')
        {
            p = true;
            pn = 0.1;
        } else
        if (ss[i] == '1' || ss[i] == '2' || ss[i] == '3' || ss[i] == '4' || ss[i] == '5'
         || ss[i] == '6' || ss[i] == '7' || ss[i] == '8' || ss[i] == '9' || ss[i] == '0')
        {
            if (!p)
                r = 10*r + num(ss[i]);
            else
            {
                r = r + num(ss[i])*pn;
                pn/=10;
            }
        }
    }
    return r;
}

double Datas::num(char tc)
{
    switch (tc)
    {
    case '0':
        return 0.0;
    case '1':
        return 1.0;
    case '2':
        return 2.0;
    case '3':
        return 3.0;
    case '4':
        return 4.0;
    case '5':
        return 5.0;
    case '6':
        return 6.0;
    case '7':
        return 7.0;
    case '8':
        return 8.0;
    case '9':
        return 9.0;
    default:
        return 0.0;
    }
}

double Datas::solve(double x)
{
    list<Data> td = d;
    list<Data>::iterator it, it1, it2, tit;
    int Mb = maxB((*this).D());

    for (it = td.begin(); it != td.end(); it++)
    {
        if ((*it).T() == 3)
        {
            Data tx(x);
            *it = tx;
        }
        /*else

        if ((*it).F() == "pi")
            it->sN(3.14159265358979323846);
        else

        if ((*it).F() == "e")
            it->sN(2.7182818284590452354);
        */
    }

    for (it = td.begin(); it != td.end(); it++)
    {
        list<Data>::iterator pre = it, next = it;
        if (it != td.begin())
            pre--;
        next++;

        if ((*it).S() == '-' && ((*pre).T() != 1 && (*pre).T() != 5) && (*next).T() == 1)
        {
            next->sN(-((*next).N()));
            pre = it;
            it = next;
            td.erase(pre);
        }
    }

    for (unsigned int ii = 0; ii < td.size()/2; ii++)
    {
        int ti = 0;
        for (it = td.begin(); it != td.end(); it++)
            if ((*it).T() == 4)
            {
                break;
                ti++;
            }
        if (ti != 0)
            goto AfterBrac;

        int tb = 0;
        for (it = td.begin(); it != td.end(); it++)
        {
            Data t = *it;
            tit = it;
            string func;
            list<Data>::iterator eit;
            eit = td.end();
            eit--;
            if (it != eit)
            {
                tit++;
                if ((*it).T() == 6 && (*tit).B() == Mb)
                {
                    it1 = it;
                    func = t.F();
                    tb = 1;
                }
            }
            if (it != eit)
            {
                //tit++;
                if ((*it).T() == 7 && (*tit).B() == Mb)
                {
                    it1 = it;
                    func = t.F();
                    tb = 2;
                }
            }

            if (t.T() == 5 && t.B() == Mb && tb)
            {
                if (tb == 1)
                {
                    it2 = it;
                    it1++; it1++;
                    Data dr = solveGroup(td,it1,it2);
                    it1--;
                    *it1 = dr;
                    td.erase(++it1, it2);
                    it--;
                    td.erase(it2);
                    it2 = it;
                    it--;
                    it1 = it;
                    it1++;
                    if ((*it).F() == "sin")
                        it->sN(sin((*it1).N())); else
                    if ((*it).F() == "cos")
                        it->sN(cos((*it1).N())); else
                    if ((*it).F() == "tg")
                        it->sN(tan((*it1).N())); else
                    if ((*it).F() == "ctg")
                        it->sN(3.141592654/2-(tan((*it1).N()))); else
                    if ((*it).F() == "arcsin")
                        it->sN(asin((*it1).N())); else
                    if ((*it).F() == "arccos")
                        it->sN(acos((*it1).N())); else
                    if ((*it).F() == "arctg")
                        it->sN(atan((*it1).N())); else
                    if ((*it).F() == "arcctg")
                        it->sN(3.141592654/2-(atan((*it1).N()))); else
                    if ((*it).F() == "sr")
                        it->sN(sqrt((*it1).N())); else
                    if ((*it).F() == "abs")
                            it->sN(absolute((*it1).N()));

                    td.erase(it2);
                    it1 = it;
                    it2 = it;
                    td.push_back(*(new Data));
                }
                if (tb == 2)
                {
                    it2 = it;
                    it1++; it1++;
                    Data dr = solveGroup(td,it1,it2);
                    it1--;
                    *it1 = dr;
                    td.erase(++it1, it2);
                    it--;
                    td.erase(it2);
                    it2 = it;
                    it--;
                    it1 = it;
                    it1++;
                    it->sN(log((*it1).N())/log((*it).N()));

                    td.erase(it2);
                    it1 = it;
                    it2 = it;
                    td.push_back(*(new Data));
                }
            }
        }

        bool it1b = false;
        for (it = td.begin(); it != td.end(); it++)
        {
            bool nf = false;
            Data t = *it;
            list<Data>::iterator titt = it;
            if (it != td.begin())
            {
                --titt;
                if ((*titt).T() == 6)
                    nf = false;
                else
                    nf = true;
            }
            else
                nf = true;

            if (t.T() == 4 && t.B() == Mb && nf)
            {
                it1 = it;
                it1b = true;
            }
            if (t.T() == 5 && t.B() == Mb && it1b)
            {
                it2 = it;
                it1++;
                Data dr = solveGroup(td,it1,it2);
                it1--;
                *it1 = dr;
                td.erase(++it1, it2);
                it--;
                td.erase(it2);
                it1 = it;
                it2 = it;
            }
        }

        int tMb = maxB(td);
        if (Mb > tMb)
        {
            Mb = tMb;
            it = td.begin();
        }
    }
    AfterBrac:
    Data r;
    if (td.size() == 1)
        r = (*td.begin()).N(); else
    if (td.size()>1)
        r = solveGroup(td,td.begin(),td.end());

    return r.N();
}

Data Datas::solveGroup(list<Data> l, list<Data>::iterator it1, list<Data>::iterator it2)
{
    Data r = 0;
    list<Data> li;
    list<Data>::iterator lit;
    list<Data>::iterator iit;

    for (iit = it1; iit != it2; iit++)
        li.push_back(*iit);

    for (unsigned int i = 0; i <= li.size()/2; i++)
        for (lit = li.begin(); lit != li.end() ; lit++)
            if ((*lit).T() == 2 && (*lit).S() == '^')
            {
                list<Data>::iterator lit1 = lit, lit2 = lit;
                lit1--; lit2++;
                *lit1 = std::pow((*lit1).N(), (*lit2).N());
                lit1++; lit--;
                li.erase(lit1,lit2);
                li.erase(lit2);
            }

    for (unsigned int i = 0; i <= li.size()/2; i++)
        for (lit = li.begin(); lit != li.end() ; lit++)
            if ((*lit).T() == 2 && ((*lit).S() == '*' || (*lit).S() == '/'))
            {
                list<Data>::iterator lit1 = lit, lit2 = lit;
                lit1--; lit2++;
                *lit1 = ((*lit).S() == '*') ? ((*lit1).N()*(*lit2).N()) : ((*lit1).N()/(*lit2).N());
                lit1++; lit--;
                li.erase(lit1,lit2);
                li.erase(lit2);
            }

    for (unsigned int i = 0; i <= li.size()/2; i++)
        for (lit = li.begin(); lit != li.end() ; lit++)
            if ((*lit).T() == 2 && ((*lit).S() == '+' || (*lit).S() == '-'))
            {
                list<Data>::iterator lit1 = lit, lit2 = lit;
                lit1--; lit2++;
                *lit1 = ((*lit).S() == '+') ? ((*lit1).N()+(*lit2).N()) : ((*lit1).N()-(*lit2).N());
                lit1++; lit--;
                li.erase(lit1,lit2);
                li.erase(lit2);
            }

    r = *(li.begin());
    return r;
}

int Datas::maxB(list<Data> l)
{
    int mB = 0;
    list<Data>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
        mB = (mB >= (*it).B()) ? mB : (*it).B();

    return mB;
}

void Datas::sMB(int i)
{
    mb = i;
}

list<Data> Datas::D()
{
    return d;
}

point::point() : x(0), y(0)
{
}

point::point(double tx, double ty) : x(tx), y(ty)
{
}

void point::S(double tx, double ty)
{
    x = tx;
    y = ty;
}

double point::Gx()
{
    return x;
}

double point::Gy()
{
    return y;
}

double Datas::absolute(double d)
{
    if (d >= 0)
        return d;
    else
        return -d;
}
