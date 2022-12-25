#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "Functions.h"
#include "Person.h"
#include "Customer.h"
#include "Infor.h"
#include "ListCus.h"
#include "LinkedlistCus.h"
#include "ListOfRevenue.h"
#include "Linkedlist.h"
#include "Node.h"
#include "Product.h"
#include "List.h"
#include "MENU.cpp"

// #define WINWIDTH 80
// #define WINHEIGHT 3

using namespace std;
int recsnum(){
    ifstream f1;
	int numLines = 0;
	f1.open("Product.txt");
	std::string unused;
	while ( std::getline(f1, unused) )
   		++numLines;
	f1.close();
	return numLines;
}
List :: List(){
    this -> N =  recsnum();
}
void List :: ReadFromFile(){
    fstream filein("D:/Codeki3/PBL/Data/Product.txt", ios::in);
	string line;
    while(getline(filein,line)){
        Product temp;
        stringstream linestream(line);
        string value;
        int j = 1;
        while(getline(linestream,value,',')){
            switch(j){
                case 1: 
                    temp.SetID(value); break;
                case 2:
                    temp.SetName(value); break;
                case 3:
                    temp.SetSold(atoi(value.c_str())); break;
				case 4:
					temp.SetQuantity(atoi(value.c_str())); break;
				case 5:
					temp.SetPrice(atoi(value.c_str())); break;
				case 6:
					temp.SetHistoricalCost(atoi(value.c_str())); break;
				case 7:
					temp.SetWarranty(atoi(value.c_str())); break;
            }
            j++;
        }
        (*this) + temp;
    }
    filein.close();
}
void List ::SaveToFile(){
    ofstream f1;
    f1.open("D:/Codeki3/PBL/Data/Product.txt",ios ::trunc);
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        f1 << temp->data.GetID() << "," << temp->data.GetName() << ",";
        f1 << temp->data.GetSold() << "," << temp->data.GetQuantity() << "," << temp->data.GetPrice() << "," << temp->data.GetHistoricalCost() << "," << temp->data.GetWarranty();
        if(temp ->next != NULL){
            f1 << endl;
        }
        temp = temp ->next;
    }
    f1.close();
}
List List ::SearchByName(string x){
    List a;
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        string str2 = temp->data.GetName();
        if (str2.find(x) != std::string::npos) {
            a + (temp->data);
        }
        temp = temp ->next; 
    }
    return a;
}
Product List:: SearchByID(string x){
    
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        if(temp->data.GetID() == x ){
            return temp->data;
        }
        temp = temp->next;
    }
    Product P;
    //cout << "This ID could not be found!" << endl;
    return P;
}
void List :: ChangeTheQuantity(string x){
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        if(temp->data.GetID() == x ){
           cout << "\n\nThe item you want to edit: " << endl;
           cout << temp->data;
           int k;
           cout << "\n    - Input New Quantity: "; cin >> k;
           temp->data.SetQuantity(k);
           cout << "\nAfter editing: " << endl;
           cout << temp->data;
           return;
        }
        temp = temp->next;
    }
    cout << "This ID could not be found!" << endl;
}
 void List::ChangeThePrice(string x){
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        if(temp->data.GetID() == x ){
           cout << "\n\nThe item you want to edit: " << endl;
           cout << temp->data;
           long long k;
           cout << "\n    - Input New Price: "; cin >> k;
           temp->data.SetPrice(k);
           cout << "\nAfter editing: " << endl;
           cout << temp->data;
           return;
        }
        temp = temp->next;
    }
    cout << "This ID could not be found!" << endl;
}
 void List::ChangeTheName(string x){
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        if(temp->data.GetID() == x ){
           cout << "\n\nThe item you want to edit: " << endl;
           cout << temp->data;
           string k;
           cout << "\n    - Input New Name: "; getchar() ;getline(cin, k);
           temp->data.SetName(k);
           cout << "\nAfter editing: " << endl;
           cout << temp->data;
           return;
        }
        temp = temp->next;
    }
    cout << "This ID could not be found!" << endl;
}
 void List ::ChangeTheSold(string x){
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        if(temp->data.GetID() == x ){
           cout << "\n\nThe item you want to edit: " << endl;
           cout << temp->data;
           int k;
           cout << "\n    - Input New Sold: "; cin >> k;
           temp->data.SetSold(k);
           cout << "\nAfter editing: " << endl;
           cout << temp->data;
           return;
        }
        temp = temp->next;
    }
    cout << "This ID could not be found!" << endl;
}
void List ::ChangeTheHistoricalCost(string x){
    Node<Product>* temp = this->Head;
    while(temp != NULL){
        if(temp->data.GetID() == x ){
           cout << "\n\nThe item you want to edit: " << endl;
           cout << temp->data;
           long long k;
           cout << "\n    - Input New Sold: "; cin >> k;
           temp->data.SetHistoricalCost(k);
           cout << "\nAfter editing: " << endl;
           cout << temp->data;
           return;
        }
        temp = temp->next;
    }
    cout << "This ID could not be found!" << endl;
}
void List :: PrintBill(Date day, string ten, string sdt, string diachi, string form){
    system("cls");
    cout << "\t\t\t";
    for(int i = 0; i < 90; i++){
        cout << (char) 278 ;
    } cout << endl;
    cout << "\t\t\t\t\t\t\t ELECTRONIC STORE BILL " << endl;
    cout << "\t\t\t";
    for(int i = 0; i < 90; i++){
        cout << (char) 278;
    }cout << endl << endl;
    cout << "\t\t\t\t\t\t Date         : " << day <<endl;
    cout << "\t\t\t\t\t\t Name         : " << ten << endl;
    cout << "\t\t\t\t\t\t Phone Number : " << "0"+sdt << endl;// << endl;
    if(form != ""){
        cout << "\t\t\t\t\t\t Address      : " << diachi << endl;
    }
    cout << endl;
    cout << "\t\t\t\t\t\t\t===== List Of Product =====" << endl << endl;
    long long total = 0;
    Node <Product>* temp = this->Head;
    while(temp != NULL){
        if(temp->data.GetQuantity()!=0){
            cout << "\t\t\t " << setw(65) << left << temp->data.GetName() << setw(12) << temp->data.GetQuantity() << setw(90-65-12+1) << temp->data.GetPrice() << endl;
            total = total + temp->data.GetPrice()*temp->data.GetQuantity();
        }
        temp = temp->next;
    }
    cout << "\t\t\t\t\t"; 
    for(int i = 0; i < 75; i++){
        cout << "-" ;
    } cout << endl;
    cout << "\t\t\t " << setw(69) << right << "TOTAL:" << setw(15) << total << endl << endl;
    cout << "\t\t\t\t\t\t\t" << (char)259 << (char)259 << (char)259 << " Thank You " << (char)259 << (char)259 << (char)259 << endl;
    cout << "\t\t\t";
    for(int i = 0; i < 90; i++){
        cout << (char) 278 ;
    }
    cout << endl << endl;
}

