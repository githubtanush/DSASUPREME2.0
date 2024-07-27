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
Node* swapnodes(Node* head,int k){
    // Case 1: null ho toh
    //agr head null hua ya single node hi hui toh
    //return head;
    if(!head || head->next == NULL) return head;


    //mein length find krunga kyuki mujhe lpos rpos bnana hai 
    //or dono ki length height se nikalunga
    //lpos or rightpos nikalanga
    int len = getlength(head);
    int lpos = k;
    int rpos = len-k+1;
    if(rpos < lpos) swap(lpos,rpos);

    //agr lpos or rpos same aa gya toh return krdo head ko;
    //Case 2: lpos==rpos
    if(lpos == rpos) return head;

    //Case 3: when length of linked list == 2;
    if(len==2){
        Node* nextNode = head->next;
        nextNode->next = head;
        head->next = 0;
        head = nextNode;
        return head;
    }
    //Case 4: if k==1 or k==n if(rpos < lpos ) swap(lpos,rpos) in upper 
    if(lpos == 1){
    Node* lp = 0;
    Node* ln = head;
    Node* rp  = head;
    for(int i = 0; i < rpos-2;i++)
        rp = rp->next;
    Node* rn = rp->next;
    Node* rsave = rn->next;

    //Swapping
    rn->next = ln->next;
    rp->next = ln;
    ln->next = rsave;
    head = rn;
    return head;
    }
    
    //Case 5: numberof nodes between swap nodes = 0;
    int noofnodesbetweenswapnodes = rpos-lpos-1;

    if(noofnodesbetweenswapnodes == 0 ){
        //ln and rn are adjacents
        Node* lp = head;
        for(int i = 0; i < lpos-2;i++) lp = lp->next;
        Node* ln = lp->next;

        Node* rp = head;
        for(int i = 0; i < rpos-2;i++) rp = rp->next;
        Node* rn = rp->next;
        Node* rsave = rn->next;
        //Swap 
        lp->next = rp->next;
        rn->next = rp;
        rp->next = rsave;
        return head;
    }
    else{
        //Case 6 :
        // noofnodesbetweenswapnodes >= 1 
        Node* lp = head;
        for(int i = 0; i < lpos-2;i++) lp = lp->next;
        Node* ln = lp->next;
        
        Node* rp = head;
        for(int i = 0; i < rpos-2;i++) rp = rp->next;
        Node* rn = rp->next;
        Node* rsave = rn->next;

        //Swap 
        lp->next = rn;
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;
        return head;
    }

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
    int k = 2;
    head = swapnodes(head,k);
    cout<<endl;
    printll(head);

    return 0;
}

