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
Node* addtwonumbers(Node*& l1,Node*& l2){
    //sbse pehle reverse krenge taaki carry vala chakkar khatam ho 
    l1 = reverselinkedlist(l1);
    l2 = reverselinkedlist(l2);
    //mein ek new linked list create krlunga -1 se initialize krke
    Node* ans = new Node(-1);
    //ek iterator create kr lunga us linked list mein move krne ke liye
    Node* it = ans;
    //ek carry variable create krlunga
    int carry = 0;
    //ab while loop chlaunga tab tak jab tak l1 ya l2 ya carry null nhi ho jata
    while(l1 || l2 || carry){
        //agr l1 null nhi hai l1 mein plus krte time uska data store ho jaay nhi to null
        int a = l1 ? l1->data : 0;
        //agr l2 null nhi hai toh l2 mein plus krta time uska data aa jay
        int b = l2 ? l2->data : 0;
        //jab yeh dono aa gya to enka sum krlo
        int sum = a + b + carry;
        //lekin ho skta hai two digit aa jaay esliye uska modulus kro
        int digit = sum % 10;
        //agr do digit hua to carry bhi jrurr aayga take it
        carry = sum / 10;
        //ab ek new node bna kar nyi vali linked list ka andar uski value store kr lenge it->next ko usse map krwa denge
        it->next = new Node(digit);
        //now it ko it agli node par le jao 
        it = it->next;
        //l1 ko bhi bdao agr null nhi hai toh
        l1 = l1 ? l1->next : 0;
        l2 = l2 ? l2->next : 0;
    }
    Node* finalans = ans->next; //kyuki ek -1 abhi phaltu hai hmara pass
    //so delete ans;
    delete ans;
    //return finalans;
    return finalans;

}
int main(){
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
    printll(ans);
    return 0;
}
// 3 4 2
// 4 6 5
// 8 0 7
// 7 0 8