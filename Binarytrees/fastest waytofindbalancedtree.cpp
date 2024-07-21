//kisi bhi tree ka leftsubtree ya rightsubtree ka absolute difference atmost 1 hai to usko balanced binary tree kehta hai 
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

    if(data==-1){
        return NULL;
    }

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

        if(front==NULL){
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
int height(Node* root,bool& isbalanced){
    if(root == nullptr) return 0;

    int lh = height(root->left,isbalanced);
    int rh = height(root->right,isbalanced);
    if(isbalanced && abs(lh-rh)>1) isbalanced = false;
    return max(lh,rh) + 1;
}
    bool isbalanced(Node* root) {
        // if(root == NULL) return true;

        // int leftsubtree = height(root->left);
        // int rightsubtree = height(root->right);
        // int diff = abs(leftsubtree - rightsubtree);
        
        // bool currdiff = (diff<=1);
        // bool leftnode = isBalanced(root->left);
        // bool rightnode = isBalanced(root->right);

        // if(currdiff && leftnode && rightnode){
        //     return true;
        // }
        // return false;
        bool isbalanced = true;
        height(root,isbalanced);
        return isbalanced;
    }
    int main(){
    Node* root = createtree();
    cout<<"Printing level order traversal : ";
    levelordertraversal(root);
    cout<<endl;
    bool ans = isbalanced(root);
    if(ans){
        cout<<"The tree is balanced"<<endl;
    }
    else{
        cout<<"The tree is not balanced"<<endl;
    }
    return 0;
    }