#include<iostream>
#include<map>
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
bool hasCycle(Node*& head){
    map<Node*,bool> table;
    Node* temp = head;
    while(temp != NULL){
        if(table[temp] == false){
            table[temp] = true;
        }
        else{
            //cycle present
            return true;
        }
        temp = temp->next;
    }
    return false;
}
bool checkcycle(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        //check for loop
        if(fast == slow) return true;
    }
    return false;
}
Node* startingloop(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) break;
    }

    slow = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
   
}
void removeloop(Node*& head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) break;
    }

    slow = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    
    Node* startingpoint = slow;
    Node* temp = fast;
    while(temp->next != startingpoint) temp = temp->next;
    temp->next = NULL;
    // return temp;
}
int main(){
    Node* head = NULL;
   Node* first = new Node(34);
   Node* second = new Node(23);
   Node* third = new Node(89);
   Node* fourth = new Node(894);
   Node* fifth = new Node(289);
   Node* sixth = new Node(29);
   Node* seventh = new Node(12);
   
   first->next = second;
   second->next = third;
   third->next = fourth;
   fourth->next = fifth;
   fifth->next = sixth;
   sixth->next = seventh;
    seventh->next = fourth;

    head = first;
    // printll(head);
    if(checkcycle(head)) cout<<"Cycle is present"<<endl;
    else cout<<"Cycle is not present"<<endl;
    cout<<startingloop(head)->data<<endl;
    removeloop(head);
    printll(head);
    return 0;
}