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
void printll(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
bool comparelist(Node*& head,Node*& head2){
    //jab tak head ya head 2 mein se koi null nhi ho jata yeh loop chli rah 
    while(head != NULL && head2 != NULL){
        //Same nhi hai toh false
        if(head->data != head2->data) return false;
        else{
            //Same hai to next krdo
            head = head->next;
            head2 = head2->next;
        }
    }
    //last tak aaya matlab return true;
    return true;
}
Node* reverseusingrecursion(Node*& prev,Node*& curr){
    //base case agr curr null hua to return prev kyuki vo sb linked list bn gya hoga
    if(curr == NULL) return prev;

    //1 case mein solve krunga baaki recursion
    //nextnode ke andar current ka next store krwaya
    //Step 1 yehi tha
    Node* nextNode = curr->next;
    //Step 2 = curr ke next ko prev se link kra diya
    curr->next = prev;
    //Step 3 = prev ko curr ke brabar kr diya taaki link na toote curr ko nextnode ke brabar krne se pehle
    prev = curr;
    //Step 4 = curr ko nextnode ke brabar kr diya
    curr = nextNode;

    //ab baaki recursion chacha sambhaalenge
    return reverseusingrecursion(prev,curr);
}
Node* middleNode(Node*& head){
    //again slow and fast pointer approach
    //slow is dependent on fast
    Node* slow = head;
    Node* fast = head;
    //jab tak fast->next != NULL nhi ho jata estarah vo mid par aana se pehle uski previous node par hi ruk jayga
    while(fast->next != NULL){
        fast = fast->next;
        //edhar bhi dekhenge fast ka next null to nhi hai 
        if(fast->next != NULL){
            fast = fast->next;
            //fast do baar chl gya matlab mein ab slow ko ek baar chla skta hu turu
            slow = slow->next;
        }
    }
    //Return krdenge slow ko jo mid node se prev node par khra hua hai
    return slow;
}
bool ispalindrome(Node*& head){
    //Break into 2 halves 
    //and find the head for second halve
    Node* midNode= middleNode(head);
    //new head bnayanga kyuki hme mid mil gya hai
    Node* head2 = midNode->next;
    //ab yeh hmara pass do head with 2 linked list aa gay 
    //ab hm reverse krenge 2nd linked list ko 
    //Reverse krna ka liye phir vohi prev curr pointer approach
    Node* prev = NULL;
    Node* curr = head2;
    head2 = reverseusingrecursion(prev,curr);
    //now ab hmm dono linked list ko compare krenge
    bool ans = comparelist(head,head2);
    return ans;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,2);
    insertathead(head,tail,3);
    insertathead(head,tail,4);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    printll(head);
    bool ans = ispalindrome(head);
    if(ans) cout<<"Valid Palindrome"<<endl;
    else cout<<"not a valid palindrome"<<endl;
    return 0;
}