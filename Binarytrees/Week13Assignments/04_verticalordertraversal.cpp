#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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

    if(data == -1 ) return NULL;

    Node* root = new Node(data);
    root->left = createtree();
    root->right = createtree();
    return root;
}
vector<vector<int> > verticalordertraversal(Node* root){
    vector<vector<int> > ans;
    queue<pair<Node*,pair<int,int> > > q; //Node,{row,col};
    q.push({root,{0,0}});
    map<int,map<int,multiset<int> > > mp;
    //col -> {row : [x,y,z]};
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* node = front.first;
        auto coordinate = front.second;
        int& row = coordinate.first;
        int& col = coordinate.second;
        mp[col][row].insert(node->data);
        if(node->left) q.push({node->left,{row+1,col-1}});
        if(node->right) q.push({node->right,{row+1,col+1}});
    }
        //store find vertical order into answer vector
        for(auto it : mp){
            auto& colmap = it.second;
            vector<int> vline;
            for(auto colmapit : colmap){
                auto& mset = colmapit.second;
                vline.insert(vline.end(),mset.begin(),mset.end());
            }
            ans.push_back(vline);
        }
    return ans;
}   
int main(){
    Node* root = createtree();
    vector<vector<int> > ans = verticalordertraversal(root);
    for(auto i : ans){
        for(auto j : i ){
            cout<<j<<" ";
        }
    }

    return 0;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1