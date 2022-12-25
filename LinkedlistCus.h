#ifndef LinkedlistCus_h
#define LinkedlistCus_h
#include "Node.h"
#include "Customer.h"
class LinkedlistCus: public Linkedlist<Customer>{
	protected:
		int N;
	public:
		LinkedlistCus();
		virtual ~LinkedlistCus();

		void InsertNode(Customer x);
		void write_file();
		void Display();	
		void find_Customer(string x);
		int getN();

		friend class ListCus;
		friend class Customer;
		friend class List;
		friend class Functions;
};




#endif
