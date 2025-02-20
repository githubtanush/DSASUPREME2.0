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
    int data;
    cin>>data;

    if(data== -1) return NULL;
    Node* root  = new Node(data);
    //create leftsubtree
    root->left = createtree();
    //create rightsubtree
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
Node* lca(Node* root,Node* p,Node* q,int& ans){
    if(root == NULL) return NULL;
    if(root->data == p->data) return p;
    if(root->data == q->data) return q;

    Node* leftans = lca(root->left,p,q,ans);
    Node* rightans = lca(root->right,p,q,ans);

    if(leftans == NULL && rightans == NULL) return NULL;
    else if(leftans != NULL && rightans == NULL) return leftans;
    else if(leftans == NULL && rightans != NULL) return rightans;
    return root;
}
int main(){
    Node* root = createtree();
    cout<<"printing the levelordertraversal : ";
    levelordertraversal(root);
    int data1;
    cin>>data1;
    Node* p = new Node(data1);
    int data2;
    cin>>data2;
    Node* q = new Node(data2);
    int answ = 0;
    Node* ans = lca(root,p,q,answ);
    cout<<ans->data<<" ";
    return 0;
}
// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1