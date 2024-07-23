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

    //it's not the first root recursion chacha
    if(data > root->data) root->right = insertintobst(root->right,data);
    else root->left = insertintobst(root->left,data);
    return root;
}
void createbst(Node*& root){
    cout<<"Enter Data : ";
    int data;
    cin>>data;
    while(data != -1){
       root =  insertintobst(root,data);
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
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}
int kthsmallestelement(Node* root,int& k){
    if(root==NULL) return -1;

    //LNR
    //L
    int leftans = kthsmallestelement(root->left,k);
    if(leftans != -1) return leftans;

    //N
    k--;
    if(k==0) return root->data;

    //R
    int rightans = kthsmallestelement(root->right,k);
   return rightans;

}
int main(){
    Node* root = NULL;
    createbst(root);
    levelordertraversal(root);
    int k;
    cout<<"Enter which smallest element till you travel : ";
    cin>>k;
    int answer = kthsmallestelement(root,k);
    cout<<"The kth smallest element is : "<<answer<<endl;
    return 0;
}
// 5 3 6 2 4 1 -1 k = 3
