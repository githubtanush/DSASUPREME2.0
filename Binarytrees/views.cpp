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

    if(data==-1) return NULL;
    Node* root = new Node(data);
    //create left subtree
    root->left = createtree();
    //create right subtree
    root->right = createtree();

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
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    } 
}
// try krna level order traversal se left view achieve krne ke liye
void printleftview(Node* root,int level,vector<int>& leftview){
    if(root==NULL) return ;

    if(level == leftview.size()){
        //iska matlab mujhe leftview vali node mil gyi hai 
        leftview.push_back(root->data);
    }
    printleftview(root->left,level+1,leftview);
    printleftview(root->right,level+1,leftview);  
}
int main(){
    Node* root = createtree();
    vector<int> leftview;
    int level = 0;
    levelordertraversal(root);
    cout<<"Printing Left View : "<<endl;
    printleftview(root,level,leftview);
    for(auto i : leftview){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1  111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1  -1