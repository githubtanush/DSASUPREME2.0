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
Node* mergetwolists(Node* left,Node* right){
    //agrr left hua hi  nhi toh
    if(left == 0) return right;
    //or agr right nhi hua toh
    if(right == 0) return left;

    //ek new listnode bna lo
    //jisme hm ans ko store krenge
    Node* ans = new Node(-1);

    //now ek mera pointer bnaya jisko meini 1 par daal diya
    Node* mptr = ans;

    //jab tk en dono mein se kuch bhi pda hai tab tak loop chlti rehni chahiye
    while(left && right){
        if(left->data <= right->data){
            //agr left ka data right ke data se km hai toh mujhe use nyi linkedlist mein daalna tha or sorted krke daalna to value abhi yaah km thi
            // left mein  to pehle usko insert kiya
            //mptr ke next ko left se kr diya
            mptr->next = left;
            //mptr ko left par hi khra kr diya
            mptr = left;
            //left ko uske next par le gay
            left = left->next;
        }
        else{
            //matlab right ka data left se chota hai so 
            //mptr ka next right ka equal kr diya
            mptr->next = right;
            //mptr ko right par hi le aayenge
            mptr = right;
            //then right ko uske ek aaga bda denge
            right = right->next;
        }
    }
    //ab while ke baar aagya ab jo bch gya usko insert kr denge
    //yeh linked list so agr koi list null nhi hai chup chap use link kar do while loop lgana ki need hi nhi
    if(left){
        mptr->next = left;
        // ab dhyan se dekho hme en do step ki need hi nhi kyuki jo linked list bchi hai bss usko connect krdo ab
    //     mptr = left;
    //     left = left->next;
    }
    if(right){
        mptr->next = right;
        // mptr = right;
        // right = right->next;
    }
    return ans->next;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,5);
    insertathead(head,tail,3);
    insertathead(head,tail,1);
    printll(head);

    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertathead(head2,tail2,5);
    insertathead(head2,tail2,4);
    insertathead(head2,tail2,2);
    cout<<endl;
    printll(head2);

    Node* ans = mergetwolists(head,head2);
    cout<<endl;
    printll(ans);
    return 0;
}
// 1 3 5 
// 2 4 5 
// 1 2 3 4 5 5