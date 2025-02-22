#include<iostream>
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

    if(data == -1) return NULL;

    Node* root = new Node(data);
    root->left = createtree();
    root->right = createtree();
    return root;
}
Node* solve(Node* root,int& k, int node,int& ans){
    if(!root) return 0;// agr root null hai to return 0 krdo
    if(root->data == node) return root; // agr root ka data node ke brabar hai to root return krdo
    if(ans != -1) return root; // agr ans -1 hai to root ko return krdo

    auto l = solve(root->left,k,node,ans); // left side check kr lo
    auto r = solve(root->right,k,node,ans);// right side check kr lo

    //node yaah hogi
    if(!l && !r) return 0; // left or right null nahi hai to return 0 krdo
    k--; // k ko kam krte jao 
    if(k == 0) ans = root->data; // agr k==0 hai to ans mein root ke data ko store krlo

    if(l && !r) return l;// agr left null nhi or right null hai to l return krdo
    if(!l && r) return r;// agr left null hai or right null nhi hai to r ko return krdo
    else return root; // root ko return krdo
}
int kthancestor(Node* root,int& k,int& node){
    int ans = -1;
    solve(root,k,node,ans);
    return ans;
}
int main(){
    Node* root = createtree();
    int k = 2;
    int node = 4;
    int ans = kthancestor(root,k,node);
    cout<<"Kth Ancestor of node is : "<<ans<<endl;
    return 0;
}
//1 2 4 -1 -1 5 -1 -1 3 -1 -1