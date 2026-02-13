#include<iostream>
using namespace std;
class Node {
public :
    int data ;
    Node * next ;
    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};
class LinkedList {
  public:
    Node * head ;
    Node * tail;
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add() {
        int data ;
        cout << " Add data "<< endl;
        cin >> data;
        Node * newnode = new Node(data);
        if (head == nullptr) {
            head = tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    void print() {
        Node * ptr = head ;
        while (ptr != nullptr) {
            cout << ptr -> data << "-> ";
            ptr = ptr ->next;
        }
        cout << "null";
    }
};
int main() {
    // creating the object of the linked list
    LinkedList ll;
    ll.add();
    ll.add();
    ll.add();
    ll.add();
    ll.add();
    ll.add();
    ll.print();
}