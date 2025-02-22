//kis kam ko krne ka baad vapis jana pd rah hai or kis kaam ko krne ke baad ruk rah ho esse base case bn jayga
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
    cout<<"Enter the value for the node : ";
    int data;
    cin>>data;
    if(data == -1) return NULL;

    Node* root = new Node(data);
    //create left subtree of node
    cout<<"left node of "<<data<<" is : ";
    root->left = createtree();
    //create right subtree of node
    cout<<"right node of "<<data<<" is : ";
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
        else {
            cout<<front->data<<" ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    }
}
void solve(Node* root,int targetSum,vector<vector<int> >& ans,vector<int> temp,int sum){
        //Base case set krdo
        if(root==NULL) return ;

        //1 case solve krna hai 
        sum += root->data;
        temp.push_back(root->data);

        //extra case
        if(root->left==NULL && root->right==NULL){
            //verify
            if(sum==targetSum) ans.push_back(temp);
            else return ;
        }

        solve(root->left,targetSum,ans,temp,sum);
        solve(root->right,targetSum,ans,temp,sum);
    }
    vector<vector<int> > pathSum(Node* root, int targetSum) {
        vector<vector<int> > ans;
        vector<int> temp;
        int sum = 0;
        solve(root,targetSum,ans,temp,sum);
        return ans;
    }
int main(){
    Node* root = createtree();
    cout<<"printing level order traversal : "<<endl;
    levelordertraversal(root);
    int targetsum = 65;
    vector<vector<int> > ans = pathSum(root,targetsum);
    for(int i = 0; i < ans.size();i++){
        for(int j = 0; j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }
    return 0;
}
// 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 5 -1 -1 1 -1 -1