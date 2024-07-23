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
Node* insertintoBST(Node*& root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    //its not the first root recursion chacha
    if(data > root->data){
        root->right = insertintoBST(root->right,data);
    }
    else{
        root->left = insertintoBST(root->left,data);
    }
    return root;
}
void levelordertraversal(Node*& root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

    if(front==NULL){
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
Node* createbst(Node*& root){
    cout<<"Enter the root value : ";
    int data;
    cin>>data;
    while(data!= -1 ){
        root = insertintoBST(root,data);
        cin>>data;
    }
    return root;
}
Node* maxvalue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
Node* deletefrombst(Node* root,int target){
    //target ko dhundh lo
    //target ko delete krdo 
    if(root == NULL) return NULL;

    if(target == root->data){
        //ab delete krenge
        //4 case
        //1 case - leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //2 case - left non null right null
        else if(root->left != NULL && root->right == NULL){
            Node* childsubtree = root->left;
            delete root;
            return childsubtree;
        }
        //3 case - left null and right non null
        else if(root->left == NULL && root->right != NULL){
            Node* childsubtree = root->right;
            delete root;
            return childsubtree;
        }
        //4 case - left non null and right non null
        else{
            //a - left subtree ki max value lao 
            Node* maxi = maxvalue(root->left);
            root->data = maxi->data;
            //delete actual max vali node
            root->left = deletefrombst(root->left,maxi->data);
            return root;
        }
    }
    else if(root->data > target){
        //left mein jao 
        root->left = deletefrombst(root->left,target);
    }
    else{
        root->right = deletefrombst(root->right,target);
    }
    return root;
}
int main(){
    Node* root = NULL;
    createbst(root);
    levelordertraversal(root);
    deletefrombst(root,50);
    cout<<endl;
    levelordertraversal(root);
    return 0;
}
// 50 30 60 20 40 55 70 80 25 -1