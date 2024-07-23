#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertintobst(Node*& root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    } 

    //it's not the first root recursion chacha
    if(data > root->data) root->right = insertintobst(root->right,data);
    else root->left = insertintobst(root->left,data);
    return root;
}
void createbst(Node*& root){
    cout<<"Enter Data : ";
    int data;
    cin>>data;
    while(data != -1){
       root =  insertintobst(root,data);
        cin>>data;
    }
}
void levelordertraversal(Node*& root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(!front){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}
Node* bstfrominorder(int inorder[],int s,int e){
    //base case
    if(s > e) return NULL;
    //1 case solve krna hai 
    int mid = (s + e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);
    
    //recursion chacha
    root->left = bstfrominorder(inorder,s,mid-1);
    root->right = bstfrominorder(inorder,mid+1,e);
    return root;
}
Node* convertdlltobst(Node*& head,int n){
    //base case
    if(head == NULL || n <= 0) return NULL;

    //LNR
    //L
    Node* leftsubtree = convertdlltobst(head,n/2);
    //N
    Node* root = head;
    root->left = leftsubtree;
    //head update
    head = head->right;

    //R
    Node* rightsubtree = convertdlltobst(head,n-n/2-1);
    root->right = rightsubtree;
    return root;
}
int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->right = third;
    second->left = first;
    third->left = second;

    Node* head = first;
    // 10<->20<->30

    Node* root = convertdlltobst(head,3);
    levelordertraversal(root);
    
   
    return 0;
}