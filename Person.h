#ifndef Person_h 
#define Person_h
#include<iostream>
#include<string>
using namespace std;
class Person{
	protected:
		string Name;
		
		string PhoneNumber;
	public:
		Person();
		//Person(string a="Undefined",string b="Undefined",string c="Undefined");
		~Person();
//		Person(const Person &);
		void setName(string x);
		string getName() ;
		//void setAddress(string x);
		//string getAddress() ;
		void setPhone(string x);
		string getPhone() ;
		void setPerson();
		
		friend ostream &operator<<(ostream &out,Person &);
};
#endif
