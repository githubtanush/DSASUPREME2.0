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
int length(Node*& head){
    //Step 1 - pehle mein ek jaali temporary pointer bna dena taaki mere head ch koi dikkat na aava ta oh apni jagah te rah 
    // kyuki maanu bacho vi ohdi value di lodd pa skdi hai 
    Node* temp = head;
    //ek variable bnana length name da taaki length find kr ska okkkk
    int length = 0;
    //mein eh loop td tak chlaunga jab tak null nhi aa janda jida hi null aaya oh aaga nhi aayga ta oh hi apni length di value hoygi
    while(temp!=NULL){
        //length lagatar bdd rhi hai 
        length++;
        //pointer next nu assign ho reha
        temp = temp->next;
    }
    //length return krti hai 
    return length;
}
void printll(Node*& head){
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
void insertathead(Node*& head,Node*& tail,int data){
    //Agr head null hoya phir 
    if(head==NULL){
        //step 1 - create new node
        Node* newNode = new Node(data);
        //step 2 - kyuki head null si esliye head nu vi new node de brabar kr de and also tere kol tail vi byrefrence aa reha ta ohnu vi update kr de
        head = newNode;
        tail = newNode;
        //finished agr head tail null si taah bss ehna hi hai 
    }
    else{
        //step 1 = create new node
        Node* newNode = new Node(data);
        //step 2  = newNode de next nu mein head naal attach kr dena
        newNode->next = head;
        //step 3 = mein head nu hi new node bna dena
        head = newNode;
    }
}
// Node* middleNode(Node*& head){
//     int len = length(head);
//     //Meini mid node tak ki length nikal li 
//     //Step 1 = find length of node till mid
//     int position = len/2 + 1;
//     //step 2 = take currposition vector which initiate from 1
//     int currpos = 1;
//     //step 3 = ek new node bnayenge temp ki jo iterate kregi 
//     Node* temp = head;
//     //Step 4 - mein tab tk iterate krunga jab tak meri currentpos pos ke brabar nhi ho jaati
//     // while(currpos != position){
//     //     currpos++;
//     //     //mein temp ko aaga move krunga
//     //     temp = temp->next;
//     // }
//     //2nd way to iterate loop just similar 
//     while(position != 1){
//         position--;
//         temp = temp->next;
//     }
//     // jidhar aa gya vo  return kr dunga kyuki eska matlab hai vo mid par aa chuki hai 
//     return temp;
// }

//2nd approach to find the middle of node is very important by using slow and fast pointer/tortoise algo
Node* middleNode(Node*& head){
    //es algo mein slow vala pointer ek step se aaga bdta hai toh 
    //fast vala pointer 2 step se aaga bdta hai 
    //or slow vala pointer usi case mein aaga ja skta hai jab 
    //fast vala pointer aaga bd skta hai nhi to slow vala 
    //aaga nhi jaata

    //asa esliye agr maanlo slow covers x km in 1 hr and 
    //fast cover 2x km in 1 hr
    //to slow to mid par hi hua naa

    //make two pointers slow and fast
    //traversing start from same position
    //but fast pointer moves with 2x and slow with x
    //Step 1 - create slow and fast pointer and initialize with head
    Node* slow = head;
    Node* fast = head;

    //Step 2 - jab tak fast null par nhi aata tab tak toh chlna hi chahiye
    // esliye
    while(fast != NULL){
        //jab tak fast null nhi hai tab tak fast ko fast ka next krte jao
        fast = fast->next;
        //hmne 2 step chlna hai toh dusra step chlna se pehle bhi 
        //yeh to check krenge 
        //naa ki aaga jayga ya nhi 
            if(fast != NULL){
                fast = fast->next;
                //ab hmm yeh keh skte hai ki fast ne 2 step chl liye 
                //matlab ab slow chl skta hai 
                //now there is green flag for slow pointer
                slow = slow->next;
            }
    }
    //loop chlta jaaygi or vaah rukagi jaah fast khatam ho jayga fast khatam matlab slow mid par phunch gya hoga
    // to return krdo slow kko
    return slow;

}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,98);
    insertathead(head,tail,89);
    insertathead(head,tail,29);
    insertathead(head,tail,37);
    insertathead(head,tail,47);
    insertathead(head,tail,82);
    insertathead(head,tail,10);
    printll(head);
    Node* temp = middleNode(head);
    cout<<endl;
    cout<<"Middle node of this linked list is : "<<temp->data<<endl;
    return 0;
}