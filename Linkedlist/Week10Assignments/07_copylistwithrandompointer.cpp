#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* random;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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
// //1st Approach = T.C = O(n) and S.C = O(n)
// //by using unordered map
// Node* helper(Node* head,unordered_map<Node*,Node*>& mp){
//     if(head == 0) return 0;

//     Node* newhead = new Node(head->data);
//     mp[head] = newhead;
//     newhead->next = helper(head->next,mp);

//     if(head->random){
//         newhead->random = mp[head->random];
//     }
//     return newhead;
// }
// Node* copyrandomlist(Node* head){
//     unordered_map<Node*,Node*> mp; //oldnode->newnode mapping
//     return helper(head,mp);
// }
//2nd Approach = Better solution
//T.C - O(n) and S.C - O(1)
Node* copyrandomlist(Node* head){
    if(!head) return 0;

    //Step 1 = clone A -> A'
    Node* it = head; //iterate over old head
    while(it){
        Node* clonednode = new Node(it->data);
        clonednode->next = it->next;
        it->next = clonednode;
        it = it->next->next;
    }

    //Step 2 - assign random links of A' with the help of old node A
    it = head;
    while(it){
        Node* clonednode = it->next;
        clonednode->random = it->random->next;
        it = it->next->next;
    }
    //Step 3 = detach A' from A
    it = head;
    Node* clonedhead = it->next;
    while(it){
        Node* clonedhead = it->next;
        it->next = it->next->next;
        while(clonednode->next){
            clonednode->next = clonednode->next->next;
        }
        it = it->next;
    }
    return clonedhead;
}

int main(){ 
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,6);
    insertathead(head,tail,5);
    insertathead(head,tail,4);
    insertathead(head,tail,3);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    printll(head);

    return 0;
}

