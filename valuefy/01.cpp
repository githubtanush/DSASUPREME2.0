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
void insertathead(Node* head,Node* tail , int data){
    if(head == NULL){
        //agr linked list khali ho toh 
        //Step 1 - create new node
        Node* newNode = new Node(data);
        //Step 2 - head newnode bna do
        head = newNode;
        //Step 3 - tail ko bhi bna do
        tail = newNode;
    }
    else{
        //agr khali nhi hai toh
        //Step 1 - create new node
        Node* newNode = new Node(data);
        //Step 2 - newnode ke next ko head se point krdo
        newNode->next = head;
        //Step 3 - head = newNode
        head = newNode;
    }
}
void insertattail(Node* head,Node* tail, int data){
    if(tail == NULL){
        //Step 1 - create new node
        Node* newNode = new Node(data);
        //Step 2 - assign head and tail with newnode
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}
int getlength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertathead(Node* head,Node* tail, int data,int position){
    int len = getlength(head);
    if(position == 1) insertathead(head,tail,data);
    else if(position > len) insertattail(head,tail,data);
    else{
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}
void deleteatll(Node* head,Node* tail,int position){
    if(head == NULL) cout<<"Cannot delete, because LL is empty"<<endl;
    //single element
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    int len = getlength(head);
    if(position == 1){
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else if(position == len){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
Node* reversell(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        //head di agli node naal link krta
        Node* nextNode = curr->next;
        // current di next nu previous naal milata 
        curr->next = prev;
        // prev nu current krta 
        prev = curr;
        // ta curr nu nextnode krta
        curr = nextNode;
    }
    return prev;
}
Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
int main(){

    return 0;
}   