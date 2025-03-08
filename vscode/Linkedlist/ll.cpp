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
void insertathead(Node*& head,Node*& tail,int data){
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
void insertattail(Node*& head,Node*& tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}
void printll(Node*& head){
   Node* temp = head;
   while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
   }
   cout<<endl;
}
int length(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertatanypos(Node*& head,Node*& tail,int pos,int data){
    int len = length(head);
    if(pos == 1) insertathead(head,tail,data);
    else if(pos > len) insertattail(head,tail,data);
    else{
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node* curr = head;
        while(pos != 1){
            pos--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}
void deletell(Node*& head,Node*& tail,int pos){
    if(head == NULL){
        cout<<"Cannot delete , because LL is empty"<<endl;
        return ;
    }
    if(head == tail){
        //step 1- create temporary node
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return ;
    }
    int len = length(head);
    if(pos == 1){
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    else{
        //bich mein koi bhi position aa gyi naa
       Node* prev = NULL;
       Node* curr = head;
       while(pos != 1){
        pos--;
        prev = curr;
        curr = curr->next;
       }
       prev->next = curr->next;
       curr->next = NULL;
       delete curr;
    }
}
Node* reversell(Node*& head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
bool checkcycle(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) return true;
    }
    return false;
}
Node* addtwonumbers(Node*& l1, Node*& l2){
    l1 = reversell(l1);
    l2 = reversell(l2);

    Node* ans = new Node(-1);
    Node* it = ans;
    int carry = 0;

    while(l1 || l2 || carry){
        int a = l1 ? l1->data : 0;
        int b = l2 ? l2->data : 0;
        int sum = a + b + carry ;
        int digit = sum % 10;
        carry = sum / 10;
        it->next = new Node(digit);
        it = it->next;
        l1 = l1 ? l1->next : 0;
        l2 = l2 ? l2->next : 0;
    }
    Node* finalans = ans->next;
    delete ans;
    return finalans;
}
int main(){
//    Node* head = NULL;
//    Node* tail = NULL;

//    insertathead(head,tail,76);
//    insertathead(head,tail,98);
//    insertattail(head,tail,23);
//    insertattail(head,tail,33);
//    insertatanypos(head,tail,2,99);
//    printll(head);
//    cout<<endl<<"Length of the linked list is : "<<length(head)<<endl;
//    deletell(head,tail,3);
//    printll(head);
//    head = reversell(head);
//    printll(head);


    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,3);
    insertathead(head,tail,4);
    insertathead(head,tail,2);
    printll(head);
    // head = reverselinkedlist(head);
    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertathead(head2,tail2,4);
    insertathead(head2,tail2,6);
    insertathead(head2,tail2,5);
    cout<<endl;
    printll(head2);
    cout<<endl;
    Node* ans = addtwonumbers(head,head2);
    ans = reversell(ans);
    printll(ans);
    return 0;
}