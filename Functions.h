#ifndef Functions_h
#define Functions_h

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

class Functions{
    public:
        Functions();
        ~Functions();
        void Revenue_Management();
        void Feature_Sell();
        List ProductFilter();
        void Feature_SellOfCus(List &a);
        void PurchaseHistory();
};
#endif