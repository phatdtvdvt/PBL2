#include<iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "ListOfRevenue.h"
#include "Linkedlist.h"
#include "Product.h"
#include "Revenue.h"
#include "Date.h"
#include "MENU.cpp"
#include "List.h"

using namespace std;

ListOfRevenue :: ListOfRevenue(){

}
ListOfRevenue ::~ListOfRevenue(){

}
void ListOfRevenue ::ReadFromFile(){
    fstream filein("D:/Codeki3/PBL/Data/WarrantyAndRevenueNew.txt", ios::in);
	string line;
    while(getline(filein,line)){
        Revenue temp;
        stringstream linestream(line);
        string value;
        int j = 1;
        while(getline(linestream,value,',')){
            Date a;
            switch(j){
                case 1: 
                    temp.SetPhone(value); break;
                case 2:
                    temp.SetID(value); break;
                case 3:
                    temp.SetNumOfAPro(atoi(value.c_str())); break;
				case 4:
					temp.SetPrice(atoi(value.c_str())); break;
                case 5:
                    temp.SetHistoricalCost(atoi(value.c_str()));break;
				case 6:
					temp.SetDay(a.SetDayFromStr(value)); break;
				case 7:
					temp.SetWarranty(atoi(value.c_str())); break;
            }
            j++;
        }
        (*this) + temp;
    }
    filein.close();
}
void ListOfRevenue ::SaveToFile(){
    ofstream F1;
    F1.open("D:/Codeki3/PBL/Data/WarrantyAndRevenueNew.txt",ios ::trunc);
    Node<Revenue>* temp = this->Head;
    while(temp != NULL){
        //F1 << 2;
        F1 << temp->data.GetPhone() << "," << temp->data.GetID() << "," << temp->data.GetNumOfAPro() << "," << temp->data.GetPrice() << "," << temp->data.GetHistoricalCost() << "," << temp->data.GetDay1() <<","<<temp->data.GetWarranty();
        if(temp ->next != NULL){
            F1 << endl;
        }
        temp = temp ->next;
    }
    F1.close();
}
void ListOfRevenue :: operator+(Revenue x){
    this->InsertNode(x);
}
int ListOfRevenue ::WarrantyLookup(string x, string y){
    Node <Revenue>* temp = this->Head;
    Date a; a.today();
    int i = 0;
    while(temp != NULL){
        if(temp->data.GetPhone() == x){ 
            i++;
            if(temp->data.GetID() == y){
                Date b = temp->data.GetDay() + temp->data.GetWarranty();
                if(b > a){
                    return 1;
                }else return 0;
            }
        }
        temp = temp->next;
    }
    if(i == 0) return 2;
}
void ListOfRevenue ::RevenueOfDay(Date &a){
    Node <Revenue>* temp = this->Head;
    long long total = 0;
    long long total1 = 0;
    while (temp != NULL){
        if(temp ->data.GetDay() == a){
            temp->data.OutPutOfRevenue();
            total += temp->data.GetPrice()*temp->data.GetNumOfAPro();
            total1 += temp ->data.GetHistoricalCost()*temp->data.GetNumOfAPro();
        }
        temp = temp->next;
    }
    cout << "\t\t" <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << " TOTAL   :"<< setw(18) << total << setw(15) << total1<< endl;
    cout << "\t\t" <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << " PROFIT  :" << setw(33) << total - total1 << endl;
}
ListOfRevenue ListOfRevenue ::FindListByMonth(int x, int y){
    ListOfRevenue a;
    Node <Revenue>* temp = this->Head;
    while (temp != NULL){
        if(temp ->data.GetDay().Y == y && temp->data.GetDay().M == x){
            a + temp->data;
        }
        temp = temp->next;
    }
    return a;
}
void ListOfRevenue ::QuantityStatistics(){
    List a; a.ReadFromFile();
    Node <Product>* temp2 = a.Head;
    long long total;
    long long total1 ;
    //a.OutPut();
    while(temp2 != NULL){
        int k = 0;
        Node <Revenue>* temp1 = this->Head;
        total = 0;
        total1 = 0;
        while(temp1 != NULL){
            if(temp1->data.GetID() == temp2->data.GetID()){
                k = k + temp1->data.GetNumOfAPro();
            }
            total += temp1->data.GetPrice()*temp1->data.GetNumOfAPro();
            total1 += temp1 ->data.GetHistoricalCost()*temp1->data.GetNumOfAPro();
            temp1 = temp1 ->next;  
        }
        if(k != 0){
            cout << "\t\t" << setw(12)<< left << temp2->data.GetID() << " | " << setw(40)  << temp2->data.GetName() << " | " << setw(3) << k << " | " << endl;
        }
        temp2 = temp2->next; 
    }
    cout << endl;
    cout << "\t\t" <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << " TOTAL   :" << endl;
    cout << "\t\t       - According to selling price:       " << setw(18) << total << endl;
    cout << "\t\t       - according to the purchase price:  " << setw(18) << total1<< endl;
    cout << "\t\t--------------------------------------------------------------------" << endl;
    cout << "\t\t" <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << " PROFIT  :" << setw(28) << "    " << total - total1 << endl;
}
long long ListOfRevenue ::RevenueOfMonth(int x, int y, int k){
    Node <Revenue>* temp = this->Head;
    long long total = 0;
    long long total1 = 0;
    while (temp != NULL){
        if(temp ->data.GetDay().Y == y && temp->data.GetDay().M == x){
            total += temp->data.GetPrice()*temp->data.GetNumOfAPro();
            total1 += temp ->data.GetHistoricalCost()*temp->data.GetNumOfAPro();
        }
        temp = temp->next;
    }
    if(k == 1){
        return total;
    }else if(k == 2){
        return total1;
    }
}
void ListOfRevenue ::RenvenueOfYear(int y){
    //Node <Revenue>* temp = this->Head;
    int i = 1;
    long long total = 0;
    long long total1 = 0;

    Linkedlist <long long> l;
    Linkedlist <long long> l1;
    while(i <= 12){
        l.InsertNode(this->RevenueOfMonth(i,y,1));
        l1.InsertNode(this->RevenueOfMonth(i,y,2));
        i++;
    }
    i = 1;
    Node <long long>* temp1 = l.Head;
    Node <long long>* temp2 = l1.Head;
    while (temp1 != NULL && temp2 != NULL){
        total += temp1->data;
        total1 += temp2->data;
        cout << "\t\t--------------- Date: " << i << "/" << y  << " ---------------"<< endl;
        cout << "\t\t" <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << " TOTAL   :" << endl;
        cout << "\t\t       - According to selling price:       " << setw(18) << temp1->data << endl;
        cout << "\t\t       - According to the purchase price:  " << setw(18) << temp2->data << endl;
        cout << "\t\t" <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << " PROFIT   :" << endl;
        cout << "\t\t                                           " << setw(18) << temp1->data - temp2->data << endl << endl;
        temp1 = temp1 ->next;
        temp2 = temp2 ->next;
        i++;
    }
    cout << "\t\t\t" << (char) 201;
    for(int i = 1; i < 75; i++){
        cout << (char) 205;
    }
    cout << (char)187 << endl;
    cout << "\t\t\t" << (char) 186 << "\t\t\t ------- "<< y<<" -------\t\t\t\t   " << (char) 186 << endl;
    cout << "\t\t\t" << (char) 186 <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << "\t TOTAL   :" << endl;
    cout << "\t\t\t" << (char) 186 << "\t- According to selling price:       " << setw(18) << total  << endl;
    cout << "\t\t\t" << (char) 186 << "\t- According to the purchase price:  " << setw(18) << total1 << endl;
    cout << "\t\t\t" << (char) 186 <<(char) 282 << (char) 282 <<(char) 282 <<(char) 282 <<(char) 282 << "\t PROFIT   :"  << endl;
    cout << "\t\t\t" << (char) 186 <<  "\t\t\t\t\t\t\t" << total - total1 << endl;
    cout << "\t\t\t" << (char) 200;
    for(int i = 1; i < 75; i++){
        cout << (char) 205;
    }
    cout << (char)188 << endl;
    //return total;
}
void ListOfRevenue ::WarrLookup(){
    Node <Revenue>* temp = this->Head;
    ListOfRevenue a;
    string ph,id;
    int i = 0;
    while(1){
        cout << "\n\t\t\t\t-  Enter the phone number you want to check warranty: "; cin >> ph;
        while(temp != NULL){
            if(temp->data.GetPhone() == ph){
                i++;
                a + temp->data;
            }
            temp = temp->next;
        }
        if(i == 0){
            cout << "\t\t\t\t => This phone number has not been purchased! " << endl;
            cout << "\t\t\tPress any key to continue enter other number or press ECS if you want to exit!";
                int k = key();
                    if(k == 8){
                        break;
                    }
        }else{
            while(1){
                system("cls");
                cout << "\t\t-------List of Product: " << endl << endl;
                a.Display();
                cout << "\n\t\t\t-  Enter the ID of Product you want to check warranty: "; cin >> id;
                if(a.WarrantyLookup(ph,id) == 1){
                    cout << "\t\t\t~~~ Product still under warranty! " << endl;
                }else if(a.WarrantyLookup(ph,id) == 0){
                    cout << "\t\t\t--- Product is out of warranty! " << endl;
                }
                cout << "\t\t\tPress any key to continue or press ECS if you want to exit!";
                int k = key();
                    if(k == 8){
                        break;
                    }
            }
            break;
        }
    }
}