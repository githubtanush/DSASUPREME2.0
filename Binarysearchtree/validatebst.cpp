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
Node* insertintobst(Node*& root,int data){
    if(root == NULL){
        Node* root = new Node(data);
        return root;
    }
    
    if(data > root->data) root->right = insertintobst(root->right,data);
    else root->left = insertintobst(root->left,data);
    return root;
}
void createbst(Node*& root){
    cout<<"Enter data : ";
    int data;
    cin>>data;
    while(data != -1){
       root = insertintobst(root,data);
       cin>>data;
    }
}
void levelordertraversal(Node*& root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(!front){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}
bool solve(Node* root,long long int lowerbound,long long int upperbound){
    //base case
    if(root == NULL) return true;

    bool cond1 = (root->data > lowerbound);
    bool cond2 = (root->data < upperbound);
    bool leftans = solve(root->left,lowerbound,root->data);
    bool rightans = solve(root->right,root->data,upperbound);

    if(cond1 && cond2 && leftans && rightans) return true;
    else return false;
}
bool isvalidbst(Node*& root){
    long long int lowerbound = -2147483657;
    long long int upperbound = 2147483657;
    bool ans = solve(root,lowerbound,upperbound);
    return ans;

}
int main(){
    Node* root = NULL;
    createbst(root);
    levelordertraversal(root);
    bool ans = isvalidbst(root);
    if(ans) cout<<"Tree is valid bst"<<endl;
    else cout<<"Tree is not a valid bst"<<endl;
    return 0;
}
// 50 30 60 20 40 55 70 80 25 -1