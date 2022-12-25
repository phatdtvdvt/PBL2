#include"Person.h"
#include<string>
//#include<iostream>
using namespace std;
//Person::Person(string a,string b,string c){
//	Name=a;
//	Address=b;
//	PhoneNumber=c;
//};
Person::Person(){
	Name="undefined";
	//Address="undefined";
	PhoneNumber="undefined";
}
Person::~Person(){};
//Person::Person(const Person &x):Name(x.Name),Address(x.Address),PhoneNumber(x.PhoneNumber){
//};
void Person:: setName(string a){
	fflush(stdin); getline(cin,Name);
};
string Person:: getName() {
	return Name;
};
// void Person::setAddress(string b){
// 	//fflush(stdin); getline(cin,Address);
// 	this->Address = b;
// };
// string Person:: getAddress() {
// 	return Address;
// };
void Person::setPhone(string x){
	fflush(stdin); getline(cin,PhoneNumber);
};
string Person::getPhone() {
	return PhoneNumber;
};
void Person::setPerson(){
	cout<<"Input Name: "; fflush(stdin); getline(cin,Name);
    //cout<<"Input Address:"; fflush(stdin); getline(cin,Address);
    cout<<"Input Phone: "; fflush(stdin); getline(cin,PhoneNumber);
}

ostream &operator<<(ostream &out,Person &x){
	out<<x.getName();
	cout<<endl;
	// out<<x.getAddress();
	// cout<<endl;
	out<<x.getPhone();
	cout<<endl;
	return out;
};
