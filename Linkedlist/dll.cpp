#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->prev = NULL;
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
int len(Node*& head){
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
        //Step 1 - create new node;
        Node* newNode =  new Node(data);
        //Step 2 = head ko newnode assign kr do 
        //tail ko bhi kyuki agr yeh 1st element hai toh tail bhi newnode hi aaygi
        head = newNode;
        tail = newNode;
    }
    else{
        //matlab 1st node null nhi hai 
         //Step 1 - create new node;
        Node* newNode =  new Node(data);
        //Step 2 - newnode ka next head se point krwa do 
        newNode->next = head;
        //Step 3 - head ka prev new node se point krwa do 
        head->prev = newNode;
        //Step 4 - head mein newnode assign kr de
        head = newNode;
    }
}
void insertattail(Node*& head,Node*& tail,int data){
    //agr tail hi null hua toh matlab head hi null hai 1st element aana hai 
    if(head == NULL){
        //Step 1 = create new node
        Node* newNode = new Node(data);
        //Step 2 = head mein newnode assign kr de
        head = newNode;
        //Step 3 = same tail mein kr
        tail = newNode;
    }
    else{
        //matlab already element hai toh
        //Step 1 = create new node
        Node* newNode = new Node(data);
        //Step 2 = tail ko next ko newnode se point krwa de
        tail->next = newNode;
        //Step 3 = newNode ke prev ko tail se point krwa do 
        newNode->prev = tail;
        //Step 4 = tail mein hi newnode ko assign krdo 
        tail = newNode;
    }
}
void insertatanypos(Node*& head,Node*& tail,int position,int data){
    //agr null hua toh 
    if(head == NULL){
        //Step 1 = create new node
        Node* newNode = new Node(data);
        //Step 2 = head mein newnode assign kr de
        head = newNode;
        //Step 3 = same tail mein kr
        tail = newNode;
    }

    int length = len(head);
    if(position==1) insertathead(head,tail,data);
    else if(position > length) insertattail(head,tail,data);
    else{
        //matlab beta ji na hi starting or na hi ending
        //so appoach of prev and current pointer or we can also use only one pointer
        //insert in middle
        //Step 1 = create new node;
        Node* newNode = new Node(data);
        //Step 2 = create two pointers prev and curr 
        //initialize prev with null and curr with head
        Node* previ = NULL;
        Node* curr = head;
        //Step 3 = jab tak position != 1 hai tab tak yeh aaga bdta jayga
        //kyuki 1 par to insert at head chl jayga to agr 2 aayga bhi toh current bss 1 se hi aaga bdega
        while(position != 1){
            position--;
            previ = curr;
            curr = curr->next;
        }
        //Step 4 - khela khelte hai newnode ke sath prev or curr ki madad se
        //pehle newnode ke next ko curr se jordo
        newNode->next = curr;
        //Step 5 - newNode ke prev ko prev ka sath jordo
        newNode->prev = previ;
        //Step 6 = prev ke next ko newnode se jordo 
        previ->next = newNode;
        //Step 7 = curr ke prev ko newnode se jordo
        curr->prev = newNode;
    }
}
void deleteNode(Node*& head,Node*& tail,int position){
    //agr head hi null hua toh
    if(head == NULL){
        cout<<"cannot delete , LL is Empty..."<<endl;
        return ;
    }
    //agr hua hi ek single element toh
    if(head == tail){
        //create one temporary pointer which points head
        //Step 1 = create one temporary node
        Node* temp = head;
        //Step 2 = temp nu delete krdena
        delete temp;
        //Step 3 = now ab mein head nu null kr dunga
        head = NULL;
        //Step 4 = now ab mein tail nu vi null kr dunga
        tail = NULL;
        //Step 5 = return krdunga
        return ;
    }

    //now agr 1st position par delete krna hua toh
    int length = len(head);
    if(position==1){
        //Step 1 = create one temporary pointer
        Node* temp = head;
        //Step 2 = now ab mein head ko temp ka next assign kr dunga
        head = temp->next;
        //Step 3 = temp->next ko null kr dunga
        temp->next = NULL;
        //step 4 = head ke prev ko null kr dunga
        head->prev = NULL;
        //temp ko delete kr dunga
        delete temp;
    }
    else if(position == length){
        //Asaa singly linked list mein krna pdta 
        // //Agr length hi last vali node delete krni hui toh
        // //Step 1 = create one temp 
        // Node* temp = head;
        // //step 2 = traverse before the tail strike
        // while(temp->next != tail ){
        //     temp = temp->next;
        // }
        // //Step 3 = tail ke prev ko null krdo
        // tail->prev = NULL;
        // //step 4 = temp ke next ko null krdo 
        // temp->next = NULL;
        // //Step 5 = delete krdo tail ko 
        // delete tail;
        // //Step 6 = tail ke andar temp ko assign krdo
        // tail = temp;

        //Par kyuki yeh doubly linked list hai toh mujhe traverse krna ki need hi nhi
        //Step 1 = tail ko prev ko ek temporary node se assign krdo
        Node* previ = tail->prev;
        //Step 2 = now ab previ ke next ko null krdo
        previ->next = NULL;
        //Step 3 = now ab tail ke prev ko bhi null krdo
        tail->prev = NULL;
        //Step 4 = tail ko delete krdo 
        delete tail;
        //Step 5 = tail ko temporary par krdo
        tail = previ;
    }
    else{
        //es case mein aa gay  matlab abhi tak to kuch hath na lga na hi 1st element hai naa hi last
        //naa hi single or naa hi null 
        //Element khi bich mein hai matlab now do that
        //Step 1 = make two pointer prev and curr approach
        Node* previ = NULL;
        Node* curr = head;
        //Step 2 = position tak traverse krta hai 
        while(position != 1){
            position--;
            previ = curr;
            curr = curr->next;
        }
        //ab current vo hai jisse delete krna 
        //Step3 = prev ka next mein curr ka next
        previ->next = curr->next;
        //Step 4 = curr ke next ke prev mein prev aana chahiya
        curr->next->prev = previ;
        //Step 5 = curr->next ko null krdo
        curr->next = NULL;
        //Step 6 = curr ke prev ko null krdo 
        curr->prev = NULL;
        //Step 7 = delete current 
        delete curr;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,34);
    insertathead(head,tail,39);
    insertattail(head,tail,29);
    insertattail(head,tail,98);
    insertatanypos(head,tail,3,89);
    deleteNode(head,tail,2);
    int length = len(head);
    cout<<"Length of the Linked list is : "<<length<<endl;
    printll(head);
    return 0;
}