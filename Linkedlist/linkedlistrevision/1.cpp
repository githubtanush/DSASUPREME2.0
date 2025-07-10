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
void insertatfirst(Node*& head,Node*& tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}
Node* middleNode(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
Node* reverseusingrec(Node*& prev,Node*& curr){
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
bool comparelist(Node*& head,Node*& head2){
    while(head != NULL && head2 != NULL){
        if(head->data != head2->data) return false;
        else{
            head = head->next;
            head2 = head2->next;
        }
    }
    return true;
}
void printll(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
bool ispalindrome(Node*& head){
    Node* midNode = middleNode(head);
    Node* head2 = midNode->next;
    midNode->next = NULL;
    Node* prev = NULL;
    Node* curr = head2;
    head2 = reverseusingrec(prev,curr);
    cout<<endl;
    printll(head);
    cout<<endl;
    printll(head2);
    bool compare = comparelist(head,head2);
    return compare;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertatfirst(head,tail,1);
    insertatfirst(head,tail,2);
    insertatfirst(head,tail,3);
    insertatfirst(head,tail,4);
    insertatfirst(head,tail,3);
    insertatfirst(head,tail,2);
    insertatfirst(head,tail,1);
    printll(head);
    if(ispalindrome(head)) cout<<"LL is Palindromic ll"<<endl;
    else cout<<"LL is not a palindromic ll"<<endl;
    return 0;
}