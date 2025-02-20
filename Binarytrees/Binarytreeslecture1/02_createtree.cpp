#include<iostream>
#include<queue>
using namespace std;
class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* createtree(){
    cout<<"Enter the value for the Node : ";
    int data;
    cin>>data;

    //base case
    if(data == -1) return NULL;

    //step1 = create node
    Node* root = new Node(data);
    //step2 - crate left subtree
    // cout<<"Enter the value for the left of node : "<<data<<endl;
    root->left = createtree();
    //step3 - create right subtree
    // cout<<"Enter the value for the right of node : "<<data<<endl;
    root->right = createtree();

    return root;

}
void preordertraversal(Node* root){
    //base condition
    if(root==NULL) return ;

    //node print kro 
    cout<<root->data<<" ";
    //left part ko process kro 
    preordertraversal(root->left);
    //right part ko process kro 
    preordertraversal(root->right);
}
void inordertraversal(Node* root){
    //base condition
    if(root==NULL) return ;

    //left part ko process kro 
    inordertraversal(root->left);
    //node print kro 
    cout<<root->data<<" ";
    //right part ko process kro 
    inordertraversal(root->right);
}
void postordertraversal(Node* root){
    //base condition
    if(root==NULL) return ;

    //left part ko process kro 
    postordertraversal(root->left);
    //right part ko process kro 
    postordertraversal(root->right);
    //node print kro 
    cout<<root->data<<" ";
}
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else{
            // valid node vala case
            cout<<front->data<<" ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);

        }
    }
}
int main(){
    Node* root = createtree();
    cout<<endl;
    cout<<"printing preorder traversal : ";
    preordertraversal(root);
    cout<<endl;
    cout<<"printing inorder traversal : ";
    inordertraversal(root);
    cout<<endl;
    cout<<"printing postorder traversal : ";
    postordertraversal(root);
    cout<<endl;
    cout<<"level order traversal : ";
    levelordertraversal(root);
    return 0;
}
// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1