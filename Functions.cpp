#include <iostream>
#include <string>
#include <iomanip>
#include "Product.h"
#include "Infor.h"
#include "ListCus.h"
#include "Functions.h"
#include "List.h"
#include "ListOfRevenue.h"
#include "MENU.cpp"

using namespace std;

Functions ::Functions(){

}
Functions ::~Functions(){

}
void Functions ::Revenue_Management(){
    ListOfRevenue Lst;
    Lst.ReadFromFile();
    int C, ch;
    while(1){
        system("cls");
        cout << "\t\t   ~~~~~~~~~~~~~~~~~~ REVENUE ~~~~~~~~~~~~~~~~~~ " << endl;
        cout << "\t\t\t\t 1. Revenue of Day. " << endl;
        cout << "\t\t\t\t 2. Revenue of Month. " << endl;
        cout << "\t\t\t\t 3. Revenue of Year. " << endl;
        cout << "\t\t\t\t 0. Exit.              " << endl;
        cout << "\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << "\t\t\t\t"<< (char) 282 <<" Choice: "; cin >> C;
        switch (C){
        case 1:
            while(1){
                system("cls");
                cout << "\t\t\t---------------- Revenue of Day ----------------------" << endl;
                cout << "\t\t\t\t 1. Revenue today.                     " << endl;
                cout << "\t\t\t\t 2. Revenue of a day that you enter.   " << endl;
                cout << "\t\t\t\t 0. Exit.                              " << endl;
                cout << "\t\t\t-------------------------------------------------------" << endl;
                cout << "\t\t\t\t"<< (char) 282 <<" Choice: "; cin >> ch;
                Date a;
                if(ch == 1){
                    system("cls");
                    a.today();
                    cout <<" \t\t\t-------- Date: " << a <<" --------" << endl;
                    Lst.RevenueOfDay(a);
                    getch();
                }else if(ch == 2){
                    while(1){
                        system("cls");
                        cout << "\t\t\t Intput day: "; cin >> a;
                        cout <<" \t\t\t-------- Date: " << a <<" --------" << endl;
                        Lst.RevenueOfDay(a);
                        cout << endl;
                        cout << "\t\t\t Press ANY KEYS to continue another date OR press ESC to exit this function: ";
                        int k = key();
                        if(k == 8){
                            break;
                        }
                    }
                }else if( ch == 0){
                    break;
                }
            }
            break;
        case 2:
            while(1){
                system("cls");
                cout << "\t\t\t---------------- Revenue of Month ----------------------" << endl;
                int x,y;
                cout << "\t\t\t - Month: "; cin >> x;
                cout << "\t\t\t - Year : "; cin >> y;
                cout << endl;
                cout << "\t\t\t\t~~~~~~~~ Date: " << x << "/" << y << " ~~~~~~~~" << endl;
                Lst.FindListByMonth(x,y).QuantityStatistics();
                cout << endl;
                cout << endl;
                cout << "\t\t\t Press ANY KEYS to continue another date OR press ESC to exit this function: ";
                int k = key();
                    if(k == 8){
                        break;
                    }
            }
            break;
        case 3:
            while(1){
                system("cls");
                cout << "\t\t---------------- Revenue of Year ----------------------" << endl;
                int y;
                cout << "\t\t\t - Year : "; cin >> y; 
                Lst.RenvenueOfYear(y);
                cout << "\t\t\t Press ANY KEYS to continue another date OR press ESC to exit this function: ";
                int k = key();
                    if(k == 8){
                        break;
                    }
            }
            break;
        default:
            break;
        }
        if(C == 0) break;
    }
}
void Functions ::Feature_Sell(){
    List K, ProSell;
	K.ReadFromFile();
	ListOfRevenue b;
	b.ReadFromFile();
    ListCus Cus;
    Cus.read_file();
	string Ph;
    Date D; D.today();
	string name; 
    cout << "\t\t\t\t-  Enter phone number of customer: "; cin >> Ph;
    int cnt = 0;
	int i;
	if(Cus.getclient().Head == nullptr){
		return;
	}else{	
		Node<Customer> *tempCus = Cus.getclient().Head;
		while(tempCus!=nullptr){
			if(tempCus->data.getPhone() == Ph){
				name = tempCus->data.getName();
				cnt = 1;
				int count = 0;
                system("cls");
                cout << "\t\t\t\t------------------------------------------" << endl;
                cout << "\t\t\t\t" << (char) 179 << "              SELL PRODUCTS             " << (char) 179 << endl;
                cout << "\t\t\t\t------------------------------------------" << endl;
                while(1){
                    Node<Product>* tempPro = K.Head;
					cout << "\n\t\t\t\t Product " << " :" << endl;
					string x;
        			cout << "\t\t\t\t-  Enter ID of product : "; cin >> x;
					while(tempPro != NULL){
						if(tempPro->data.GetID() == x){
                            count = 1;
							if(tempPro->data.GetQuantity() == 0){                                
								cout << "\t\t\t\tThis product is sold out!" << endl;
							}else{
								int i;
                    			cout << "\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;
								while(1){
									if(i > tempPro->data.GetQuantity()){
                    			    	cout << "\t\t\t\t Invalid purchase quantity!" << endl;
                    				}else{
										Product a = tempPro->data;
										a.SetQuantity(i);
										ProSell + a;
                    			    	tempPro->data.SetQuantity(tempPro->data.GetQuantity() - i);
                    					tempPro->data.SetSold(tempPro->data.GetSold() + i);
										Infor In(x, i,tempPro->data.GetPrice(),"","");
										tempCus->data.goods.InsertNode(In);
										Revenue R (Ph,x,i,tempPro->data.GetPrice(), tempPro->data.GetHistoricalCost(),D,tempPro->data.GetWarranty());
                    					b + R;
										break;
                    				}
									cout << "\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;  
								}
							}
							break;
						}
						tempPro = tempPro->next;
					}
                    if(count == 0){
                        cout << "\t\t\t\t This ID is not found!" << endl;
                    }
                    cout << "\t\t\t\tPress ENTER to continue, OR Press ESC to exit ";
                    int k = key();
                    if(k == 8){
                        break;
                    }
                }
				break;
			}
			tempCus = tempCus->next;			
		}
	}
	if(cnt==0){
			cout<<"\t\t\t\t The customer is not exist, Do you want add new customer: "<< endl;
			string sdt;
			string id;
			int quan;
			int price;
			string address;
			int count = 0;
			cout<<"\t\t\t\t-	Input Name: ";fflush(stdin); getline(cin,name);
			sdt = Ph;
            system("cls");
            cout << "\t\t\t\t------------------------------------------" << endl;
            cout << "\t\t\t\t" << (char) 179 << "              SELL PRODUCTS             " << (char) 179 << endl;
            cout << "\t\t\t\t------------------------------------------" << endl;
            while(1){
                Node<Product>* tempPro = K.Head;
				cout << "\n\t\t\t\t Product " << " :" << endl;
				string x;
        		cout << "\t\t\t\t-  Enter ID of product : "; cin >> x;
				while(tempPro != NULL){
					if(tempPro->data.GetID() == x){
                        count = 1;
						if(tempPro->data.GetQuantity() == 0){
							cout << "\t\t\t\tThis product is sold out!" << endl;
						}else{
							int i;
                    		cout << "\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;
							while(1){
								if(i > tempPro->data.GetQuantity()){
                    			    cout << "\t\t\t\t Invalid purchase quantity!" << endl;
                    			}else{
									Product a = tempPro->data;
									a.SetQuantity(i);
									ProSell + a;
                    			    tempPro->data.SetQuantity(tempPro->data.GetQuantity() - i);
                    				tempPro->data.SetSold(tempPro->data.GetSold() + i);
									Infor In(x, i,tempPro->data.GetPrice(),"","");
									Customer d(name,sdt,In);
									Cus.getclient().InsertNode(d);
									Revenue R (Ph,x,i,tempPro->data.GetPrice(), tempPro->data.GetHistoricalCost(),D,tempPro->data.GetWarranty());
                    				b + R;
									break;
                    			}
								cout << "\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;  
							}
						}
						break;
					}
					tempPro = tempPro->next;
				}
                if(count == 0){
                    cout << "\t\t\t\t This ID is not found!" << endl;
                }
                cout << "\t\t\t\tPress ENTER to continue, OR Press ESC to exit ";
                int k = key();
                if(k == 8){
                    break;
                }
            }
	}
	char tl;
	ProSell.PrintBill(D,name,Ph,"","");
    cout << "\t\t\t\t" << (char) 282 << "Do you want to save these changes? (Y/N) "; 
    cin >> tl;
    tl = toupper(tl);
    if(tl == 'Y'){
        Cus.getclient().write_file();
		b.SaveToFile();
		K.SaveToFile();
        return;
    }else if(tl == 'N'){
        return;
    }
}
List Functions ::ProductFilter(){
    string a, y, Y;
    List Cart;
    while(1){
        List b;
        b.ReadFromFile();
        cout << endl;
        system("cls");
        cout << "\t\t\t\t---------------- FILTER -----------------------" << endl;
        cout << "\t\t\t\t   (1) Filter products: by name, by type.         " << endl;
        cout << "\t\t\t\t   (2) Filter best-selling products.              " << endl;
        cout << "\t\t\t\t   (3) Filter products: by price.                 " << endl;
        cout << "\t\t\t\t   (0) Exit                                       " << endl;
        cout << "\t\t\t\t-----------------------------------------------" << endl;
        cout << "\t\t\t\t Note: You can choose many functions? Ex: 123, 23 " << endl;
        cout << "\t\t\t\t"<< (char) 282 <<" Choice: "; cin >> a;
        if(a == "0"){
            break;
        }
        int k = a.size();
        switch (k){
            case 1:
                if(a[0] == '1'){
                    cout << "\t\t\t\t-   What type of product do you want to find? " << endl;
                    getchar();
                    cout << "\t\t\t\t-   Input type of product: "; getline(cin, y);
                    b.SearchByName(y).OutPutOfCus();
                }else if(a[0] == '2'){
                    b.SortByBestSelling().OutPutOfCus();
                }else if(a[0] == '3'){
                    b.FilterByPrice().OutPutOfCus();
                }
                cout << "\n\t\t\t\t-  Enter the ID of the product you want to add to the cart. " << endl;
                cout << "\t\t\t\t-  Enter no if there is no product you want to buy." << endl;
                while(1){
                    cout << "\n\t\t\t\t" << (char) 282 << " Input: "; cin >> Y;
                    if(Y == "no"){
                        break;
                    }else{
                        if (b.SearchByID(Y).GetID() != "undefined"){
                            Cart + b.SearchByID(Y);
                        }else{
                            cout << "\t\t\t\tThis ID is not found!" << endl;
                        }
                        cout << "\t\t\t\tPress any key to continue or press ECS if you want to exit!";
                        int k = key();
                        if(k == 8){
                            cout << "\n\t\t\t\t Products added to cart, press any key to continue! ";
                            break;
                        }
                    }
                }
                getch();
                break;
            case 2:
                if(a == "12" || a == "21"){
                    cout << "\t\t\t\t-   What type of product do you want to find? " << endl;
                    getchar();
                    cout << "\t\t\t\t-   Input type of product: "; getline(cin, y);
                    b.SearchByName(y).SortByBestSelling().OutPutOfCus();
                }else if (a == "13" || a == "31"){
                    cout << "\t\t\t\t-   What type of product do you want to find? " << endl;
                    getchar();
                    cout << "\t\t\t\t-   Input type of product: "; getline(cin, y);
                    b.SearchByName(y).FilterByPrice().OutPutOfCus();
                }else if (a == "23" || a == "32"){
                    b.FilterByPrice().SortByBestSelling().OutPutOfCus();
                }
                cout << "\n\t\t\t\t-  Enter the ID of the product you want to add to the cart. " << endl;
                cout << "\t\t\t\t-  Enter no if there is no product you want to buy." << endl;
                while(1){
                    cout << "\n\t\t\t\t" << (char) 282 << " Input: "; cin >> Y;
                    if(Y == "no"){
                        break;
                    }else{
                        Cart + b.SearchByID(Y);
                        cout << "\t\t\t\tPress any key to continue or press ECS if you want to exit!";
                        int k = key();
                        if(k == 8){
                            cout << "\n\t\t\t\t Product added to cart, press any key to continue! ";
                            break;
                        }
                    }
                }
                
                getch();
                break;
            case 3:
                if(a == "123" || a == "132" || a == "213" || a == "231" || a == "312" || a == "321"){
                    cout << "\t\t\t\t-   What type of product do you want to find? " << endl;
                    getchar();
                    cout << "\t\t\t\t-   Input type of product: "; getline(cin, y);
                    b.SearchByName(y).FilterByPrice().SortByBestSelling().OutPutOfCus();
                }
                cout << "\n\t\t\t\t-  Enter the ID of the product you want to add to the cart. " << endl;
                cout << "\t\t\t\t-  Enter no if there is no product you want to buy." << endl;
                while(1){
                    cout << "\n\t\t\t\t" << (char) 282 << " Input: "; cin >> Y;
                    if(Y == "no"){
                        break;
                    }else{
                        Cart + b.SearchByID(Y);
                        cout << "\t\t\t\tPress any key to continue or press ECS if you want to exit!";
                        int k = key();
                        if(k == 8){
                            cout << "\n\t\t\t\t Product added to cart, press any key to continue! ";
                            break;
                        }
                    }
                }          
                getch();
                break;
            default:
                break;
        }
    }
    return Cart;
}
void Functions ::Feature_SellOfCus(List &a){
    ListOfRevenue Lt;
    Lt.ReadFromFile();
    List A; A.ReadFromFile();
    //Staff Nv;
    ListCus Cus;
    Cus.read_file();
    string Ph;
    Date D; D.today();
    int q = 0;
    string address;
    string name;
    cout << "\n\t\t\t\t-  Enter your phone number:       "; cin >> Ph;
    cout << "\t\t\t\t-   Enter your delivery address:    "; fflush(stdin); getline(cin,address);
    Node<Product>* temp = a.Head;
    Node<Customer> *tempCus = Cus.getclient().Head;
    while(tempCus != NULL){
        if(tempCus->data.getPhone() == Ph){
                q = 1;
                name = tempCus->data.getName();
                while(temp != NULL){
                    Node<Product>* tmp = A.Head;
                    while(tmp != NULL){
                        if(tmp->data.GetID() == temp->data.GetID()){
                            if(temp->data.GetQuantity() == 0){
                                cout << "\t\t-  " << temp->data.GetName() << endl;
                                cout << "\t\t\t=>     This product is sold out!" << endl;
                            }else{
                                int i; 
                                cout << endl;
                                cout <<"\t\t--------------------------------------------------------------------------" << endl;
                                cout <<"\t\t\t" << tmp->data.GetID() << "      " << setw(40) << tmp->data.GetName() << setw(12) << tmp->data.GetPrice() << endl;
                                cout <<"\t\t--------------------------------------------------------------------------" << endl;
                                cout << "\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;
                                while(1){
                                    if(i > tmp->data.GetQuantity()){
                                        cout << "\t\t\t\t Invalid purchase quantity!" << endl;
                                    }else{
                                        temp->data.SetQuantity(i);
                                        tmp->data.SetQuantity(tmp->data.GetQuantity() - i);
                                        tmp->data.SetSold(tmp->data.GetSold() + i);
                                        Infor In(temp->data.GetID(), i,tmp->data.GetPrice(),address,"onl");
                                        tempCus->data.goods.InsertNode(In);
                                        Revenue R (Ph,temp->data.GetID(),i,tmp->data.GetPrice(), tmp->data.GetHistoricalCost(),D,tmp->data.GetWarranty());
                                        Lt + R;
                                        break;
                                    }
                                    cout << "\n\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;
                                }
                            }
                            break;
                        }
                        tmp = tmp ->next;
                    }
                    temp = temp->next;
                }
        }
        tempCus = tempCus ->next;
    }
    if(q == 0){
        system("cls");
        cout << "\t\t\t\t\t ~~~~~ WELCOM NEW CUSTOMER ~~~~~ " << endl;
        cout << "\t\t\t\t  Please enter your information:" << endl;
        
        cout<<"\t\t\t\t-	Input Name: ";fflush(stdin); getline(cin,name);
        while(temp != NULL){
            Node<Product>* tmp = A.Head;
            while(tmp != NULL){
                if(tmp->data.GetID() == temp->data.GetID()){
                    if(temp->data.GetQuantity() == 0){
                        cout << "\t\t-  " << temp->data.GetName() << endl;
                        cout << "\t\t\t=>     This product is sold out!" << endl;
                    }else{
                        int i; 
                        cout << endl;
                        cout <<"\t\t--------------------------------------------------------------------------" << endl;
                        cout <<"\t\t\t" << tmp->data.GetID() << "      " << setw(40) << tmp->data.GetName() << setw(12) << tmp->data.GetPrice() << endl;
                        cout <<"\t\t--------------------------------------------------------------------------" << endl;
                        cout << "\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;
                        while(1){
                            if(i > tmp->data.GetQuantity()){
                                cout << "\t\t\t\t Invalid purchase quantity!" << endl;
                            }else{
                                temp->data.SetQuantity(i);
                                tmp->data.SetQuantity(tmp->data.GetQuantity() - i);
                                tmp->data.SetSold(tmp->data.GetSold() + i);
                                Infor In(temp->data.GetID(), i,tmp->data.GetPrice(),address,"onl");
                                Customer h(name,Ph,In);
                                Cus.getclient().InsertNode(h);
                                Revenue R (Ph,temp->data.GetID(),i,tmp->data.GetPrice(), tmp->data.GetHistoricalCost(),D,tmp->data.GetWarranty());
                                Lt + R;
                                break;
                            }
                            cout << "\n\t\t\t\t-  Enter the quantity which you want to buy: "; cin >> i;
                        }
                    }
                            break;
                        }
                        tmp = tmp ->next;
                    }
                    temp = temp->next;
        }
    }
    a.PrintBill(D,name,Ph, address,"onl");
    cout << "\t\t\t\t-  Press ENTER to confirm your order. " << endl;
    cout << "\t\t\t\t-  Press ESC to cancel the order. ";
    int k = key();
    if(k == 5){
        cout << "\t\t\t\t ~~~ THANK YOU ~~~" << endl;
        A.SaveToFile();
        Lt.SaveToFile();
        Cus.getclient().write_file();
    }else{
        return;
    }
}
void Functions :: PurchaseHistory(){
    ListOfRevenue Lt; Lt.ReadFromFile();
    List A; A.ReadFromFile();
    ListCus Cus; Cus.read_file();
    do{
        SET_COLOR(3);
        string Ph, Name;
        int count = 0;
        system("cls");
        cout << "\t\t\t\t- Input your Phonenumber: "; cin >> Ph;
        Node<Customer>* TempCus = Cus.getclient().Head;
        while(TempCus != NULL){
            if(TempCus->data.getPhone() == Ph){
                count = 1;
                Name = TempCus->data.getName();
            }
            TempCus = TempCus ->next;
        }
        if(count == 0){
            cout << "\t\t\t\t-------------------------------------------" << endl;
            cout << "\t\t\t\t- This phone number has not been purchased!" << endl;
            cout << "\t\t\t\t-------------------------------------------" << endl;
            SET_COLOR(4);
            cout << "\t\t\t\t- Press ANY KEY to check with another phone number! " << endl;
            cout << "\t\t\t\t- Press ESC to exit!";
            int k = key();
            if (k == 8){
                break;
            }
        }else{
            system("cls");
            cout << "\t";
            for(int i = 0; i < 81; i++){
                cout << (char) 278;
            }
            cout << endl;
            cout << "\t\t\t\t YOUR PURCHASE HISTORY" << endl;
            cout << "\t\t\t Name        : " << Name << endl;
            cout << "\t\t\t Phonenumber : " << "0"+Ph << endl;
            cout << "\t";
            for(int i = 0; i < 81; i++){
                cout << (char) 278;
            }
            cout << endl;
            Node<Revenue>* tempRe = Lt.Head;
            while(tempRe != NULL){
                Node<Product>* tempPro = A.Head;
                if(tempRe->data.GetPhone() == Ph){
                    cout << "\t\t" << left << setw(12) << tempRe->data.GetDay1() << "|   ";
                    while(tempPro != NULL){
                        if(tempRe->data.GetID() == tempPro->data.GetID()){
                            cout << setw(45) << tempPro->data.GetName();
                            break;
                        }
                        tempPro = tempPro->next;
                    }
                    cout << setw(3) << tempRe->data.GetNumOfAPro() << setw(15) << tempRe->data.GetPrice() << endl;
                }
                tempRe = tempRe->next;
            }
            cout << "\t";
            for(int i = 0; i < 81; i++){
                cout << (char) 278;
            }
            cout << endl;
            SET_COLOR(4);
            cout << "\t\t\t- Press ANY KEY to check with another phone number! " << endl;
            cout << "\t\t\t- Press ESC to exit!";
            int k = key();
            if (k == 8){
                break;
            }
        }
    } while(1);
}