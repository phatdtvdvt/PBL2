#include<iostream>
#include <string>
#include <iomanip>
#include "Product.h"
#include "Date.h"
#include "Revenue.h"
using namespace std;

Revenue :: Revenue(){

}
Revenue ::~Revenue(){

}
Revenue :: Revenue(string x, string y, int z, long long h, long long l, Date k, int t){
    this->Phone = x;
    this->ID = y;
    this->NumOfAPro = z;
    this->Price = h;
    this->HistoricalCost = l;
    this->Day = k;
    this->Warranty =t;
}
void Revenue ::SetPhone(string x){
    this->Phone = x;
}
void Revenue ::SetNumOfAPro(int x){
    this->NumOfAPro =x;
}
void Revenue ::SetDay(Date x){
    this->Day = x;
}
string Revenue :: GetPhone(){
    return this->Phone;
}
int Revenue :: GetNumOfAPro(){
    return this->NumOfAPro;
}
Date Revenue :: GetDay(){
    return this->Day;
}
string Revenue :: GetDay1(){
    return this->Day.SetDayFromNum();
}
void Revenue ::OutPutOfRevenue(){
    cout << "\t\t"; for(int i = 1; i < 49; i++) cout << (char) 196;
    cout <<  endl;
    cout << "\t\t" << (char) 179 << setw(12) << this->ID << " " << (char) 179 << setw(3) << this->NumOfAPro << " " << (char) 179 << setw(12) << this->Price << " " << (char) 179 << setw(12) << this->HistoricalCost << " " << (char) 179 << endl;
    cout << "\t\t"; for(int i = 1; i < 49; i++) cout << (char) 196;
    cout <<  endl;
}
ostream &operator <<(ostream &os, const Revenue &s1){
    cout << setw(20) << (char)186 << setw(12) << s1.Phone << " " << (char)186 << setw(12) << s1.ID << " " << (char)186 << setw(3) << s1.NumOfAPro << " " << (char)186 << setw(14) << s1.Price << " " << (char)186 << setw(14) << s1.HistoricalCost << " " << (char)186 << setw(9) << s1.Day <<" "<< (char)186 << setw(5) << s1.Warranty <<" " <<(char)186 << endl;
    cout << setw(18); 
    for(int i = 1; i < 96; i++) cout << (char) 196; 
    cout <<  endl;
}