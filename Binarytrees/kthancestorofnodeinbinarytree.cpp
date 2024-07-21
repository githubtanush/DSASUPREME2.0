#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL:
    }
};
Node* createtree(){
    cout<<"Enter the value for the Node : ";
    int data;
    cin>>data;

    if(data == -1) return NULL;

    Node* root = new Node(data);
    root->left = createtree();
    root->right = createtree();
    return root;
}
int main(){
    Node* root = createtree();
    return 0;
}