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

    if(data==-1) return NULL;

    Node* root = new Node(data);
    //create left subtree
    root->left = createtree();
    //create right subtree
    root->right = createtree();

    return root;
}
bool solve(Node* root,int targetsum,int sum){
    //base case
    if(root == NULL) return false;

    sum += root->data;
    if(root->left==NULL && root->right == NULL){
        //i am currently standing on the leaf node
        if(sum==targetsum) return true;
        else return false;
    }

    bool leftans = solve(root->left,targetsum,sum);
    bool rightans = solve(root->right,targetsum,sum);
    return leftans || rightans;
}
bool haspathsum(Node* root,int targetsum){
    int sum = 0;
    bool ans = solve(root,targetsum,sum);
    return ans;
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
    cout<<"Level Order Traversal : ";
    levelordertraversal(root);
    int targetsum = 22;
    bool ans = haspathsum(root,targetsum);
    if(ans){
        cout<<"path is exist "<<endl;
    }
    else{
        cout<<"path does not exist"<<endl;
    }

    
    return 0;
}
// 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1  4 -1 1 -1 -1
