#include<iostream>
#include <string>
#include "Product.h"
#include<iomanip>
using namespace std;

Product ::Product(const Product &x){
    this -> ID = x.ID;
    this -> NameProduct = x.NameProduct;
    this -> Quantity = x.Quantity;
    this -> Sold = x.Sold;
    this -> Price = x.Price;
    this -> HistoricalCost = x.HistoricalCost;
    this -> Warranty = x.Warranty;
}
string Product ::GetID(){
	return ID;
}
string Product ::GetName(){
	return NameProduct;
}
int Product :: GetSold(){
	return this->Sold;
}
int Product ::GetQuantity(){
	return this->Quantity;
}
long long Product :: GetPrice(){
	return this ->Price;
}
long long Product :: GetHistoricalCost(){
	return this->HistoricalCost;
}
int Product :: GetWarranty(){
	return this->Warranty;
}
void Product :: SetID(string x){
	this->ID = x;
}
void Product ::SetName(string x){
	this->NameProduct = x;
}
void Product ::SetSold(int x){
	this->Sold = x;
}
void Product ::SetQuantity(int x){
	this->Quantity = x;
}
void Product ::SetPrice(long long x){
	this->Price = x;
}
void Product ::SetHistoricalCost(long long x){
	this->HistoricalCost = x;
}
void Product ::SetWarranty(int x){
	this->Warranty = x;
}
void Product :: InputPr(string x){
	// cout << "\n\t\t\t\tAdd new items" << endl;
	// cout << "\t\t\t\t	- ID: "; cin >> this->ID; getchar();
	this->ID = x;
	cout << "\t\t\t\t	- Name: "; getline(cin, this->NameProduct);
	this->Sold = 0;
	cout << "\t\t\t\t	- Quantity: "; cin >> this->Quantity;
	cout << "\t\t\t\t	- Price: "; cin >> this->Price;
	cout << "\t\t\t\t	- HistoricalCost: "; cin >> this->HistoricalCost;
	cout << "\t\t\t\t	- Warranty: "; cin >> this->Warranty;
	cout << "\t\t\t\t------------------------------------------------" << endl;
}
void Product ::OutPutofCus(){
	cout << "\n" << this->ID << "  " <<" | " << "  " << setw(45) << left << this->NameProduct  << setw(3) << left << " | " << setw(3) << left << this->Sold  << " | " << "		" << " | "  <<  setw(3) << left << this->Quantity << " | " << "	" << " | " <<  setw(8) << left << this->Price << setw(5) << " | " <<"   | " << setw(3) << left  << this->Warranty << " | " << endl;
	cout << "___________________________________________________________________________________________________________________________________________" << endl;
}
ostream &operator << (ostream &os, const Product &a){
    cout << "\n" << a.ID << "  " <<" | " << "  " << setw(45) << left << a.NameProduct  << setw(3) << left << " | " << setw(3) << left << a.Sold  << " | " << "		" << " | "  <<  setw(3) << left << a.Quantity << " | " << "	" << " | " <<  setw(8) << left << a.Price << setw(5) << " | " << "  |  "<<  setw(8) << left << a.HistoricalCost << setw(4) << " | " <<"   | " << setw(3) << left  << a.Warranty << " | " << endl;
	cout << "___________________________________________________________________________________________________________________________________________" << endl;
}


