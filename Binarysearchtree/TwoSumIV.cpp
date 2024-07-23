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
void storeinorder(Node* root,vector<int>& inorder){
    //base case
    if(root == NULL) return ;

    //LNR
    //L
    storeinorder(root->left,inorder);
    //N
    inorder.push_back(root->data);
    //R
    storeinorder(root->right,inorder);
}
bool findtarget(Node* root,int k){
    vector<int> inorder;
    storeinorder(root,inorder);
    
    //Find target sum using 2 pointer approach 
    int s = 0;
    int e = inorder.size()-1;

    while(s < e){
        int sum = inorder[s] + inorder[e];
        if(sum==k) return true;
        else if(sum > k) e--;
        else s++;
    }
    return true;
}
int main(){
    Node* root = NULL;
    createbst(root);
    levelordertraversal(root);
    int k ;
    cout<<"Enter the targeted sum : ";
    cin>>k;
    bool answer = findtarget(root,k);
    if(answer) cout<<"Targeted sum is present in this array"<<endl;
    else cout<<"Targeted sum is not present in this array"<<endl;
    return 0;
}
// 5 3 6 2 4 7 -1
// k = 9