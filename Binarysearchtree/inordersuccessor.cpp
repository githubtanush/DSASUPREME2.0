// 1st way - inorder traversal - vector stored
// then  Linear search or binary search(firstvalue > x)
//Time complexity - O(N) or O(LogN) space complexity - O(N)

//2nd way - Perform inorder traversal and we will find 1st value > x will be the answer.
 // Time Complexity - O(N)(Recursion) space complexity - O(N) or O(1)(Morris traversal)

//3rd way - Property binary search tree left node lesser than current node and right node greater than current node

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
Node* createbst(Node*& root,int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    //it's time for recursion
    if(data > root->data){
        root->right = createbst(root->right,data);
    }
    else{
        root->left = createbst(root->left,data);
    }
    return root;
}
void createbst(Node*& root){
    cout<<"Enter data : "<<endl;
    int data;
    cin>>data;
    while(data != -1){
        root = createbst(root,data);
        cin>>data;
    }
}
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(!front){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}
Node* inordersuccessor(Node* root,Node* x){
    Node* succ = 0;
    Node* curr = root;
    while(curr){
        if(curr->data > x->data){
            succ = curr;
            curr = curr->left;
        }
        else curr = curr->right;
    }
    return succ;
}
void inorder(Node* root){
    if(root == NULL) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root = NULL;
    createbst(root);
    levelordertraversal(root);
    inorder(root);
    return 0;
}