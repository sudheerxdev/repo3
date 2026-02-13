#include<iostream> 
using namespace std;
class Node{
    public:
    int data ; 
    Node * next ; 
    Node(int data){
        this -> data = data;
        this-> next =  nullptr;
    }
};
int main(){
    int n ; 
    int arr[n];
    cout << "Enter the number of elements in the linked list: ";
    cin >> n ; 
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    Node * head = new Node(arr[0]);
    Node * temp = head;
    for(int i = 1 ; i < n ; i++){
        temp ->next =new Node(arr[i]);
        temp = temp -> next;
    }
    Node * ptr = head;
    while(ptr != nullptr){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    

}