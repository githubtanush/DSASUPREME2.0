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
Node* rotateright(Node* head,int k){
    if(!head) return 0;

    int len = getlength(head);
    int actualrotatek = (k % len);
    if(actualrotatek == 0) return head;
    int newlastpos = len-actualrotatek-1;
    Node* newlastnode = head;
    for(int i = 0; i < newlastpos;i++){
        newlastnode = newlastnode->next;
    }
    Node* newhead = newlastnode->next;
    newlastnode->next = 0;
    Node* it = newhead;
    while(it->next){
        it = it->next;
    }
    it->next = head;
    return newhead;
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
    int k = 2;
    head = rotateright(head,k);
    printll(head);

    return 0;
}
// 1 2 3 4 5
// 1 3 5 2 4