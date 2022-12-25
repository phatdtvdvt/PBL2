#ifndef Product_h
#define Product_h
#include <string>
using namespace std;

class Product{
    protected:
        //int N;// so mat hang hien co
        string ID;// Ma sp
        string NameProduct;// Ten sp
        int Sold;// So luong da ban
        int Quantity;// So luong con lai trong kho        
        long long Price;// Gia ban ra
        long long HistoricalCost;// Gia goc
        int Warranty; // Thoi luong bao hanh tinh theo don vi thang
    public:
        Product(){this->ID = "undefined";};
        Product(const Product &x);
        ~Product(){};
        string GetID();
        string GetName();
        int GetSold();
        int GetQuantity();
        long long GetPrice();
        long long GetHistoricalCost();
        int GetWarranty();
        void SetID(string x);
        void SetName(string x);
        void SetSold(int x);
        void SetQuantity(int x);
        void SetPrice(long long x);
        void SetHistoricalCost(long long x);
        void SetWarranty(int x);
        void InputPr(string x);
        friend ostream &operator << (ostream &os, const Product &a);
        void OutPutofCus();
};
#endif