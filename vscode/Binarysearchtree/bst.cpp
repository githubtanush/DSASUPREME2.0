#include<iostream>
#include<vector>
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
Node* insertintobst(Node* root,int data){
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    //it's not the first node
    if(data > root->data) root->right = insertintobst(root->right,data);
    else root->left = insertintobst(root->left,data);

    return root;
}
void createbst(Node*& root){
    cout<<"Enter the root Node : ";
    int data;
    cin>>data;

    while(data != -1){
        root = insertintobst(root,data);
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

        if(front == NULL){
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
void preorder(Node*& root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node*& root){
    if(root == NULL) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node*& root){
    if(root == NULL) return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = NULL;
    createbst(root);

    cout<<endl<<"Level Order Traversal : ";
    levelordertraversal(root);

    cout<<endl<<"Pre Order Traversal : ";
    preorder(root);

    cout<<endl<<"In Order Traversal : ";
    inorder(root);

    cout<<endl<<"Post Order Traversal : ";
    postorder(root);

    return 0;
}
// 50 30 60 20 40 55 70 80 25 -1