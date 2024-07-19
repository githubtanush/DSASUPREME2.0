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

    //mein create tree mein baar baar base case lgana bhool jata hu 
    if(data == -1) return NULL;

    Node* root = new Node(data);
    //create left subtree
    root->left = createtree();
    //create right subtree
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
int main(){
    Node* root = createtree();
    levelordertraversal(root);
    return 0;
}
//  10 20 40 -1 -1 50 70 110 -1 -1  111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1  -1