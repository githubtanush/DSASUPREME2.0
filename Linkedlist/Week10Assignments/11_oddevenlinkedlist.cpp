#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
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
int getlength(Node*& head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;        
    }
    return length;
}
void printll(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void insertathead(Node*& head,Node*& tail,int data){
    //head is null
    if(head == NULL){
        //Step 1 = create new node
        Node* newNode = new Node(data);
        //Step 2 = head and tail ko newNode se initialize kr rahhu
        head = newNode;
        tail = newNode;
    }
    else{
        //head null nhi hai
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}
Node* oddevenlinkedlist(Node* head){
    if(!head && head->next==0) return head;

    Node* h1 = head; //odd linked list
    Node* h2 = head->next; // even linked list
    Node* evenhead = h2;
    while(h2 && h2->next){
        h1->next = h2->next;
        h2->next = h2->next->next;
        h1 = h1->next;
        h2 = h2->next;
    }
    h1->next = evenhead;
    return head;
}
int main(){ 
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,5);
    insertathead(head,tail,4);
    insertathead(head,tail,3);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    printll(head);

    
    cout<<endl;
    Node* ans = oddevenlinkedlist(head);
    printll(ans);

    return 0;
}
// 1 2 3 4 5
// 1 3 5 2 4