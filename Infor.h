#ifndef Infor_h
#define Infor_h
#include<string>
using namespace std;
//thong tin 1 loai san pham da mua
class Infor{
	protected:
	string ID;
		int Quantity;
		int Price; // gia tien voi tung 1 san pham
		long Bill;// tong tien cua 1 loai san pham
		string form;
		string Address; 
	public:
		Infor();
		Infor(string id,int q, int p,string addr ,string f);
		virtual ~Infor();
		friend ostream &operator<<(ostream &out,Infor &);	
		void set_infor(string id,int q, int p);
		string getID();
		int getQuantity();
		int getPrice();
		string getForm();
		void setForm(string x);
		string getAddress();
		void setAddress(string x);
};
#endif
