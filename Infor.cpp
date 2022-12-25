#include"Infor.h"
#include<iostream>
using namespace std;
Infor::Infor(){	
	ID="Undefined";
	Quantity=0;
	Price=0;
	//Bill=0;
};
Infor::Infor(string id,int q, int p, string addr ,string f){
	ID = id;
	Quantity = q;
	Price = p;
	Address = addr;
	form = f;
};
Infor::~Infor(){
};
ostream &operator<<(ostream &out,Infor &x){
	cout<<x.ID<<" || "<<x.Quantity<<" || "<<x.Price<<endl;
	return out;
}
void Infor::set_infor(string id,int q, int p){
	ID=id;
	Quantity=q;
	Price=p;
};
string Infor::getID(){
	return ID;
};
int Infor::getQuantity(){
	return Quantity;
};
int Infor::getPrice(){
	return Price;
};
string Infor:: getForm(){
	return form;
}
void Infor::setForm(string x){
	this->form = x;
}
void Infor::setAddress(string x){
	this->Address = x;
};
string Infor:: getAddress() {
	return Address;
};