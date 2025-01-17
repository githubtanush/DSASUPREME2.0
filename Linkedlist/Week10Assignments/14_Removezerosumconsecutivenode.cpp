#include<iostream>
#include<unordered_map>
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
void sanitizemap(Node* head,unordered_map<int,Node*>& mp,int csum){
        int temp = csum;
        while(true){
            temp  += head->data;
            //jidha temp sum csum ke brabar hua break kr do
            if(temp == csum) break;
            //or map ke andar se remove krdo uska data
            mp.erase(temp);
            //head ko uska next krlo
            head = head->next;
        }
}
Node* removezerosum(Node* head){
    //agr head null hai ya single node hai or 0 hai to return null krna
    if(!head || (!head->next && head->data == 0)) return 0;

    unordered_map<int,Node*> mp;
    Node* it = head;
    int csum = 0;
    while(it){
        csum += it->data;
        if(csum == 0){
            head = it->next;
            mp.clear();
        }
        else if(mp.find(csum) != mp.end()){
            sanitizemap(mp[csum]->next,mp,csum);
            mp[csum]->next = it->next;
        }
        else{
            mp[csum] = it;
        }
        it = it->next;
    }
    return head;
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

    head = removezerosum(head);
    cout<<endl;
    printll(head);

    return 0;
}
// 1 2 -3 3 1 
// 3 1  