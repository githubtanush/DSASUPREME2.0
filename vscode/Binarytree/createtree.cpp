//yaad rkhi tu root left right krna bhul janda baar baar
#include<iostream>
#include<vector>
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
Node* createtree(){
    int data;
    cin>>data;

    //base case
    if(data == -1) return NULL;

    //create new node initialize with data
    Node* root = new Node(data);
    //for the left side of the root node
    cout<<"Enter the data for the left of node "<<data<<" : ";
    root->left = createtree();
    //for the right side of the root node
    cout<<"Enter the data for the right of node "<<data<<" : ";
    root->right = createtree();

    //return krdo root nu 
    return root;

}
void preorder(Node*& root){
    //base case
    if(root == NULL) return ;

    //print krdo
    cout<<root->data<<" ";
    //left mein jata hai
    preorder(root->left);
    //right mein jata hai 
    preorder(root->right);
}
void postordertraversal(Node*& root){
    //base case
    if(root == NULL) return ;

    //left traversal
    postordertraversal(root->left);
    //right traversal
    postordertraversal(root->right);
    //print krte h 
    cout<<root->data<<" ";

}
void inordertraversal(Node*& root){
    //base case
    if(root == NULL) return ;

    //left vala case
    inordertraversal(root->left);
    //print krte hai 
    cout<<root->data<<" ";
    //right vala case
    inordertraversal(root->right);

}
void levelordertraversal(Node*& root){
    // queue bna la Node store karan lyi
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
int maxdepth(Node*& root){
    //base case
    if(root == NULL) return 0;

    //left subtree depth
    int leftsubtree = maxdepth(root->left);
    //right subtree depth
    int rightsubtree = maxdepth(root->right);
    //length of the tree
    int length = max(leftsubtree,rightsubtree);

    //return krdo
    return length+1;
}
int maxdepthlot(Node*& root){
    //base case
    if(root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            if(!q.empty()){
                count++;
                q.push(NULL);
            }
        }
        else{
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

    }
    return count;
}
int diameter(Node*& root){
    if(root == NULL) return 0;

    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = maxdepth(root->left) + maxdepth(root->right);

    return max(option1,max(option2,option3));
}
bool isbalanced(Node*& root){
    if(root == NULL) return true;

    int leftheight =  maxdepth(root->left);
    int rightheight = maxdepth(root->right);
    int diff = abs(leftheight - rightheight);

    bool curr = (diff <= 1);
    bool lefttree = isbalanced(root->left);
    bool righttree = isbalanced(root->right);

    if(curr && lefttree && righttree) return true;
    else return false;
}
Node* lca(Node* root,Node* p,Node* q,int& ans){
    if(root == NULL) return NULL;
    if(root->data == p->data) return p;
    if(root->data == q->data) return q;

    Node* leftans = lca(root->left,p,q,ans);
    Node* rightans = lca(root->right,p,q,ans);

    if(leftans == NULL && rightans == NULL) return NULL;
    if(leftans != NULL && rightans == NULL) return leftans;
    if(leftans == NULL && rightans != NULL) return rightans;
    return root;
}
// bool solve(Node*& root, int targetsum,int sum){
//     //base case
//     if(root == NULL) return false;

//     sum += root->data;
//     if(root->left == NULL && root->right == NULL){
//         // i am currently at leaf node
//         if(sum == targetsum) return true;
//         else return false;
//     }

//     bool leftans = solve(root->left,targetsum,sum);
//     bool rightans = solve(root->right, targetsum,sum);

//     return leftans || rightans;
// }
// bool haspathsum(Node* root,int targetsum){
//     int sum = 0;
//     bool ans = solve(root,targetsum,sum);
//     return ans;
// }

// void solve(Node*& root, int sum,int targetsum,vector<vector<int> >& ans,vector<int> temp){
//     //base case
//     if(root == NULL) return ;

//     //sum add krte jao
//     sum += root->data;
//     temp.push_back(root->data);

//     if(root->left == NULL && root->right == NULL){
//         if(sum == targetsum) ans.push_back(temp);
//         else return ;
//     }

//     //left / right part to recursion ko hi sambhalna hai 
//     solve(root->left,sum,targetsum,ans,temp);
//     solve(root->right,sum,targetsum,ans,temp);
// }
// vector<vector<int> >pathsum(Node*& root , int targetsum){
//     vector<vector<int> > ans;
//     vector<int> temp;
//     int sum = 0;
//     solve(root,sum,targetsum,ans,temp);
//     return ans;
// }

Node* solve(Node*& root,int& k,int node,int& ans){
    if(!root) return 0;
    if(root->data == node) return root;
    if(ans != -1) return root;

    auto l = solve(root->left,k,node,ans);
    auto r = solve(root->right,k,node,ans);

    if(!l && !r ) return 0;
    k--;
    if(k==0) ans = root->data;
    if(l && !r) return l;
    if(!l && r) return r;
    else return root;                           
}
int kthancestor(Node* root,int& k ,int& node){
    int ans = -1;
    solve(root,k,node,ans);
    return ans;
}

int searchinorder(int inorder[],int size,int target){
    for(int i = 0; i < size;i++)
        if(inorder[i] == target) return i;

    return -1;
}
void createmapping(int inorder[],int size,map<int,int>& valuetoindexmap){
    for(int i= 0; i < size;i++){
        int element = inorder[i];
        int index = i;
        valuetoindexmap[element] = index;
    }
}
Node* constructtreefrompreandinordertraversal(map<int,int> valuetoindexmap,int preorder[],int inorder[],int& preindex,int inorderstart,int inorderend,int size){
    //base case
    if(preindex >= size || inorderstart > inorderend) return NULL;

    //1 case mein solve krta hu 
    int element = preorder[preindex];
    preindex++;
    Node* root = new Node(element);
    //element search kro inorder mein
    // int position = searchinorder(inorder,size,element); 
    //Is we do search in O(1) ? - yes map is a data structure which do in O(1);
    int position = valuetoindexmap[element]; 

    //baaki recursion sambhal lega
    root->left = constructtreefrompreandinordertraversal(valuetoindexmap,preorder,inorder,preindex,inorderstart,position-1,size);
    root->right = constructtreefrompreandinordertraversal(valuetoindexmap,preorder,inorder,preindex,position+1,inorderend,size);

    return root;
}
int main(){
    // cout<<"Enter the value for node : ";
    // Node* root = createtree();

    // //preorder traversal of the Tree is : 
    // cout<<"Preorder Traversal ";
    // preorder(root);
    // //inorder traversal of the Tree is : 
    // cout<<endl<<"Inorder Traversal ";
    // inordertraversal(root);
    // //postorder traversal of the Tree is : 
    // cout<<endl<<"Postorder Traversal ";
    // postordertraversal(root);
    // //levelorder traversal of the Tree is : 
    // cout<<endl<<"Levelorder Traversal "<<endl;
    // levelordertraversal(root);

    //height of the tree is 
    // cout<<"Maximum height of subtree is : "<<maxdepth(root)<<endl;
    // cout<<"Maximum height of subtree is : "<<maxdepthlot(root)<<endl;
    
    // bool answer = isbalanced(root);
    // if(answer) cout<<"Tree is balanced"<<endl;
    // else cout<<"Tree is not balanced"<<endl;

    //lowest common ancestor
    // cout<<"Enter the value for pth node : ";
    // int data1;
    // cin>>data1;
    // Node* p = new Node(data1);
    // cout<<"Enter the value for qth node : ";
    // int data2;
    // cin>>data2;
    // Node* q = new Node(data2);
    // int ans = 0;
    // Node* hi = lca(root,p,q,ans);
    // cout<<hi->data<<" "<<endl;

    // check path sum 1
    // int targetsum;
    // cout<<"Enter the target sum you want to be : ";
    // cin>>targetsum;
    // bool answe = haspathsum(root,targetsum);
    // if(answe) cout<<"Target sum achieved"<<endl;
    // else cout<<"Target sum not achieved"<<endl;


    //path sum 2
    // int targetsum;
    // cout<<"Enter the targeted sum : ";
    // cin>>targetsum;
    // vector<vector<int> > ans = pathsum(root,targetsum);
    // for(auto i : ans) 
    //     for(auto it : i) 
    //         cout<<it<<" ";


    //kth ancestor
    // int data1;
    // cout<<"Enter the data which u want to find : ";
    // cin>>data1;
    // int k;
    // cout<<"Enter which ancestor u find for tree : ";
    // cin>>k;
    // cout<<"kth ancestor of node is : "<<kthancestor(root,k,data1)<<endl;


    //preorder and inorder traversal
    // create tree
    int preorder[] = {2,8,10,6,4,12};
    int inorder[] = {10,8,6,2,4,12};
    int size = 6;
    int preorderindex = 0;
    int inorderstart = 0;
    int inorderend = size-1;
    map<int,int> valuetoindexmap;
    createmapping(inorder,size,valuetoindexmap);
    //preorder se root node mil jaygi sbse pehle
    Node* root = constructtreefrompreandinordertraversal(valuetoindexmap,preorder,inorder,preorderindex,inorderstart,inorderend,size);
    cout<<"Level order traversal : ";
    levelordertraversal(root);
    cout<<endl;
    return 0; 
}
// 5 10 15 -1 -1 20 -1 -1 25 30 -1 -1 35 -1 -1 