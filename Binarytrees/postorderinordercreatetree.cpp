#include<iostream>
#include<queue>
#include<map>
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
void createmapping(int inorder[],int size,map<int,int>& valuetoindexmap){
for(int i = 0; i < size;i++){
        int element = inorder[i];
        int index = i;
        valuetoindexmap[element] = index;
    }
}
Node* constructtreefrompostandinorder(map<int,int>& valuetoindexmap,int postorder[],int inorder[],int& postindex,int inorderstart,int inorderend,int size){
    if(postindex<0 || inorderstart>inorderend) return NULL;

    //1 case mein solve krunga baaki recursion dekh lega
    int element = postorder[postindex];
    postindex--;
    Node* root = new Node(element);
    //search kro inorder mein
    int position = valuetoindexmap[element];
    //baaki recursion sambhal lega
    //right ki call pehle lgegi
    root->right = constructtreefrompostandinorder(valuetoindexmap,postorder,inorder,postindex,position+1,inorderend,size);
    root->left = constructtreefrompostandinorder(valuetoindexmap,postorder,inorder,postindex,inorderstart,position-1,size);

    return root;
}
int main(){
    int postorder[] = {8,6,14,4,10,2};
    int inorder[] = {8,14,6,2,10,4};
    int size = 6;
    int postindex = size - 1;
    int inorderstart = 0;
    int inorderend = size - 1;
    map<int,int> valuetoindexmap;
    createmapping(inorder,size,valuetoindexmap);
    Node* root = constructtreefrompostandinorder(valuetoindexmap,postorder,inorder,postindex,inorderstart,inorderend,size); 
    levelordertraversal(root);

    return 0;
}
//inorder = 8 14 6 2 10 4
//postorder = 8 6 14 4 10 2