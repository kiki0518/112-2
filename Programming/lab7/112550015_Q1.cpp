#include<iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *lchild, *rchild;
    TreeNode(int v): value(v), lchild(NULL), rchild(NULL) {}
};

TreeNode* insert(TreeNode* node, int value) {
    //TO-DO
    if(node == NULL) {
        // the first one
        TreeNode* new_node = new TreeNode(value);
        return new_node;
    }

    if(value > node->value) {
        node->rchild = insert(node->rchild, value);
    } else {
        node->lchild = insert(node->lchild, value);
    }

    return node;
}

void inOrder(TreeNode* node) {
    //TO-DO
    if(node == NULL)    return;
    inOrder(node->lchild);
    cout << " "<<node->value;
    inOrder(node->rchild);
}

void preOrder(TreeNode* node) {
    //TO-DO
    if(node == NULL)    return;
    cout << " "<<node->value;
    preOrder(node->lchild);
    preOrder(node->rchild);
}

void postOrder(TreeNode* node) {
    //TO-DO
    if(node == NULL)    return;
    postOrder(node->lchild);
    postOrder(node->rchild);
    cout << " "<<node->value;
    
}

int main(){
    int n;
    cin >> n;
    TreeNode* bst = NULL;
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        bst = insert(bst, value);
    }

    /*
    input
    9
    50 35 20 5 25 45 75 55 65
    */



    /*
    output
    InOrder traversal: 5 20 25 35 45 50 55 65 75
    PreOrder traversal: 50 35 20 5 25 45 75 55 65
    PostOrder traversal: 5 25 20 45 35 65 55 75 50
    */

    //TO-DO
    cout<<"InOrder traversal:";
    inOrder(bst);
    cout<<endl;

    cout<<"PreOrder traversal:";
    preOrder(bst);
    cout<<endl;

    cout<<"PostOrder traversal:";
    postOrder(bst);
    cout<<endl;

    return 0;
}