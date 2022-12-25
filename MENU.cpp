#ifndef Menu_h
#define Menu_h
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "List.h"
#include "Functions.h"

#define WINWIDTH 80
#define WINHEIGHT 3

using namespace std;

class Menu{
	public:
        //friend void ListItem();
        friend void SET_COLOR(int color);
        friend int Key();
        friend void ListChange();
        friend void filler();
        friend void liner();
        friend void Profile();
        friend void welcome();
        friend void MenuPerson();
        friend void ListChange();
        //friend void Menu();

        void StoreManagerInterface();
        void SaffInterface();
        void CustomerInterface();
};
void SET_COLOR(int color){
	WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
int key(){
	char c = getch();
    if ((int) c == -32) c = getch();
    switch ((int) c) {
        case 80:
            return 1; //cout << "Xuong";
        case 72:
            return 2; //cout << "Len";
        case 77:
            return 3; //cout << "Phai";       
        case 75:
            return 4; //cout << "Trai";
        case 27:
            return 8; //Nut ESC thoat
        case 13:
            return 5; //Nut Enter
        default:
            return 0; //cout << "Sai";
    }
}
void filler(){
    cout << "\t\t\t";
    for(int i = 0 ; i < WINWIDTH ; i++)
    {
        cout << "*";
    }
    cout << "\a" << endl;
}
void liner(){
    for(int i = 0 ; i < WINHEIGHT ; i++)
        cout << endl;
}
void Profile(){
    SET_COLOR(3);
    string GV = "   GVHD: Tran Ho Thuy Tien";
    string x = "Tran Thi Huynh Linh         - MSSV: 102210299";
    string P = "Pham Nguyen Anh Phat        - MSSV: 102210302";
    string X1 = "   - Sinh vien: ";
    string X3 = "   - Ten De Tai: ";
    int k = x.size();
    int k1 = 64;
    int k2 = X1.size();
    int k5 = X3.size();
    string x1 = "Ung Dung Quan Li Cua Hang Ban Do Dien Tu";
    string x2 = "   - Ten De Tai: ";
    int k4 = x1.size();
    int k3 = x2.size();
    string PBl ="                   PBL2: DO AN CO SO LAP TRINH";
    cout << "\t\t\t\t" << (char) 201;
    for(int i = 1; i < 65; i++){
        cout << (char) 205;
    }
    cout << (char)187 << endl;
    cout << "\t\t\t\t" << (char) 186 << setw(PBl.size()) << PBl << setw(k-PBl.size()+1+19) << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 186 << "________________________________________________________________" << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 186 << "   Lop: 21TCLC_KHDL\t\t\t\t\t\t " << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 186 << GV << setw(k1-k+1+19) << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 186 << X1 << setw(k) << x << setw(k1-k-k2+1) << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 186 << X1 << setw(k) << P << setw(k1-k-k2+1) << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 186 << x2 << setw(k4) << x1 << setw(k1-k3-k4+1) << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 200;
    for(int i = 1; i < 65; i++){
        cout << (char) 205;
    }
    cout << (char)188 << endl;
}
void welcome(){
    system("cls");
    liner();
    SET_COLOR(5);
    cout << "\tLoading..." << endl;
    Sleep(400);
    char msg[] = "WELCOME TO ELECTRONIC STORE MANAGEMENT SYSTEM";
    int len = strlen(msg);
    int x;
    x = ((WINWIDTH+56)/2) - (len/2);
    cout << "\t";
    for(int i = 0 ; i < WINWIDTH ; i++)
    {   
        printf("%c",176);
        Sleep(10);
    }
    cout << endl;
    system("CLS");
    liner();
    filler();
    cout << setw(len+x) << msg << endl;
    filler();
    cout <<  endl << endl;
    Profile();
    cout << "\t\t\t\t\tEnter any keys to continue!";
    getch();
}
void MenuPerson(){
    SET_COLOR(6);
    cout << "\t\t\t\t-----------------------------------";
    cout << "\n\t\t\t\t\t   WHO ARE YOU?" << endl;
    cout << "\t\t\t\t" << (char) 201;
    for(int i = 0; i <= 32; i++){
       cout << (char) 205;
    }
    cout << (char) 187 << endl;
    cout << "\t\t\t\t" << (char) 186 << "\t(1) Store Manager         " << (char) 186 << endl
        << "\t\t\t\t" << (char) 186 << "\t(2) Sales Agent           " << (char) 186 << endl
        << "\t\t\t\t" << (char) 186 << "\t(3) Client                " << (char) 186 << endl
        << "\t\t\t\t" << (char) 186 << "\t(0) Exit                  " << (char) 186 << endl;
    cout << "\t\t\t\t" << (char) 200;
    for(int i = 0; i <= 32; i++){
       cout << (char) 205;
    }
    cout << (char) 188 << endl;
    cout << "\t\t\t\t"<< (char) 282 <<" Choice: ";
}
void ListChange(){
    cout << "\t\t\t\t--------- Change ---------" << endl;
    cout << "\t\t\t\t|    1. Name             |" << endl;
    cout << "\t\t\t\t|    2. Price            |" << endl;
    cout << "\t\t\t\t|    3. Quantity         |" << endl;
    cout << "\t\t\t\t|    4. Sold             |" << endl;
    cout << "\t\t\t\t|    5. HistoricalCost   |" << endl;
    cout << "\t\t\t\t|    0. Exit.            |" << endl;
    cout << "\t\t\t\t--------------------------" << endl;
    cout << "\t\t\t\t"<< (char) 282 <<" Choice: ";
}
void Menu ::StoreManagerInterface(){
    List DS;
    DS.ReadFromFile();
    Functions F;
    while(1){
        system("cls");
        int c;
        cout << endl << endl;
        SET_COLOR(10);
        cout << "\t\t\t\t~~~~~~~~~~~~~~ STORE MANAGER ~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t\t" << (char) 186  << "  (1) Change: name, price, quantity,... " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (2) Remove product.                   " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (3) Add new product.                  " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (4) Revenue management.               " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (0) Exit.                             " << (char) 186 <<endl;
        cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t\t"<< (char) 282 <<" Choice: "; cin >> c;
        switch (c){
        case 1:
            while(1){
                string x,c;
                system("cls");
                cout << "\t\t\t\t CHANGE: NAME, PRICE, QUANTITY " << endl;
                cout << "\t\t\t What type of product do you want to edit? " << endl;
                getchar();
                cout << "\t\t\t Input type of product: "; getline(cin, x);
                while(1){
                    DS.SearchByName(x).OutPut();
                    cout << endl << endl;
                    cout << "\t\t\t "<< (char) 282 <<  " Enter the ID of the product you want to edit, Ex: BP#AK0001 : ";  
                    cin >> c;
                    system("cls");
                    ListChange(); 
                    int j; cin >> j;
                    if(j == 3){
                        DS.ChangeTheQuantity(c);  
                    }else if(j == 2){
                        DS.ChangeThePrice(c);
                    }else if(j == 1){
                        DS.ChangeTheName(c);
                    }else if(j == 4){
                        DS.ChangeTheSold(c);
                    }else if(j == 5){
                        DS.ChangeTheHistoricalCost(c);
                    }else if(j == 0){
                        break;
                    }
                    cout << "\n\t\t\tPress ENTER to continue this item OR Press ESC to exit ";
                    int k = key();
                    if(k == 8){
                        break;
                    }
                }
                break;   
            }
            break;
        case 2:
            while (1){
                string x,c;
                system("cls");
                cout << "\t\t\t\t REMOVE PRODUCTS " << endl;
                cout << "\t\t\t What type of product do you want to remove? " << endl;
                cout << "\t\t\t Press 'no' if there isn't product you want to remove! " << endl;
                getchar();
                cout << "\t\t\t Input type of product: "; getline(cin, x);
                if( x == "no"){
                    break;
                }
                while(1){
                    DS.SearchByName(x).OutPut();
                    cout << endl << endl;
                    cout << "\t\t\t "<< (char) 282 <<  " Enter the ID of the product you want to remove, Ex: BP#AK0001 : "; 
                    cin >> c;
                    system("cls");
                    DS.DeleteProduct(c);
                    cout << "\n\t\t\tPress ENTER to continue this item OR Press ESC to exit ";
                    int k = key();
                    if(k == 8){
                        break;
                    }
                }
            }
            break;
        case 3:
            int num;
            cout << "\t\t\t\tHow many new items do you want to import? "; cin >> num;
            for(int i = 0; i < num; i++){
                int j = i;
                cout << "\t\t\t\t" << ++j << ":";
                DS.InportNewProduct();
            }
            if(num != 0){
                cout << "\t\t\t\t  " << (char) 259 << " Products added successfully " << (char) 259 << endl;
            } 
            cout << "\t\t\t\tPress any key to continue";
            getch();
            break;
        case 4:
            F.Revenue_Management();
            break;
        default:
            break;
        }
        if ( c == 0) break;
    }
    char tl;
    cout << "\t\t\t\t" << (char) 282 << "Do you want to save these changes? (Y/N) "; 
    cin >> tl;
    tl = toupper(tl);
    if(tl == 'Y'){
        DS.SaveToFile();
        return;
    }else if(tl == 'N'){
        return;
    }
}
void Menu ::SaffInterface(){
    Functions F;
    while(1){
        system("cls");
        int c;
        ListOfRevenue Lt;
        Lt.ReadFromFile();
        SET_COLOR(13);
        cout << endl << endl;
        cout << "\t\t\t\t~~~~~~~~~~~~~~ SALES AGENT ~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t\t" << (char) 186  << "  (1) Sell products and print bill.   " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (2) Warranty Lookup.                " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (0) Exit.                           " << (char) 186 <<endl;
        cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t\t"<< (char) 282 <<" Choice: "; cin >> c;
        switch (c){
            case 1:
                while(1){
                    F.Feature_Sell();
                    break;
                }  
                break;
            case 2:
                Lt.WarrLookup();
            case 0:
                break;
        }
        if(c == 0){
            break;
        }
    }
    return;
}
void Menu ::CustomerInterface(){
    Functions A;
    List YourCart;
    while(1){
        system("cls");
        int c; string a;
        SET_COLOR(3);
        cout << endl << endl;
        cout << "\t\t\t\t~~~~~~~~~~~~~~ CUSTOMER INTERFACE ~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t\t" << (char) 186  << "  (1) Find information of product.           " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (2) Buy products.                          " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (3) Purchase History.                      " << (char) 186 <<endl;
        cout << "\t\t\t\t" << (char) 186  << "  (0) Exit.                                  " << (char) 186 <<endl;
        cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t\t"<< (char) 282 <<" Choice: "; cin >> c;
        system("cls");
        switch (c){
            case 1:
                YourCart = A.ProductFilter();
                break;
            case 2:
                YourCart.OutPutOfCus();
                cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~" << (char) 259 << "THIS IS YOUR CART " << (char) 259 << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << endl;
                if(YourCart.Head == NULL){
                    cout << "\t\t\t\t Add items to your cart before you buy! " << endl;
                    cout << "\t\t\t\t Press any keys to ESC "; getch();
                }else{
                     A.Feature_SellOfCus(YourCart);
                }
                break;
            case 3:
                A.PurchaseHistory();
                break;
            case 0:
                break;
        }
        if(c == 0){
            break;
        }
    }
    return;
}
#endif
