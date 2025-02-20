#include<iostream>
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

    if(data == -1) return NULL;

    Node* root = new Node(data);
    root->left = createtree();
    root->right = createtree();
    return root;
}
Node* solve(Node* root,int& k, int node,int& ans){
    if(!root) return 0;
    if(root->data == node) return root;

    if(ans != -1 ) return root; //answer mil jaayga to aaga mat jao 

    auto l = solve(root->left,k,node,ans);
    auto r = solve(root->right,k,node,ans);

    //node yaah hogi
    if(!l && !r) return 0;

    k--;
    if(k==0) ans = root->data;

    if(l && !r) return l;
    else if(!l && r) return r;
    else return root;
}
int kthancestor(Node* root,int& k,int& node){
    int ans = -1;
    solve(root,k,node,ans);
    return ans;
}
int main(){
    Node* root = createtree();
    int k = 2;
    int node = 4;
    int ans = kthancestor(root,k,node);
    cout<<"Kth Ancestor of node is : "<<ans<<endl;
    return 0;
}
//1 2 4 -1 -1 5 -1 -1 3 -1 -1