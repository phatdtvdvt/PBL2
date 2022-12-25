#ifndef ListOfRevenue_h
#define ListOfRevenue_h

#include <iostream>
#include <string>
#include "List.h"
#include "Linkedlist.h"
#include "Product.h"
#include "Revenue.h"
#include "Date.h"
using namespace std;
class ListOfRevenue: public Linkedlist<Revenue>{
    public:
        ListOfRevenue();
        ~ListOfRevenue();
        void ReadFromFile();
        void SaveToFile();
        void operator+(Revenue x);
        int WarrantyLookup(string, string);
        void RevenueOfDay(Date &a);

        ListOfRevenue FindListByMonth(int x, int y);
        void QuantityStatistics();
        long long RevenueOfMonth(int x, int y, int k);

        void RenvenueOfYear(int y);

        //feature:
        void WarrLookup();
        friend class List;
        friend class Linkedlist;
        friend class Function;
};
#endif