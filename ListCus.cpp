#include<iostream>
#include"ListCus.h"
#include"Infor.h"
#include"Customer.h"
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
ListCus::ListCus(){
		
};
ListCus::~ListCus(){
		
};
void ListCus::read_file(){
	string sdt;
	string id;
	string ten;
	string quan;
	string price;
	string address;
	string form;
	ifstream file;
	file.open("D:/Codeki3/PBL/Data/khachhangnew.txt");
	while(!file.eof()){
		getline(file,sdt,',');
   		getline(file,id,',');
   		getline(file,quan,',');
		int num_quantity=atoi(quan.c_str());
  		getline(file,ten,',');
  		getline(file,address,',');
		getline(file,price,',');
		int num_price=atoi(price.c_str());
		getline(file,form);	
		Infor h(id,num_quantity,num_price,address,form);
		Customer d(ten,sdt,h);
		client.InsertNode(d);
	};
	file.close();
}
LinkedlistCus ListCus:: getclient(){
	return client;
};
