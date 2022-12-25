#ifndef Node_h
#define Node_h
#include <string>
using namespace std;
template <class T>
class Node{
public:
    T data;
    Node<T> *next;
    Node();
    Node(T data);
};
#endif