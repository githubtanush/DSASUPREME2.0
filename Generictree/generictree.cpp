#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        int children_count;
        Node** children;

    Node(int data){
        this->data = data;
        this->children_count = 0;
        this->children = 0;
    }
};
Node* takeinput(){
    int data,count;
    cout<<"Enter root data : ";
    cin>>data;
    cout<<"Enter children count for "<<data<<" node : ";
    cin>>count;
    Node* root = new Node(data);
    root->children_count = count;
    root->children = new Node*[count]; // array to stores links to children
    for(int i = 0; i < count;i++){
        root->children[i] = takeinput();
    }
    return root;
}
void levelorderprint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(0);//it is also treated like a pointer which is NULL pointer

    while(!q.empty()){
        auto front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
            else{
                cout<<front->data<<" ";
                for(int i = 0; i < front->children_count;i++)
                    if(front->children[i]) q.push(front->children[i]);
            }
        }
    }
int main(){
    Node* root = takeinput();
    levelorderprint(root);
    return 0;
}
// 1 5 2 2 10 0 3 0 4 2 89 0 90 0 3 0 4 0 5 0