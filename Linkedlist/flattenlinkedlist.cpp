#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* bottom;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        bottom = NULL;
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
Node* merge(Node* a,Node* b){
    if(!a) return b;
    if(!b) return a;

    Node* ans = 0;
    if(a->data < b->data){
        ans = a;
        a->bottom = merge(a->bottom,b);
    }
    else{
        ans = b;
        b->bottom = merge(a,b->bottom);
    }
    return ans;
}
Node* flatten(Node* root){
    if(!root) return 0;

    Node* mergedLL = merge(root,flatten(root->next));

    return mergedLL;
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
    Node* ans = flatten(head); 
    printll(ans);

    return 0;
}
//Set this main function according to test case
