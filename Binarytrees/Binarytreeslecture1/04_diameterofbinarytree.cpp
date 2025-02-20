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
        this->right = NULL;
    }
};
Node* createtree(){
    int data;
    cin>>data;

    if(data == -1) return NULL;

    //create new node
    Node* root = new Node(data);
    // for left side of node
    cout<<"Enter the value for the left side of the node "<<data<<" : ";
    root->left = createtree();
    //for right side of node
    cout<<"Enter the value for the right side of the node "<<data<<" : ";
    root->right = createtree();

    //return krdo root ko
    return root;
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
int height(Node* root){
    //base case
    if(root == NULL) return 0;

    //left subtree ki height find krte hai 
    int leftsubtree = height(root->left);
    //right subtree ki height find krte hai
    int rightsubtree = height(root->right);
    // max of left and right
    int length = max(leftsubtree,rightsubtree);

    return length+1;
}
int diameter(Node* root){
    //base case
    if(root == NULL) return 0;

    //option1 diameter of leftsubtree
    int option1 = diameter(root->left);
    //option2 diameter of rightsubtree
    int option2 = diameter(root->right);
    //option3 find the height of left + right
    int option3 = height(root->left) + height(root->right);
    //find out the maximum diameter
    int diameter = max(option1,max(option2,option3));

    //return the max diameter
    return diameter;

}
int main(){
    cout<<"Enter the value of the root Node : ";
    Node* root = createtree();
    cout<<"Level order traversal of that tree : "<<endl;
    levelordertraversal(root);
    cout<<"Diameter of the tree is : ";
    cout<<diameter(root)<<endl;
    return 0;
}
// 1 2 3 -1 -1 4 -1 -1 5 -1 -1  