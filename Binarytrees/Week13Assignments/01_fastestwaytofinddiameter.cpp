#include<iostream>
#include<queue>
using namespace std;
class Node{
    public : 
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
    cout<<"Enter the value for the Node : ";
    int data;
    cin>>data;

    if(data == -1 ) return NULL;

    //insert the data in Node
    Node* root = new Node(data);
    //create left subtree
    root->left = createtree();
    //create right subtree
    root->right = createtree();

    //root ko return krdo
    return root;
}
int height(Node* root ,int D){
    if(!root) return 0;

    int lh = height(root->left,D);
    int rh = height(root->right,D);
    int currD = lh + rh;
    D = max(D,currD);
    return max(lh,rh) + 1; 
}
int diameterofbinarytree(Node* root){
    int D = 0;
    height(root,D);
    return D;
}
int main(){
    Node* root = createtree();
    int answer = diameterofbinarytree(root);
    cout<<"Maximum Diameter of binary tree is : "<<answer<<endl;
    return 0;
}