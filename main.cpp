#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include "Functions.cpp"
#include "Linkedlist.cpp"
#include "Node.cpp"
#include "Product.cpp"
#include "List.cpp"
#include "Revenue.cpp"
#include "Date.cpp"
#include "ListOfRevenue.cpp"
#include "Person.cpp"
#include "Infor.cpp"
#include "Customer.cpp"
#include "LinkedlistCus.cpp"
#include "ListCus.cpp"
#include "Menu.cpp"


using namespace std;

main(){
    Menu M;
    welcome();
    while(1){
        system("cls");
        MenuPerson();
        int ch; cin >> ch;
        switch(ch){ 
            case    1   :   M.StoreManagerInterface();
                            break;
            case    2   :   M.SaffInterface();
                            break;
            case    3   :   M.CustomerInterface();
                            break;
            case    0   :   break;
        }
        if(ch == 0) break;
    }
}

