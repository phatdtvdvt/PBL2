#ifndef ListCus_h
#define ListCus_h
#include"LinkedlistCus.h"
#include"Infor.h"
#include"Customer.h"
class ListCus{
	protected:
		LinkedlistCus client;
	public:
		ListCus();
		~ListCus();
		void read_file();
		void write_file();
		LinkedlistCus getclient();

		friend class List;	
			
};
#endif
