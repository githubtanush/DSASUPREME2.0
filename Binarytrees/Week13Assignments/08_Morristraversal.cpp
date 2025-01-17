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
    cout<<"Enter the value for the Node : "<<endl;
    int data;
    cin>>data;

    if(data == -1) return NULL;
    Node* root = new Node(data);
    root->left = createtree();
    root->right = createtree();
    return root;
}
vector<int> morristraversal(Node* root){
    vector<int> ans;
    Node* curr = root;
    while(curr){
        //leftnode is NULl , then visit it and go right
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        //left node is not null
        else{
            Node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }
        
        //if pred ka right node is NULL, then go left after establish link from pred to current
        if(pred->right == NULL){
            pred->right = curr;
            curr = curr->left;
        }
        else{
            //left is already visited , go right after visiting current node, while
            pred->right = NULL;
            ans.push_back(curr->data);
            curr = curr->right;
        }
        }
    }
    return ans;
    
}
int main(){
    Node* root = createtree();
    vector<int> ans = morristraversal(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
//1 2 4 -1 -1 5 6 -1 -1 -1 3 7 -1 -1 8 -1 -1