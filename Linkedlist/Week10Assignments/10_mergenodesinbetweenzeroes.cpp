#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* bottom;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        bottom = NULL;
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
Node* mergeNodes(Node* head){
if(!head) return NULL;
        Node* slow = head;
        Node* fast = head->next;
        Node* newlastNode = NULL;
        int sum = 0;
        while(fast){
            if(fast->data != 0){
                sum += fast->data;
            }
            else{
                //fast->val = 0
                slow->data = sum;
                newlastNode = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }
        // ListNode* temp = newlastNode->next;
        //just formed newlastnode
        newlastNode->next = NULL;
        // while(temp){
        //     ListNode* nxt = temp->next;
        //     delete temp;
        //     temp = nxt;
        // }
        return head;
    }
int main(){ 
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,0);
    insertathead(head,tail,9);
    insertathead(head,tail,0);
    insertathead(head,tail,4);
    insertathead(head,tail,3);
    insertathead(head,tail,2);
    insertathead(head,tail,0);
    printll(head);

    
    cout<<endl;
    Node* ans = mergeNodes(head); 
    printll(ans);

    return 0;
}
//Set this main function according to test case
