#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertintobst(Node*& root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
        root->right = insertintobst(root->right, data);
    else
        root->left = insertintobst(root->left, data);
    return root;
}

void createbst(Node*& root) {
    cout << "Enter Data: ";
    int data;
    cin >> data;
    while (data != -1) {
        root = insertintobst(root, data);
        cin >> data;
    }
}

void levelordertraversal(Node*& root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (!front) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        } else {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}

Node* lowestcommonancestor(Node* root, Node* p, Node* q) {
    if (root == NULL)
        return NULL;

    if (p->data < root->data && q->data < root->data)
        return lowestcommonancestor(root->left, p, q);

    if (p->data > root->data && q->data > root->data)
        return lowestcommonancestor(root->right, p, q);

    return root;
}

Node* findNode(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return findNode(root->left, data);

    return findNode(root->right, data);
}

int main() {
    Node* root = NULL;
    createbst(root);
    levelordertraversal(root);

    int pData, qData;
    cout << "Enter value for p: ";
    cin >> pData;
    cout << "Enter value for q: ";
    cin >> qData;

    Node* p = findNode(root, pData);
    Node* q = findNode(root, qData);

    Node* lca = lowestcommonancestor(root, p, q);
    if (lca != NULL)
        cout << "Lowest Common Ancestor of " << pData << " and " << qData << " is: " << lca->data << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}