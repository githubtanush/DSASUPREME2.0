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
int length(Node*& head){
    //Step 1 - pehle mein ek jaali temporary pointer bna dena taaki mere head ch koi dikkat na aava ta oh apni jagah te rah 
    // kyuki maanu bacho vi ohdi value di lodd pa skdi hai 
    Node* temp = head;
    //ek variable bnana length name da taaki length find kr ska okkkk
    int length = 0;
    //mein eh loop td tak chlaunga jab tak null nhi aa janda jida hi null aaya oh aaga nhi aayga ta oh hi apni length di value hoygi
    while(temp!=NULL){
        //length lagatar bdd rhi hai 
        length++;
        //pointer next nu assign ho reha
        temp = temp->next;
    }
    //length return krti hai 
    return length;
}
void printll(Node*& head){
//Step 1 - pehle mein ek jaali temporary pointer bna dena taaki mere head ch koi dikkat na aava ta oh apni jagah te rah 
// kyuki maanu bacho vi ohdi value di lodd pa skdi hai 
    Node* temp = head;
//loop jad tak null nhi aa janda
    while(temp != NULL){
        //print kdi ja value ohdi linked list di 
        cout<<temp->data<<" ";
        //temp nu aaga vdada 
        temp = temp->next;
    }   
}
void insertathead(Node*& head,Node*& tail,int data){
    //Agr head null hoya phir 
    if(head==NULL){
        //step 1 - create new node
        Node* newNode = new Node(data);
        //step 2 - kyuki head null si esliye head nu vi new node de brabar kr de and also tere kol tail vi byrefrence aa reha ta ohnu vi update kr de
        head = newNode;
        tail = newNode;
        //finished agr head tail null si taah bss ehna hi hai 
    }
    else{
        //step 1 = create new node
        Node* newNode = new Node(data);
        //step 2  = newNode de next nu mein head naal attach kr dena
        newNode->next = head;
        //step 3 = mein head nu hi new node bna dena
        head = newNode;
    }
}

// Node* reversekgroup(Node*& head,int k){
//     //agr head null ho gya toh ya null hi hua toh
//     if(head == NULL) return head;
//     //agr head ka next null hua toh bhi return head hi hoga
//     if(head->next == NULL) return head;
//     //now base case hogay 
    
//     //ab mein 1 case krta hu baaki to recursion chacha ji hai hi 
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* nextNode = NULL;
//     int pos = 0;
//     int len = length(head);
//     if(len < k) return head;
//     while(pos < k ){
//         nextNode  = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = nextNode;
//         pos++;
//     }
//     //Ab chacha ji ki baari
//     Node* recursionkaans = NULL;
//     if(nextNode != NULL){
//         recursionkaans = reversekgroup(nextNode,k);
//         head->next = recursionkaans;
//     }
//     return prev;
// }

Node* solve(Node*& head){
    //ll hi nhi hai to remove thori kuch ho jayga
if(head == NULL) return head;
//single element hai to remove thori kuch ho jayga
if(head->next == NULL) return head;

//Step 1 - make temporary node
Node* temp = head;
//jab tak temp null ke brabar nhi ho jata tab tak loop chlao
while(temp != NULL){
    //agr temp ka next null nhi hai 
    //or temp ka data temp ka next ke data ke similar hai toh remove krdo
    if(temp->next != NULL && temp->data == temp->next->data){
        //Removekrdo
        //nextnode mein temporary ka next store krwa lo
        Node* nextNode = temp->next;
        //or temp ke next ko nextnode ke next se link kr do
        temp->next = nextNode->next;
        //nextnode ke next ko null krdo
        nextNode->next = NULL;
        //nextnode ko delete kr do
        delete nextNode;
    }
    else{
        //agr yeh sb kuch nhi hai to temp ko aaga bda do
        temp = temp->next;
    }
}
//head ko return krwa do
return head;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,2);
    insertathead(head,tail,2);
    insertathead(head,tail,3);
    insertathead(head,tail,3);
    insertathead(head,tail,4);
    int k = 2;
    printll(head);
    cout<<endl;
    head = solve(head);
    printll(head);
    return 0;
}
// 9 9 9 
//1 0 0 0 