#ifndef Customer_h 
#define Customer_h
#include"Person.h"
#include"Infor.h"
#include"Linkedlist.h"

class Customer: public Person{
	Linkedlist<Infor> goods;

	public:
		Customer();
		~Customer();
		Customer(string name, string phone,Infor x);	
			
		Linkedlist<Infor> getGoods();
		void Buy();
		void CancelOrder();

		const Customer &operator = (const Customer &);
		friend ostream &operator<<(ostream &out,Customer &);

		friend class LinkedlistCus;
		friend class Linkedlist<Infor>;
		friend class List;
		friend class Functions;
};
#endif
