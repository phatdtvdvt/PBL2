#ifndef Linkedlist_h
#define Linkedlist_h
#include "Node.h"
template <class T>
class Linkedlist{
    protected:
        Node<T>* Head;
    public:
        Linkedlist();
        virtual ~Linkedlist(){};
        
        void InsertNode(T x);
        void Display();
        void Display1();

        friend class ListOfRevenue;    
        friend class Customer;
        friend class LinkedlistCus; 
        friend class Functions;
        friend class Menu;   
};
#endif