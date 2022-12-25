#include"Customer.h"
#include<iostream>
#include<fstream>
using namespace std;
Customer::Customer(){
	
};
Customer::~Customer(){
	
};
ostream &operator<<(ostream &out,Customer &x){
	cout << x.Name << "||" << x.PhoneNumber << endl;
	cout<<"Purchase history: "<<endl;
	x.goods.Display();
	return out;
};
Customer::Customer(string name, string phone,Infor x){
	Name=name;
	PhoneNumber=phone;
	goods.InsertNode(x);
};	

const Customer &Customer::operator = (const Customer &x){
	Name=x.Name;
	PhoneNumber=x.PhoneNumber;
	goods=x.goods;
}
Linkedlist<Infor> Customer:: getGoods(){
	return goods;
};
