#include <iostream>
#include <queue>
#include <map>
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
    int data;
    cin>>data;

    if(data == -1) return NULL;

    Node* root = new Node(data);
    cout<<"Enter the data to the left of data "<<root->data<<" : ";
    root->left = createtree();
    cout<<"Enter the data to the right of data "<<root->data<<" : ";
    root->right = createtree();

    return root;
}
void levelordertraversal(Node*& root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
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
void printleftview(Node*& root,int level,vector<int>& leftview){
    if(root == NULL) return;

    if(level == leftview.size()) leftview.push_back(root->data);

    printleftview(root->left,level+1,leftview);
    printleftview(root->right,level+1,leftview);
}
void printrightview(Node*& root,int level,vector<int>& rightview){
    if(root == NULL) return ;

    if(level == rightview.size()) rightview.push_back(root->data);

    printrightview(root->right,level+1,rightview);
    printrightview(root->left,level+1,rightview);
}
void topview(Node*& root){
    map<int,int> hdtonodemap;
    queue<pair<Node*,int> >q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if(hdtonodemap.find(hd) == hdtonodemap.end())
            hdtonodemap[hd] = frontNode->data;

        if(frontNode->left != NULL) q.push(make_pair(frontNode->left,hd-1));
        if(frontNode->right != NULL) q.push(make_pair(frontNode->right,hd+1));
    }
    cout<<"Printing Top View : ";
    for(auto i : hdtonodemap) cout<<i.second<<" ";
}
void bottomview(Node*& root){
    map<int,int> hdtonodemap;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        hdtonodemap[hd] = frontNode->data;

        if(frontNode->left) q.push(make_pair(frontNode->left,hd-1));
        if(frontNode->right) q.push(make_pair(frontNode->right,hd+1));
    }

    cout<<"Printing bottom view : ";
    for(auto i : hdtonodemap) cout<<i.second<<" ";
}

void printleft(Node*& root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return ;

    cout<<root->data<<" ";
    if(root->left != NULL) printleft(root->left);
    else printleft(root->right);

}
void printleaf(Node*& root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL)
        cout<<root->data<<" ";
    
    printleaf(root->left);
    printleaf(root->right);

}
void printright(Node*& root){
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return ;

    if(root->right != NULL) printright(root->right);
    else printright(root->left);

    cout<<root->data<<" ";
}
void boundarytraversal(Node*& root){
    if(root == NULL) return ;

    cout<<endl<<"Boundary traversal : ";
    cout<<root->data<<" ";
    printleft(root->left);
    printleaf(root->left);
    printleaf(root->right);
    printright(root->right);
}
int main(){
    cout<<"Enter the data for root node : ";
    Node* root = createtree();

    cout<<endl<<"Level Order Traversal for this tree is : "<<endl;
    levelordertraversal(root);
    
    cout<<"Printing Left View of the tree : ";
    vector<int> leftview;
    printleftview(root,0,leftview);
    for(int i : leftview) cout<<i<<" ";

    cout<<endl<<"Printing Right View of the tree : ";
    vector<int> rightview;
    printrightview(root,0,rightview);
    for(int i : rightview) cout<<i<<" ";

    cout<<endl;
    topview(root);

    cout<<endl;
    bottomview(root);

    boundarytraversal(root);

    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1  111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1  -1