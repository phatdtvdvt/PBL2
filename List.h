#ifndef List_h
#define List_h

#include<iostream>
#include<string>
#include "ListOfRevenue.h"
#include "Linkedlist.h"
#include "Node.h"
#include "Product.h"
#include "Date.h"
using namespace std;
class List: public Linkedlist<Product>{
    private:
        int N;
    public:
        List();
        ~List(){};
        void ReadFromFile();
        void SaveToFile();

        Product SearchByID(string x);
        List SearchByName(string x);

        void ChangeTheQuantity(string x);
        void ChangeThePrice(string x);
        void ChangeTheSold(string x);
        void ChangeTheHistoricalCost(string x);
        void ChangeTheName(string x);
        void InportNewProduct(); // Them sp moi bang cach nhap tu ban phim
        void operator+(Product x);
        void DeleteProduct(string x);

        void PrintBill(Date day, string ten, string sdt, string diachi, string form);

        void OutPut();
        void OutPutOfCus();

        friend int recsnum();
        friend bool CheckID(string X, List a);

        List SortByBestSelling();
        List FilterByPrice();
        List SearchByPrice(char, long long);

        friend string ID(int i);

        friend class ListOfRevenue;
        friend class LisCus;
        friend class LinkedlistCus;
        friend class Customer;
        friend class Functions;
};
#endif