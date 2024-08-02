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
void solve(Node* head,int& carry){
    if(!head) return ;

    solve(head->next,carry);
    //1 case solve krna hai
    int prod = head->data*2 + carry;
    head->data = prod % 10;
    carry = prod / 10;
}
Node* doubleit(Node* head){
    int carry = 0;
    solve(head,carry);
    if(carry){
        Node* carrynode = new Node(carry);
        carrynode->next = head;
        head = carrynode;
    }
    return head;
}
int main(){ 
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,5);
    insertathead(head,tail,4);
    insertathead(head,tail,9);
    insertathead(head,tail,9);
    insertathead(head,tail,9);
    printll(head);

    
    cout<<endl;
    Node* ans = doubleit(head);
    printll(ans);

    return 0;
}
// 1 2 3 4 5
// 1 3 5 2 4