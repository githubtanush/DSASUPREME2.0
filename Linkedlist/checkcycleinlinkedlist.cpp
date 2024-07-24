#include<iostream>
#include<map>
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
    //agr head null hoyaphir
    if(head == NULL){
        //Step1 - create new node
        Node* newNode = new Node(data);
        //Step2 - head tail ko new node se initialize kr do 
        head = newNode;
        tail = newNode;
    }
    else{
        //list kuch hai 
        //Step1 = create new Node
        Node* newNode = new Node(data);
        //Step2 = newnode ka next ko head se join kr do
        newNode->next = head;
        //Step 3 = head  ko new node assign kr do 
        head = newNode;
    }
}
void insertattailcsll(Node*& head,Node*& tail,int data){
    //agr head null hoyaphir
    if(head == NULL){
        //Step1 - create new node
        Node* newNode = new Node(data);
        //Step2 - head tail ko new node se initialize kr do 
        head = newNode;
        tail = newNode;
        //Step 3 - tail ka next head ke equal kr do 
        tail->next = head;
    }
    else{
        //list kuch hai 
        //Step1 = create new Node
        Node* newNode = new Node(data);
        //Step2 = tail ka next ko newnode se join kr do
        tail->next = newNode;
        //Step 3 =  newnode ka next nu head se 
        newNode->next = head;
        //step 4 = tail ko newnode assign kr do 
        tail = newNode;
    }
}
void printll(Node*& head){
    // Node* temp = head;
    // while(temp != NULL){
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    Node* it = head;
    while(1){
        cout<<it->data<<" ";
        if(it->next == head){
            break;
        }
        it = it->next;
    }
}
//Ab yeh map vala trika to jaali hai jldi se pta lag jaayga or we can say that it is a brute force
// bool hascycle(Node*& head){
//     //ek map bna liya jab hm jis jis node par jaayenge uske corresponding value true 
//     // krte rhenge or jeise hi dobara koi true value vala aayga matlab cycle detect ho gyi
//     map<Node*,bool> table;
//     //traverse krne ke liye jaali pointer
//     Node* temp = head;
//     //jab tak temp null nhi ho jaata tab tak chlega yeh
//     while(temp != NULL){
//         //agr table mein node ki value false hai to 
//         if(table[temp] = false){
//             //false value ko hmm true krenge
//             table[temp] = true;
//         }
//         else{
//             //cycle present 
//             return true;
//         }
//         //temp nu aaga vdavanga ek ek krke
//         temp = temp->next;
//     }
//     //loop not present 
//     return false;
// }
//2nd approach
bool checkcycleinlinkedlist(Node*& head){
    //slow fast pointer approach 
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            //do baar fast ho gya ab slow aayga
            slow = slow->next;
        }
        //check for loop 
        if(fast == slow) return true;
    }
    return false;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    // insertathead(head,tail,1);
    // insertathead(head,tail,2);
    // insertathead(head,tail,3);
    // insertathead(head,tail,4);
    // insertathead(head,tail,5);
    insertattailcsll(head,tail,6);
    insertattailcsll(head,tail,7);
    insertattailcsll(head,tail,8);
    insertattailcsll(head,tail,9);
    insertattailcsll(head,tail,10);
    insertattailcsll(head,tail,11);
    
    printll(head);
   bool ans = checkcycleinlinkedlist(head);
   if(ans) cout<<"Cycle exist in linked list"<<endl;
   else cout<<"Cycle does not exist"<<endl;
    return 0;
}