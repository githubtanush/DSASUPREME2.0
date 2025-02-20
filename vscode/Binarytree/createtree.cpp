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

    //base case
    if(data == -1) return NULL;

    //create new node initialize with data
    Node* root = new Node(data);
    //for the left side of the root node
    cout<<"Enter the data for the left of node "<<data<<" : ";
    root->left = createtree();
    //for the right side of the root node
    cout<<"Enter the data for the right of node "<<data<<" : ";
    root->right = createtree();

    //return krdo root nu 
    return root;

}
void preorder(Node*& root){
    //base case
    if(root == NULL) return ;

    //print krdo
    cout<<root->data<<" ";
    //left mein jata hai
    preorder(root->left);
    //right mein jata hai 
    preorder(root->right);
}
void postordertraversal(Node*& root){
    //base case
    if(root == NULL) return ;

    //left traversal
    postordertraversal(root->left);
    //right traversal
    postordertraversal(root->right);
    //print krte h 
    cout<<root->data<<" ";

}
void inordertraversal(Node*& root){
    //base case
    if(root == NULL) return ;

    //left vala case
    inordertraversal(root->left);
    //print krte hai 
    cout<<root->data<<" ";
    //right vala case
    inordertraversal(root->right);

}
void levelordertraversal(Node*& root){
    // queue bna la Node store karan lyi
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
int maxdepth(Node*& root){
    //base case
    if(root == NULL) return 0;

    //left subtree depth
    int leftsubtree = maxdepth(root->left);
    //right subtree depth
    int rightsubtree = maxdepth(root->right);
    //length of the tree
    int length = max(leftsubtree,rightsubtree);

    //return krdo
    return length+1;
}
int maxdepthlot(Node*& root){
    //base case
    if(root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            if(!q.empty()){
                count++;
                q.push(NULL);
            }
        }
        else{
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

    }
    return count;
}
int diameter(Node*& root){
    if(root == NULL) return 0;

    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = maxdepth(root->left) + maxdepth(root->right);

    return max(option1,max(option2,option3));
}
int main(){
    cout<<"Enter the value for node : ";
    Node* root = createtree();

    //preorder traversal of the Tree is : 
    cout<<"Preorder Traversal ";
    preorder(root);
    //inorder traversal of the Tree is : 
    cout<<endl<<"Inorder Traversal ";
    inordertraversal(root);
    //postorder traversal of the Tree is : 
    cout<<endl<<"Postorder Traversal ";
    postordertraversal(root);
    //levelorder traversal of the Tree is : 
    cout<<endl<<"Levelorder Traversal "<<endl;
    levelordertraversal(root);

    //height of the tree is 
    cout<<"Maximum height of subtree is : "<<maxdepth(root)<<endl;
    cout<<"Maximum height of subtree is : "<<maxdepthlot(root)<<endl;
    return 0;
}
// 5 10 15 -1 -1 20 -1 -1 25 30 -1 -1 35 -1 -1 