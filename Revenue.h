#ifndef Revenue_h
#define Revenue_h
#include <iostream>
#include "Product.h"
#include "Date.h"
using namespace std;
class Revenue: public Product{
    public:
        string Phone;
        int NumOfAPro;
        Date Day;
    public:
        Revenue();
        ~Revenue();
        Revenue (string, string, int, long long,long long, Date, int);
        void SetPhone(string x);
        void SetNumOfAPro(int x);
        void SetDay(Date x);
        string GetPhone();
        int GetNumOfAPro();
        Date GetDay();
        string GetDay1();
        void OutPutOfRevenue();
        friend ostream &operator <<(ostream &os, const Revenue &s1);
        void InputOfRevenue(string x);
};
#endif