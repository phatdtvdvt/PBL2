#ifndef Date_h
#define Date_h
#include <iostream>
using namespace std;
class Date{
    public:
        int D,M,Y;
    public:
        Date();
        ~Date();
        void today();
        Date SetDayFromStr(string x);
        string SetDayFromNum();
        friend istream &operator >>(istream &is, Date &s1);
        friend ostream &operator <<(ostream &os, const Date &s1);
        bool operator ==(const Date &s1);
        bool operator > (const Date &s1);
        Date operator+(int Month);
};
#endif