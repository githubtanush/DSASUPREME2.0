#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
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
vector<int> nodesbetweencriticalpoints(Node* head){
    vector<int> ans = {-1,-1};
    Node* prev = head;
    if(!prev) return ans;
    Node* curr = head->next;
    if(!curr) return ans;
    Node* nxt = head->next->next;
    if(!nxt) return ans;
    
    int firstCp = -1;
    int lastCp = -1;
    int mindistance = INT_MAX;
    int i = 1;

    while(nxt){
        bool isCp = ((curr->data > prev->data && curr->data > nxt->data) || (curr->data < prev->data && nxt->data))?true:false;
        if(isCp && firstCp == -1){
            firstCp = i;
            lastCp = i;
        }
        else if(isCp){
            mindistance = min(mindistance,i-lastCp);
            lastCp = i; 
        }
        i++;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if(lastCp == firstCp)//means only 1 cp is present
    return ans;
    else{
        ans[0] = mindistance;
        ans[1] = lastCp - firstCp;
    }
    return ans;

}
int main(){ 
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,3);
    insertathead(head,tail,-3);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    printll(head);

    
    cout<<endl;
    printll(head);

    return 0;
}
// 1 2 -3 3 1 
// 3 1  