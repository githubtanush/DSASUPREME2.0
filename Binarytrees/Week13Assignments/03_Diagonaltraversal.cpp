#include<iostream>
#include<queue>
#include<vector>
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
    //create leftsubtree
    root->left = createtree();
    //create rightsubtree
    root->right = createtree();

    return root;
}

vector<int> diagonaltraversal(Node* root){
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp){
            ans.push_back(temp->data);
            if(temp->left){
                //baad mein dekhta hai 
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}
int main(){
    Node* root = createtree();
    cout<<endl;
    vector<int> ans = diagonaltraversal(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
// 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1