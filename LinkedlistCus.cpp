#include"LinkedlistCus.h"
#include"Customer.h"
#include"Infor.h"
#include"Node.h"
#include<iostream>
#include<fstream>
using namespace std;
LinkedlistCus::LinkedlistCus(){
	N = 0;
	Head = nullptr;
};
void LinkedlistCus::InsertNode(Customer x){
	Node<Customer>* NewNode = new Node<Customer>(x);
	if(Head == nullptr){
		Head = NewNode;
	}else{
		Node<Customer>* temp = Head;
        while(temp ->next != nullptr){
			if(temp->data.getPhone()==NewNode->data.getPhone()){
				Infor d(x.getGoods().Head->data.getID(),x.getGoods().Head->data.getQuantity(),x.getGoods().Head->data.getPrice(),x.getGoods().Head->data.getAddress(),x.getGoods().Head->data.getForm());
            	temp->data.goods.InsertNode(d);
			}
			temp = temp->next;
        }
        if(temp->data.getPhone()==NewNode->data.getPhone()){
				Infor d(x.getGoods().Head->data.getID(),x.getGoods().Head->data.getQuantity(),x.getGoods().Head->data.getPrice(),x.getGoods().Head->data.getAddress(),x.getGoods().Head->data.getForm());
            	temp->data.goods.InsertNode(d);
		}else{
        	temp->next = NewNode;
		}
	}
	N++;
};
void LinkedlistCus:: Display(){
	Node<Customer> *temp=Head;
	if(Head==nullptr){
		cout<<"EMPTY!!!";
		return;
	}else{
		while(temp!=nullptr){
			cout<<temp->data;
			temp=temp->next;
		}
	}
	
};	
int LinkedlistCus::getN(){
	return N;
};
void LinkedlistCus::find_Customer(string x){
	int cnt=0;
	if(Head==nullptr){
		cout<<"An empty List"<<endl;
	}else{
		Node<Customer> *temp = Head;
		while(temp!=nullptr){
			if(temp->data.getPhone()==x){
				cout<<temp->data;
				cnt+=1;
				break;
			}
			temp=temp->next;			
		}
		if(cnt==0){
			cout<<"The Customer is not exist!"<<endl;
		}
	}
};

void LinkedlistCus::write_file(){
	ofstream file;                      
	file.open("D:/Codeki3/PBL/Data/khachhangnew.txt",ios::trunc); 
	Node<Customer>* temp=Head;
	if(Head==nullptr){
		return;
	}else{
		while(temp!=nullptr){
			Node<Infor> *tempInfor = temp->data.goods.Head;
			while(tempInfor!=nullptr){
				file << temp->data.getPhone()<<","<<tempInfor->data.getID()<<","<<tempInfor->data.getQuantity()<<","<<temp->data.getName()<<","<<tempInfor->data.getAddress()<<","<<tempInfor->data.getPrice()<<","<<tempInfor->data.getForm();
				if(tempInfor->next!=nullptr){
					file << endl;
				}
				tempInfor=tempInfor->next;
			}
			if(temp->next != nullptr){
					file << endl;
			}
			temp=temp->next;
		}
	}
	file.close(); 
};
LinkedlistCus::~LinkedlistCus(){

};
