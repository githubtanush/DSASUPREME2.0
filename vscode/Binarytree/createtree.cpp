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
Node* createtree(){
    int data;
    cin>>data;
    
    if(data == -1) return NULL;

    Node* root = new Node(data);
    cout<<"Enter the left of the "<<root->data<<" node : ";
    root->left = createtree();
    cout<<"Enter the right of the "<<root->data<<" node : ";
    root->right = createtree();

    return root;
}
void preorder(Node*& root){
    if(!root) return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node*& root){
    if(!root) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node*& root){
    if(!root) return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelordertraversal(Node*& root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(!front){
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
int height(Node*& root){
    if(root == NULL) return 0;

    return max(height(root->left),height(root->right))+1;
}
int diameter(Node*& root){
    if(root == NULL) return 0;

    return max(diameter(root->left),max(diameter(root->right),height(root->left) + height(root->right)));
}
bool isbalanced(Node*& root){
    if(root == NULL) return true;

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(diff && isbalanced(root->left) && isbalanced(root->right)) return true;
    else return false;
}
bool pathsum(Node*& root,int sum , int& targetsum){
    if(root == NULL) return false;

    sum += root->data;
    if(!root->left && !root->right){
        if(sum == targetsum) return true;
        else return false;
    }
    
    bool leftans = pathsum(root->left,sum,targetsum);
    bool rightans = pathsum(root->right,sum,targetsum);

    return leftans || rightans;
}
void pathssum(Node*& root,vector<vector<int> >& ans,vector<int>& temp,int targetsum,int sum){
    if(!root) return ;

    sum+= root->data;
    temp.push_back(root->data);
    if(!root->left && !root->right){
        if(sum == targetsum) ans.push_back(temp);
        else return ;
    }

    pathssum(root->left,ans,temp,targetsum,sum);
    pathssum(root->right,ans,temp,targetsum,sum);
}
Node* lca(Node*& root,int p,int q){
    if(!root) return NULL;
    if(root->data == p || root->data == q) return root;

    auto l = lca(root->left,p,q);
    auto r = lca(root->right,p,q);

    if(!l && !r) return NULL;
    else if(l && !r) return l;
    else if(!l && r) return r;
    else return root;
    
}
Node* kthancestor(Node*& root,int& k,int node,int ans){
    if(!root) return NULL;
    if(root->data == node || ans != -1) return root;

    auto l = kthancestor(root->left,k,node,ans);
    auto r = kthancestor(root->right,k,node,ans);

    if(!l && !r) return NULL;
    k--;
    if(k == 0) ans = root->data;

    if(!l && r) return r;
    if(l && !r) return l;
    else return root;
}
void createmapping(map<int,int>& valuetoindexmap,int size,int inorder[]){
    for(int i = 0; i < size;i++) 
        valuetoindexmap[inorder[i]] = i;
}
void createemapping(map<int,int>& valuetoindexxmap,int size,int inordered[]){
    for(int i = 0; i < size;i++)
        valuetoindexxmap[inordered[i]] = i;
}
Node* preorderandinordertraversal(map<int,int>& valuetoindexmap,int preorder[],int inorder[],int& preindex,int inorderstart,int inorderend,int size){
    if(preindex >= size || inorderstart > inorderend) return NULL;

    int element = preorder[preindex];
    preindex++;
    Node* root = new Node(element);

    int position = valuetoindexmap[element];

    root->left = preorderandinordertraversal(valuetoindexmap,preorder,inorder,preindex,inorderstart,position-1,size);
    root->right = preorderandinordertraversal(valuetoindexmap,preorder,inorder,preindex,position+1,inorderend,size);
    
    return root;
}
Node* postorderandinordertraversal(map<int,int>& valuetoindexmap,int postorder[],int inordered[],int& postindex,int inorderstart,int inorderend,int size){
    if(postindex < 0 || inorderstart > inorderend) return NULL;

    int element = postorder[postindex];
    postindex--;
    Node* root = new Node(element);

    int position = valuetoindexmap[element];

    root->right = postorderandinordertraversal(valuetoindexmap,postorder,inordered,postindex,position+1,inorderend,size);
    root->left = postorderandinordertraversal(valuetoindexmap,postorder,inordered,postindex,inorderstart,position-1,size);
    
    return root;
}
void printleftview(Node*& root,int level,vector<int>& leftview){
    if(!root) return ;

    if(level == leftview.size()) leftview.push_back(root->data);

    printleftview(root->left,level+1,leftview);
    printleftview(root->right,level+1,leftview);

}
void printrightview(Node*& root,int level,vector<int>& rightview){
    if(!root) return ;

    if(level == rightview.size()) rightview.push_back(root->data);

    printrightview(root->right,level+1,rightview);
    printrightview(root->left,level+1,rightview);
}
void printtopview(Node*& root){
    map<int,int> hdtonodemap;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* front = temp.first;
        int hd = temp.second;

        if(hdtonodemap.find(hd) == hdtonodemap.end())
            hdtonodemap[hd] = front->data;

        if(front->left) q.push(make_pair(front->left,hd-1));
        if(front->right) q.push(make_pair(front->right,hd+1));
    }
    cout<<"Printing top view : ";
    for(auto i : hdtonodemap)
        cout<<i.second<<" ";
}
void printbottomview(Node*& root){
    map<int,int> hdtonodemap;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* front = temp.first;
        int hd = temp.second;

        hdtonodemap[hd] = front->data;

        if(front->left) q.push(make_pair(front->left,hd-1));
        if(front->right) q.push(make_pair(front->right,hd+1));
    }
    cout<<"Printing bottom view : ";
    for(auto i : hdtonodemap)
        cout<<i.second<<" ";
}
void leftview(Node*& root){
    if(!root) return ;
    if(!root->left && !root->right) return ;

    cout<<root->data<<" ";
    if(root->left) leftview(root->left);
    else leftview(root->right);
}
void printleaf(Node*& root){
    if(!root) return ;

    if(!root->left && !root->right) cout<<root->data<<" "; 
    printleaf(root->left);
    printleaf(root->right);
}
void rightview(Node*& root){
    if(!root) return ;

    if(!root->left && !root->right) return ;

    if(root->right) rightview(root->right);
    else rightview(root->left);
    cout<<root->data<<" ";
}
void printboundarytraversal(Node*& root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    leftview(root->left);
    printleaf(root->left);
    printleaf(root->right);
    rightview(root->right);
}
int main(){
    cout<<"Enter the root node : ";
    Node* root = createtree();

    cout<<endl<<"Preorder Traversal : ";
    preorder(root);

    cout<<endl<<"Inorder Traversal : ";
    inorder(root);

    cout<<endl<<"Postorder Traversal : ";
    postorder(root);

    cout<<endl<<"Level Order Traversal : "<<endl;
    levelordertraversal(root);

    cout<<"Height of the Tree is : "<<height(root)<<endl;
    cout<<"Diameter of the Tree is : "<<diameter(root)<<endl;

    // int p;
    // cin>>p;
    // int q;
    // cin>>q;
    // Node* ans = lca(root,p,q);
    // cout<<"Lowest common ancestor of p and q node is : "<<ans->data<<endl;

    // int targetsum;
    // cout<<"Enter the target sum :";
    // cin>>targetsum;
    // // if(pathsum(root,0,targetsum)) cout<<"Target exists"<<endl;
    // // else cout<<"Target does not exist"<<endl;

    // vector<vector<int> >ans;
    // vector<int> temp;
    // pathssum(root,ans,temp,targetsum,0);
    // for(auto i : ans) 
    //     for(auto j : i) cout<<j<<" ";

    // int preorder[] = {2,8,10,6,4,12};
    // int inorder[] = {10,8,6,2,4,12};
    // int postorder[] = {8,6,14,4,10,2};
    // int inordered[] = {8,14,6,2,10,4};
    // int preindex = 0;
    // int size = 6;
    // int postindex = size - 1;
    // int inorderstart = 0;
    // int inorderend = size - 1;
    // map<int,int> valuetoindexmap;
    // createmapping(valuetoindexmap,size,inorder);
    // map<int,int> valuetoindexxmap;
    // createemapping(valuetoindexxmap,size,inordered);
    // Node* roots = postorderandinordertraversal(valuetoindexxmap,postorder,inordered,postindex,inorderstart,inorderend,size); 
    // levelordertraversal(roots);
    // cout<<endl;

    // Node* roote = preorderandinordertraversal(valuetoindexmap,preorder,inorder,preindex,inorderstart,inorderend,size); 
    // levelordertraversal(roote);

    vector<int> leftview;
    printleftview(root,0,leftview);
    for(auto i : leftview) cout<<i<<" ";

    cout<<endl;
    vector<int> rightview;
    printrightview(root,0,rightview);
    for(auto i : rightview) cout<<i<<" ";

    cout<<endl;
    printtopview(root);
    cout<<endl;
    printbottomview(root);

    cout<<endl<<"Boundary Traversal : ";
    printboundarytraversal(root);
    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1  111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1  -1