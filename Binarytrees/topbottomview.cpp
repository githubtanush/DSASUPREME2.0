#include<iostream>
#include<queue>
#include<map>
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

    //mein create tree mein baar baar base case lgana bhool jata hu 
    if(data == -1) return NULL;

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

        if(front == NULL){
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
void printtopview(Node* root){
    map<int,int> hdtoNodemap;
    queue<pair<Node*,int> >q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //if there is no empty for hd in map then create a new entry
        if(hdtoNodemap.find(hd)==hdtoNodemap.end()){
            hdtoNodemap[hd] = frontNode->data;
        }
        //child ko dekhna hai
        if(frontNode ->left != NULL) q.push(make_pair(frontNode->left,hd-1));
        if(frontNode -> right != NULL) q.push(make_pair(frontNode->right,hd+1));

    }
    cout<<"Printing top view : ";
    for(auto i : hdtoNodemap){
        cout<<i.second<<" ";
    }

}

void printbottomview(Node* root){
    map<int,int> bottom;
    queue<pair<Node*,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int bottome = temp.second;

        //overwrite value of bottom to find bottom view of a tree
        bottom[bottome] = frontNode->data;

        if(frontNode->left != NULL) q.push(make_pair(frontNode->left,bottome-1));
        if(frontNode->right != NULL) q.push(make_pair(frontNode->right,bottome+1));
    }
    cout<<"Printing Bottom View : ";
    for(auto i : bottom){
        cout<<i.second<<" ";
    }

}
int main(){
    Node* root = createtree();
    levelordertraversal(root);
   printtopview(root);
   printbottomview(root);
    return 0;
}
//  10 20 40 -1 -1 50 70 110 -1 -1  111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1  -1