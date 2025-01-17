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
// Node* reversell(Node*& head){
//     Node* prev = NULL;
//     Node* curr = head;

//     while(curr != NULL){
//         Node* nextNode = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = nextNode;
//     }
//     return prev;
// }
// Node* printkthnodefromend(Node*& head,int& k){
//     Node* curr = head;
//     // int pos = 0;
//     while(k--){
//         curr = curr->next;
//     }
//     return curr;
// }
void printkthnodefromend(Node*& head,int& k,int& ans){
    //Recursive solution
    //jeise hi head mile return krdo
    if(head == 0) return ;
    //head null hua sath hi mein us head ka next kr diya yaani reverse ho gya
    printkthnodefromend(head->next,k,ans);
    //k agr 0 ho gya to ans store krlo
    if(k == 0) ans = head->data;
    // k-- shi position tak phunchne ke liye 
    k--;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,2);
    insertathead(head,tail,3);
    // insertathead(head,tail,0);
    printll(head);

    cout<<endl;
    int k = 2;
    int ans = -1;
    printkthnodefromend(head,k,ans);
    printll(head);
    cout<<"The Node present at the reverse of kth position is : "<<ans<<endl;
   
    return 0;
}
