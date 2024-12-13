#include<iostream>
using namespace std;
// #define TEST
struct TreeNode{
    int value,height;
    TreeNode *lchild,*rchild;
    TreeNode(int v):value(v),height(1),lchild(NULL),rchild(NULL){}
};

int getHeight(TreeNode* root){
	// TODO
    if(root == nullptr) return 0;
    return root->height;
}

int getbalanceFactor(TreeNode* root){
    // TODO
    if(root == NULL)    return 0;
    if(root->lchild == NULL && root->rchild)    return -(root->rchild->height);
    if(root->rchild == NULL && root->lchild)    return root->lchild->height;
    if(root->lchild == NULL && root->rchild == NULL)    return 0;
    int diff = root->lchild->height - root->rchild->height;
    return diff;
}

void updateHeight(TreeNode* root){
    // TODO
    root->height++;
}
/*
void L(TreeNode* &root){
	// TODO
    // left rotation

    TreeNode* new_left = root;
    root = root->rchild;
    root->rchild = new_left;
    root->height++;
    root->lchild->height--;
#ifdef TEST
    cout<<"L succeefully "<<endl;
#endif
}

void R(TreeNode* &root){
	// TODO
    // right rotation
    TreeNode* new_right = root;
    root = root->lchild;
    root->rchild = new_right;
    root->height++;
    root->rchild->height--;
#ifdef TEST
    cout<<"R succeefully "<<endl;
#endif
}*/
void L(TreeNode* &root){
    if (root == nullptr || root->rchild == nullptr)
        return; 

    TreeNode* new_left = root;
    root = root->rchild;
    new_left->rchild = root->lchild;
    root->lchild = new_left;

    new_left->height = max(getHeight(new_left->lchild), getHeight(new_left->rchild)) + 1;
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;

#ifdef TEST
    cout << "L successfully " << endl;
#endif
}

void R(TreeNode* &root){
    if (root == nullptr || root->lchild == nullptr)
        return; 

    TreeNode* new_right = root;
    root = root->lchild;
    new_right->lchild = root->rchild;
    root->rchild = new_right;

    new_right->height = max(getHeight(new_right->lchild), getHeight(new_right->rchild)) + 1;
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;


#ifdef TEST
    cout << "R successfully " << endl;
#endif
}


void insert(TreeNode* &root,int v){
    if(root == NULL){
        root = new TreeNode(v);
        return;
    }

    if(v < root->value){
        insert(root->lchild, v);
    } else {
        insert(root->rchild, v);
    }
    updateHeight(root);

    int balance = getbalanceFactor(root);

#ifdef TEST
    cout<<"node: "<<root->value<<endl;
    cout<<"balance: "<<balance<<endl;
#endif

    if(balance > 1) {
        if(getbalanceFactor(root->lchild) >= 0) {
#ifdef TEST
    cout<<"LL"<<root->value<<endl;
#endif
            R(root);
        }   else {
#ifdef TEST
    cout<<"LR"<<root->value<<endl;
#endif
            L(root->lchild);
            R(root);
        }
    }else if(balance < -1) {

        if(getbalanceFactor(root->rchild) <= 0) {
#ifdef TEST
    cout<<"RR"<<root->value<<endl;
#endif
            L(root);
        }   else {
#ifdef TEST
    cout<<"RL"<<root->value<<endl;
#endif
            R(root->rchild);
            L(root);
        }
    }
}


int main(){
    int n,tmp;
    TreeNode* root = NULL;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&tmp);
        insert(root,tmp);
#ifdef TEST
    cout<<"insert: "<<tmp<<endl;
#endif
    }
    printf("%d\n",root->value);
    return 0;
}