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
Node* getstartingpointofloop(Node*& head){
    //check for loop
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            //matlab cycle to exist krti hai but yeh thori jroori hai ki starting point hi return kiya esna
            break;
        }
    }
    //yaah phunch gay matlab kahi na kahi slow fast meet kr gay 
    //agr fast null hua means no cycle return 
    if(fast == NULL) return NULL;
    //slow hmara head par hai 
    //cycle exist so slow attached to head
    //Step1 = slow ko head se assign krdo 
    slow = head;
    //loop chlao jab tak fast slow brabar nhi hota
    while(fast != slow){
        //esma simple chlayenge loop 
        //slow ko bdao 
        slow = slow->next;
        //fast ko bdao
        fast = fast->next;
        //check kro ki yeh same hua ya nhi
    }
    //return starting point
    //bahar aaya matlab fast slow ek jagah par hai to return krdo slow ko
    return slow;
}
//Remove a loop 
//jo starting point se pehle vala link hai usko htakar null krdo ho gya loop remove
void removeloop(Node*& head){
    //check for loop
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            //matlab cycle to exist krti hai but yeh thori jroori hai ki starting point hi return kiya esna
            break;
        }
    }
    //yaah phunch gay matlab kahi na kahi slow fast meet kr gay 
    //agr fast null hua means no cycle return 
    // if(fast == NULL) return NULL;
    //slow hmara head par hai 
    //cycle exist so slow attached to head
    //Step1 = slow ko head se assign krdo 
    slow = head;
    //loop chlao jab tak fast slow brabar nhi hota
    while(fast != slow){
        //esma simple chlayenge loop 
        //slow ko bdao 
        slow = slow->next;
        //fast ko bdao
        fast = fast->next;
        //check kro ki yeh same hua ya nhi
    }
   //hme starting point mil gya
   Node* startpoint = slow;
   Node* temp = fast;
   while(temp->next != startpoint){
    temp = temp->next;
   }
   temp->next = NULL;
}
void printsll(Node*& head){
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
   removeloop(head);
   printsll(head);
   bool ans2 = checkcycleinlinkedlist(head);
   if(ans2) cout<<"Cycle exist in linked list"<<endl;
   else cout<<"Cycle does not exist"<<endl;
    return 0;
}