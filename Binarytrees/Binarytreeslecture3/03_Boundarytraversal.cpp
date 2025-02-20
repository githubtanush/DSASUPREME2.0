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
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    }

}
//Boundary traversal
//step 1 - print left boundary
//step 2 - print leaf boundary
//step 3  - print right boundary

void printleftboundary(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return ;

    cout<<root->data<<" ";
    if(root->left!= NULL) printleftboundary(root->left);
    else printleftboundary(root->right);
}
void printleafboundary(Node* root){
    if(root == NULL ) return ;

    if(root->left == NULL && root->right == NULL) cout<<root->data<<" ";
    printleafboundary(root->left);
    printleafboundary(root->right);
}
void printrightboundary(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return ;

    if(root->right != NULL) printrightboundary(root->right);
    else printrightboundary(root->left);
    cout<<root->data<<" ";
}
// void boundarytraversal(Node* root){
//     if(root == NULL) return ;

//     printleftboundary(root);
//     printleafboundary(root);
//     if(root->right != NULL)
//         printrightboundary(root->right);
//     else printrightboundary(root->left);
// }
void boundarytraversal(Node* root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    printleftboundary(root->left);
    printleafboundary(root->left);
    printleafboundary(root->right);
    printrightboundary(root->right);
}
int main(){
    Node* root = createtree();
    levelordertraversal(root);
    boundarytraversal(root);
    return 0;
}
//  10 20 40 -1 -1 50 70 110 -1 -1  111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1  -1