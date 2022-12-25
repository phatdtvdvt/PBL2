#include<iostream>
#include<string>
#include "Linkedlist.h"
#include "Node.h"
using namespace std;

template <class T> Linkedlist <T> ::Linkedlist(){
    Head = NULL;
}
template <class T> void Linkedlist<T> ::InsertNode(T x){
    Node<T>* NewNode = new Node<T>(x);
        if(Head == NULL){
            Head = NewNode;
            return;
        }else{
            Node<T>* temp = Head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = NewNode;
        }
}
template <class T> void Linkedlist<T> ::Display(){
    Node<T>* temp = Head;
    if(Head == NULL){
        cout << "Empty List!!";
        return;
    }else{
        while (temp != NULL){
            cout << temp ->data;
            temp = temp ->next;
        }
    }
}
template <class T> void Linkedlist<T> ::Display1(){
    Node<T>* temp = Head;
    if(Head == NULL){
        cout << "Empty List!!";
        return;
    }else{
        while (temp != NULL){
            (temp ->data).OutPutofCus();
            temp = temp ->next;
        }
    }
}


