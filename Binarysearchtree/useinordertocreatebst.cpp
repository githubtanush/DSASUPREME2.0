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
int main(){
    // Node* root = NULL;
    // createbst(root);
    // levelordertraversal(root);
    int inorder[] = {10,20,30,40,50,60,70};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node* root = bstfrominorder(inorder,start,end);
    levelordertraversal(root);
    return 0;
}