void List ::InportNewProduct(){
    Product NewPr;
    string id;
    cout << "\n\t\t\t\tAdd new items" << endl;
    do{
        cout << "\t\t\t\t	- ID: "; cin >> id; getchar();
        if(CheckID(id, *this) == 0){
            NewPr.InputPr(id);
            (*this) + NewPr;
            break;
        }else{
            cout << "\t\t\t\t This ID already exists, please re-enter ! " << endl;
        }
    }while(1);
}
void List ::operator+(Product x){
    this-> N++;
    this-> InsertNode(x);
}
//template <class U> ostream operator << (ostream &os, const List<U> &a){
void List ::OutPut(){
    system("cls");
    cout << "\n------------------------------------------------------------ LIST OF PRODUCT ------------------------------------------------------------" << endl << endl;
    cout << setw(5)  << " ---ID---" << "        "<< " ----- Name Product ----- "  << "                   " << " Sold " << "	  " << "      Quantity" << "	   "  <<  "Price" << "         " <<  "Historical Cost" << "    " << "Warranty"  << endl << endl;
    this->Display();
}
void List :: OutPutOfCus(){
    system("cls");
    cout << "\n------------------------------------------------------------ LIST OF PRODUCT ------------------------------------------------------------" << endl << endl;
    cout << setw(5)  << " ---ID---" << "        "<< " ----- Name Product ----- "  << "                   " << " Sold " << "	  " << "      Quantity" << "	   " <<  "Price" << "           " << "Warranty"  << endl << endl;
    this->Display1();
}
void List ::DeleteProduct(string x){
    if(this->Head == NULL){
        cout << "Empty List!!";
        return;
    }
    Node<Product>* temp1 = this->Head;
    Node<Product>* temp2 = NULL;
    int tmp = 0;
    while (temp1 != NULL){
        temp1 = temp1->next;
        tmp++;
    }
    temp1 = this->Head;
    int flag = 0;
    if(temp1->data.GetID()== x && temp1->data.GetQuantity() == 0){
        Node<Product>* Head = Head ->next;
        delete temp1;
        return;
    }else if(temp1->data.GetID()== x && temp1->data.GetQuantity() != 0){
        cout << "\t\t\t! You can only remove products with quantity in stock = 0. Please change quantity then return to remove !" << endl;
        return;
    }
    for(int i = 1; i < tmp; i++){
        if(temp1->data.GetID()== x && temp1->data.GetQuantity() == 0){
            flag = 1;
            break;
        }else if(temp1->data.GetID()== x && temp1->data.GetQuantity() != 0){
            flag = 2;
            break;
        }
        temp2 = temp1;
        temp1 = temp1 ->next;
    }
    if(flag == 1){
        temp2 ->next = temp1 ->next;
        delete temp1;
        cout << "\t\t\t\tProduct removed !!!" << endl;
        this->N--;
    }else if(flag == 2){
        cout << "\t\t\t! You can only remove products with quantity in stock = 0. Please change quantity then return to remove !" << endl;
    }else{
        cout << "\t\t\t\tProduct not found" << endl;
    }
}
bool CheckID(string X, List a){
    Node<Product>* temp = a.Head;
    while(temp != NULL){
        if(temp->data.GetID() == X){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
List List ::SortByBestSelling(){
    for(Node<Product> *p = this-> Head; p->next != NULL; p = p->next){
        for (Node<Product> *q = p->next; q !=NULL; q = q->next){
            if (q ->data.GetSold() > p->data.GetSold()){
                Product tmp;
                tmp = q->data;
                q->data = p->data;
                p->data = tmp;
            }
        }
    }
    return (*this);
}
List List ::FilterByPrice(){
    int a;
    cout << "\t\t\t     ~~~ Please select a product price you want to filter! ~~~" << endl << endl;
    cout << "\t\t\t\t\t" << (char) 221 << "-------------------------" << (char) 221 << endl;
    cout << "\t\t\t\t\t" << (char) 221 << "     (1) < 1.000.000     " << (char) 221 << endl;
    cout << "\t\t\t\t\t" << (char) 221 << "     (2) > 1.000.000     " << (char) 221 << endl;
    cout << "\t\t\t\t\t" << (char) 221 << "     (3) > 2.000.000     " << (char) 221 << endl;
    cout << "\t\t\t\t\t" << (char) 221 << "-------------------------" << (char) 221 << endl;
    cout << "\t\t\t\t\t"<< (char) 282 <<" Choice: "; cin >> a;
    switch (a){
    case 1:
        *this = this->SearchByPrice('<',1000000);
        break;
    case 2:
        *this = this->SearchByPrice('>',1000000);
        break;
    case 3:
        *this = this->SearchByPrice('>',2000000);
        break;
    default:
        break;
    }
    return (*this);
}
List List ::SearchByPrice(char a, long long x){
    List L;
    Node<Product>* temp = this->Head;
    if(a == '<'){
        while(temp != NULL){
            if(temp->data.GetPrice() < x){
                L + (temp->data);
            }
            temp = temp->next;
        }
        return L;
    }else if(a == '>'){
        while(temp != NULL){
            if(temp->data.GetPrice() > x){
                L + (temp->data);
            }
            temp = temp->next;
        }
        return L;
    }
}