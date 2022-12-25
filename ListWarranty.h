#ifndef ListWarranty_h
#define ListWarranty_h

#include <iostream>
#include <string>
#include "List.h"
#include "Linkedlist.h"
#include "WarrantyStatus.h"
#include "Date.h"
using namespace std;
class ListWarranty: public Linkedlist<WarrantyStatus>{
    private:
        int N;
    public:
        ListWarranty();
        ~ListWarranty();
        void ReadFromFile();
        void SaveToFile();
        void operator+(WarrantyStatus x);

        friend class List;
        friend class Linkedlist;
        friend class Staff;
};
#endif