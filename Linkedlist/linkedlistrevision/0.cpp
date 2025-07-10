#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertathead(Node*& head,Node*& tail,int data){
    if(head == NULL){
        //Means starting point of linked now we have starting to made linked list
        //Step 1 - create Node
        Node* newNode = new Node(data);
        //Step 2 - initialize head with the newNode
        head = newNode;
        //Step 3 - initialize tail with the newNode
        tail = newNode;
    }
    else{
        //if(head != NULL)
        //Step1 - create new Node
        Node* newNode = new Node(data);
        //Step 2 - newNode ke aaga se head aayga
        newNode->next = head;
        //Step 3 - head ke piche newNode hogi
        head->prev = newNode;
        //Step 4 - head initialize with newNde
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
void insertattail(Node*& head,Node*& tail,int data){
    if(tail == NULL){
        //Step 1 - create firstly new Node
        Node* newNode = new Node(data);
        //Step 2 - now node is made and only node in full linked list 
        //So initialize head with newNode
        head = newNode;
        //Step 3 - tail initialize with newNode
        tail = newNode;
    }
    else{
        //means tail != NULL
        //Step 1 - create new Node
        Node* newNode = new Node(data);
        //Step 2 - tail is always at the last position 
        //So tail->next = newNode
        tail->next = newNode;
        //Step 3 - newNode ka previous bhi map krdo
        newNode->prev = tail;
        //Step 4 - initialize tail with newNode
        tail = newNode;
    }
}
int length(Node*& head){
    int len= 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertatanypoint(Node*& head,Node*& tail,int data,int pos){
    //if at starting
    int len = length(head);
    if(pos == 1) insertathead(head,tail,data);
    else if(pos > len) insertattail(head,tail,data);
    else{
        //make two pointer for traversing
        Node* previ = NULL;
        Node* curr = head;
        //means neither 1st nor last
        //Step 1 - always like firstly create one node
        Node* newNode = new Node(data);
        //Step 2 - traversing till pos != 1
        while(pos != 1){
            previ = curr;
            curr = curr->next;
            pos--;
        }
        //Step 3 - now prev at before insertion and curr after insertion
        //So newNode->next = curr
        newNode->next = curr;
        //Step 4 - now prev->next = newNode
        previ->next = newNode;
        //Step 5 - curr->prev = newNode
        curr->prev = newNode;
        //Step 6 - newNode->prev = prev;
        newNode->prev = previ;
    }
}
void deletionathead(Node*& head){
    //Step 1 - temporary node
    Node* temp = head;
    //Step 2 - head = head->next
    head = head->next;
    //Step 3 - now temp->next = null
    temp->next = NULL;
    //Step 4 - head prev = null
    head->prev = NULL;
    //Step 5 - delete temp
    delete temp;
}
void deleteattail(Node*& tail){
    //Step 1 - initialize temp
    Node* previ = tail->prev;
    //Step 2 - previ ka next = null
    previ->next = NULL;
    //Step 3 - tail ka prev = null
    tail->prev = NULL;
    //Step 4 - delete tail
    delete tail;
    //Step 5 - tail = previ;
    tail = previ;
}
void deleteatanypoint(Node*& head,Node*& tail,int pos){
    if(head == NULL) 
    {
        cout<<"cannot delete , because LL is empty"<<endl;
        return ;
    }
    int len = length(head);
    if(pos == 1) deletionathead(head);
    else if(pos == len) deleteattail(tail);
    else{
        // delete from middle 
        Node* previ = NULL;
        Node* curr = head;
        while(pos != 1){
            pos--;
            previ = curr;
            curr = curr->next;
        }
        Node* nextNode = curr->next;
        previ->next = nextNode;
        nextNode->prev = previ;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }

}
void reverseusingrec(Node*& head,Node*& prev,Node*& curr){
    //base case
    if(curr == NULL){
        head = prev;
        return ;
    }
    
    //1 case hm solve krenge baaki apna bhai dekh lega
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    
    //baaki to apna chacha sambhalaga
    return reverseusingrec(head,prev,curr);
}
Node* reverse(Node*& head){
    Node* prev = NULL;
    Node* curr = head;
    return head;
}
Node* middleNode(Node*& head){
    int n = length(head);
    int pos = n/2 + 1;
    int currpos = 1;
    Node* temp = head;
    while(pos != 1){
        pos--;
        temp = temp->next;
    }
    return temp;
}
Node* middleNodes(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        //if fast moves 2 step ahead then only slow moves by one step ookkk
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
Node* reversell(Node*& head){
    Node* previ = NULL;
    Node* curr = head;
    while(curr != NULL){
        //Step 1 - make node so that linked list is preserved
        Node* nextNode = curr->next;
        curr->next = previ;
        previ =  curr;
        curr = nextNode;
    }
    // head = previ;
    return previ;
}
bool ispalindrome(Node*& head){
    //create an empty stack to store values
    stack<int> st;
    //initialize temp pointer to head
    Node* temp = head;
    //Traverse the linked list
    while(temp != NULL){
        //push the data from the current node to stack 
        st.push(temp->data);
        //move to the next node
        temp = temp->next;
    }
    //reset the temporary pointer back to the head of the ll
    temp = head;
    //compare values by popping from the stack 
    //and checking against linked list nodes
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        st.pop();
        //move to the next in the ll
        temp = temp->next;
    }
    //if matches all 
    return true;
}
bool comparelist(Node*& head,Node*& head2){
    while(head != NULL && head2 != NULL){
        if(head->data != head2->data) return false;
        else{
            head = head->next;
            head2 = head2->next;
        }
    }
    //last tak aaya true;
    return true;
}
bool ispalindromeornot(Node*& head){
    Node* midNode = middleNode(head);
    Node* head2 = midNode->next;
    midNode->next = NULL;
    Node* previ = NULL;
    Node* curr = head2;
    head2 = reversell(head);
    bool ans = comparelist(head,head2);
    return ans;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,2);
    insertathead(head,tail,3);
    insertathead(head,tail,3);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    cout<<endl;
    // head = reversell(head);
    // printll(head);
    // cout<<endl;
    // head = reverse(head);
    // printll(head);
    // cout<<endl<<middleNodes(head)->data<<endl;
    if(ispalindromeornot(head)) cout<<"ll is palindromic"<<endl;
    else cout<<"ll is not palindromic"<<endl;
    return 0;
}