#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void printll(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int length(Node*& head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}
void insertathead(Node*& head,Node*& tail,int data){
    //agr head hi null hua toh
    if(head == NULL){
        //create new node
        Node* newNode = new Node(data);
        //head ko newnode se initialize kro or tail ko bhi
        head = newNode;
        tail = newNode;
    }
    else{
        //matlab ki linkedlist pehle se hai 
        // toh
        //step1 = create new node;
        Node* newNode = new Node(data);
        //step 2 = newnode ke next ko head se point krwa do
        newNode->next = head;
        //step 3 = head ko newnode se initialize kr do
        head = newNode;
    }
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,2);
    insertathead(head,tail,3);
    insertathead(head,tail,4);
    insertathead(head,tail,5);
    printll(head);
    int m = 2;
    int n = 1;
   
    cout<<endl;
    printll(head);
    return 0;
}