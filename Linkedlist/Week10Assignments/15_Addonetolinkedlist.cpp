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
//Reverse krde hai linked list nu without using even recursion
Node* reverselinkedlist(Node*& head){
    //Step 1  = phir to 2 pointer leke aana hai ta ohda use krde hai linked list nu reverse krn lyi
    Node* previ = NULL;
    Node* curr = head;
    //Step 2 = loop chlana hai jad tak value plt ni jaandi 
    while(curr != NULL){
        //current jab tk not equal to 1 hai tab tak  yeh chlta jaayga
        //Step 1 = hmm kisi node ke andar to current ke next ki value ko store rkhenge
        Node* nextNode = curr->next;
        //Step 2 = hmm curr ke next ko prev se attach kr denge ll reverse krne ke liye
        curr->next = previ;
        //step 3 = ab hmm previ ko current ke equal krdenge loop aaga bdana ke liye
        previ = curr;
        //step 4 = hmm curr ke andar usi ke next ki value by using next node insert kr denge
        curr = nextNode;
    }
    //or hm previous ko return kr denge
    return previ;
}
// Node* Reverseusingrecursion(Node*& prev,Node*& curr){
//     //Base case
//     //agr current null ho gya to previous return krdo 
//     if(curr==NULL) return prev;

//     //now ab hm logic likhenge
//     //step 1 = nextnode ke andar current ka next ko store krwayenge
//     //store krenge curr ke next ko because ab hme curr ke next ko prev se point krwana 
//     //linked list reverse krna ka liye esliye next node se curr ke next ko save rkhenge
//     //taaki baad mein curr ko vaapis assign krrne ka kaam aay
//     Node* nextNode = curr->next;
//     //step 2 = curr ke next ka andar prev ko daalanga
//     curr->next = prev;
//     //step 3 = now hun prev nu curr ke equal assign kr daanga
//     prev = curr;
//     //step 4 = curr ko uski nextnode assign krdenge
//     curr = nextNode;

//     //baaaki apna aap recursion chacha ji sambhalenge
//     return Reverseusingrecursion(prev,curr);
// }
// Node* reverseusingrecursion(Node*& head){
//     Node* prev = NULL;
//     Node* curr = head;
//     return Reverseusingrecursion(prev,curr);
// }
void addone(Node*& head){
    //reverse  krdo
    head = reverselinkedlist(head);
    //add 1 
    int carry = 1;
    Node* temp = head;
    while(temp->next != NULL){
        int totalsum = temp->data + carry;
        int digit  = totalsum % 10;
        carry = totalsum / 10;

        //temp ke data de vich digit store krdanga
        temp->data = digit;
        //then temp nu aaga vda danga
        temp = temp->next;

        if(carry == 0) break;
    }
    if(carry != 0){
        int totalsum = temp->data + carry;
        int digit = totalsum % 10;
        carry = totalsum/10;
        temp->data = digit;
        if(carry != 0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }
    //phir se reverse krdo 
    head = reverselinkedlist(head);
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,9);
    insertathead(head,tail,9);
    insertathead(head,tail,9);
    printll(head);
    // head = reverselinkedlist(head);
    addone(head);
    cout<<endl;
    printll(head);
    return 0;
}
// 9 9 9 
//1 0 0 0 