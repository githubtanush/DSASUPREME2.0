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
Node* createtree(){
    cout<<"Enter the value for node : ";
    int data;
    cin>>data;
    
    if(data == -1) return NULL;
    Node* root = new Node(data);
    //create leftsubtree
    root->left = createtree();
    //create rightsubtree
    root->right = createtree();

    return root;
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
            cout<<front->data<<" ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    }
}
Node* lca(Node* root,Node* p,int k){
    if(root == NULL) return NULL;
    if(root->data == p->data) return p;

    Node* leftans = lca(root->left,p,k);
    Node* rightans = lca(root->right,p,k);

    if(leftans == NULL && rightans == NULL) return NULL;
    else if(leftans != NULL && rightans == NULL) return leftans;
    else if(leftans == NULL && rightans != NULL) return rightans;
    return root;
}
int main(){
    Node* root = createtree();
    cout<<"Printing level order traversal : ";
    levelordertraversal(root);
    return 0;
}