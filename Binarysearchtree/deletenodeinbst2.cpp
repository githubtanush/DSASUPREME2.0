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
Node* insertintobst(Node*& root,int data){
    if(root == NULL){
        Node* root = new Node(data);
        return root;
    }
    
    if(data > root->data){
        root->right = insertintobst(root->right,data);
    }
    else{
        root->left = insertintobst(root->left,data);
    }
    return root;
}
Node* createbst(Node*& root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    while(data != -1){
        root = insertintobst(root,data);
        cin>>data;
    }
    return root;
}
void levelordertraversal(Node*& root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front==NULL){
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
Node* deleteNode(Node* root, int key) {
        if(!root) return 0;
        if(root->data == key){
            //Case 1 = leaf Node
            if(!root->left && !root->right){
                delete root;
                return 0;
            }
            //Case 2 - left is null but right is non - null
            else if(!root->left){
                auto temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            //Case 3 - right is null but left is non - null
            else if(!root->right){
                auto temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            //Case 4 - left is non - null and also right is non - null
             else{
                //right subtree ka min nikalo
#if 0 //this is called if derivates
                auto rscan = root->right;
                while(rscan->left) 
                    rscan = rscan->left;
                rscan->left = root->left;
                auto temp = root;
                root = root->right;
                delete temp;
                return root;
#endif //this tells code to if end if tak ka code phaltu hai
                //left subtree ka max nikalo
                auto lscan = root->left;
                while(lscan->right) lscan = lscan->right;
                lscan->right = root->right;
                auto temp = root;
                root = root->left;
                delete temp;
                return root;
            }
        }
        else if(key > root->data){
            root->right = deleteNode(root->right,key);
        }
        else{
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
int main(){
    Node* root = NULL;
    root = createbst(root);
    levelordertraversal(root);
    deleteNode(root,40);
    levelordertraversal(root);
    return 0;
}
// 50 30 60 20 40 55 70 80 25 -1