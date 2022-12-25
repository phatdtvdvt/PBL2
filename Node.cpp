#include<iostream>
#include<string>
#include "Node.h"
using namespace std;

template <class T> Node<T> ::Node(){    
    next = NULL;
}
template <class T> Node<T> ::Node(T data){
    this ->data = data;
    this ->next = NULL;
}