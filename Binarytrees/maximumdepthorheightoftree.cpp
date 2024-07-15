//height of tree
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
    cout<<"Enter the value for the node : ";
    int data;
    cin>>data;

    //base case
    if(data==-1) return NULL;

    Node* root = new Node(data);
    root->left = createtree();
    root->right = createtree();
    return root;
}
// int maxdepth(Node* root){
// //base case
// if(root==NULL) return 0;
 
//  //recursive call for left root
//  int leftsubtree = maxdepth(root->left);
//  int rightsubtree = maxdepth(root->right);
//  int length = max(leftsubtree,rightsubtree);
//  return length+1;
// }

int maxdepthwithlevelordertraversal(Node* root){
    if(root==NULL) return 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                count++;
            q.push(NULL);
            }
        }
        else{
            // valid node vala case
            cout<<front->data<<" ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);

        }
    }
    return count;
}
int main(){
    Node* root = createtree();
    cout<<endl;
    int answer = maxdepthwithlevelordertraversal(root);
    cout<<"Maximum depth for binary tree is : "<<answer<<endl;
    return 0;
}
// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1