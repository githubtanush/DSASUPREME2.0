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
int maxdepthheight(Node* root){
    if(root==NULL) return 0;

    int leftheight = maxdepthheight(root->left);
    int rightheight = maxdepthheight(root->right);
    int finalans = max(leftheight,rightheight) + 1;
    return finalans;
}
bool isbalanced(Node* root){
    if(root==NULL) return true;
    
    //currNode - solve
    int leftheight = maxdepthheight(root->left);
    int rightheight = maxdepthheight(root->right);
    int diff = abs(leftheight - rightheight);

    bool currdiff = (diff <= 1);
    bool leftans = isbalanced(root->left);
    bool rightans = isbalanced(root->right);

    if(currdiff && leftans && rightans){
        return true;
    }
    else{
        return false;
    }
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
//3 9 -1 -1 20 15 -1 -1 7 -1 -1 