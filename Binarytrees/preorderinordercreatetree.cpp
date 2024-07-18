#include<iostream>
#include<queue>
#include<map>
using namespace std;
//create tree from preorder and inorder
class Node {
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

void createmapping(int inorder[],int size,map<int,int>& valuetoindexmap){
    for(int i = 0; i < size;i++){
        int element = inorder[i];
        int index = i;
        valuetoindexmap[element] = index;
    }
}

int searchinorder(int inorder[],int size,int target){
    for(int i = 0; i < size;i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
}
//map searching O(1) mein kr deta agr mein voh use krlu toh searching ko jo n time mil rah hai vo nhi milega
//bhaiya ne bhut jaada focus krna ko bola ke preindex ko by refrence pass krna hai 
Node* constructtreefrompreandinordertraversal( map<int,int> valuetoindexmap,int preorder[],int inorder[],int& preindex,int inorderstart,int inorderend,int size){
    //base case
    if(preindex>=size || inorderstart > inorderend){
        return NULL;
    }

    //1 case mein solve krta hu 
    int element = preorder[preindex];
    preindex++;
    Node* root = new Node(element);  
    //element search krna pdega inorder mein
    // int position = searchinorder(inorder,size,element);
    int position = valuetoindexmap[element];
    //baaki toh recursion chacha jii sambhal hi lenge
    root->left = constructtreefrompreandinordertraversal(valuetoindexmap,preorder,inorder,preindex,inorderstart,position-1,size);
    //right mein bhi dekh lete hai 
    root->right = constructtreefrompreandinordertraversal(valuetoindexmap,preorder,inorder,preindex,position+1,inorderend,size);
    return root;
}
int main(){
    // Node* root = createtree();
    // cout<<"Printing the level order traversal : ";
    // levelordertraversal(root);
    int preorder[] = {2,8,10,6,4,12};
    int inorder[] = {10,8,6,2,4,12};
    int size = 6;
    int preorderIndex = 0;
    int inorderstart = 0;
    int inorderend = 5;
    map<int,int> valuetoindexmap;
    createmapping(inorder,size,valuetoindexmap);
    Node* root = constructtreefrompreandinordertraversal(valuetoindexmap,preorder,inorder,preorderIndex,inorderstart,inorderend,size);
    cout<<"Printing the level order traversal : ";
    levelordertraversal(root);
    return 0;
}
//preorder = 2 8 10 6 4 12
//inorder = 10 8 6 2 4 12
// 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1