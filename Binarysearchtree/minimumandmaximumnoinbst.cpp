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
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertintobst(root->right,data);
    }
    else{
        root->left = insertintobst(root->left,data);
    }
    return root;
}
Node* createbst(Node*& root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    while(data != -1){
        root = insertintobst(root,data);
        cin>>data;
    }
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
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }

}
Node* minvalue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxvalue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
bool searchinbst(Node* root,int target){
    //base case
    if(root==NULL) return false;

    //1 case mujhe solve krna hoga
    if(root->data == target) return true;

    //baaki recursion sambhal lega
    //left ya right
    bool leftans = false;
    bool rightans = false;
    if(target > root->data) rightans = searchinbst(root->right,target);
    else leftans = searchinbst(root->left,target);

    return leftans || rightans;
}
int main(){
    Node* root = NULL;
    root = createbst(root);
    levelordertraversal(root);
    cout<<"Minimum value of node is : "<<minvalue(root)->data<<endl;
    cout<<"Maximum value of node is : "<<maxvalue(root)->data<<endl;
    bool ans = searchinbst(root,40);
    if(ans) cout<<"Targeted value is present in the tree"<<endl;
    else cout<<"Targeted value is not present in the tree"<<endl;

    return 0;
}