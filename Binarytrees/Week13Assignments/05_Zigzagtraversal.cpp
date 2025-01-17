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

    if(data == -1 ) return NULL;

    Node* root = new Node(data);
    root->left = createtree();
    root->right = createtree();
    return root;
}
vector<vector<int> > zigzagtraversal(Node* root){
    vector<vector<int> > ans;
    if(!root) return ans;
    bool ltor = true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int width = q.size();
        vector<int> onelevel(width);
        for(int i = 0; i < width;i++){
            Node* front = q.front();
            //remind this mistake
            q.pop();
            int index = ltor ? i : width-i-1;
            onelevel[index] = front->data;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        //toggle the direction
        ltor = !ltor;
        ans.push_back(onelevel);
    }
    return ans;
}
int main(){
    Node* root = createtree();
    vector<vector<int> > ans = zigzagtraversal(root);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// 3 9 -1 -1 20 15 -1 -1 7 -1 -1