#include <iostream>
#include <queue>

class Node {
public:
	int data;
	Node *left;
	Node *right;

	// Constructor
	Node(int d) : data(d), left(nullptr), right(nullptr) {}

	// Copy Constructor for deep copy
	Node(const Node& other) {
        // TODO
        this->data = other.data;   
        this->left = copy(this->left, other.left);
        this->right = copy(this->right, other.right);
	}

    Node* copy(Node* subRoot, Node* other) {
        if(other == nullptr) return nullptr;
        subRoot = new Node(other->data);
        subRoot->left = copy(subRoot->left, other->left);
        subRoot->right = copy(subRoot->right, other->right);
        return subRoot;
    }

	// Destructor
	~Node() {
		delete left;
		delete right;
	}
};

class BinaryTree {
public:
	Node *root;

	// Constructor
	BinaryTree() : root(nullptr) {}

	// Copy Constructor for deep copy
	BinaryTree(const BinaryTree& other) {
        // TODO
        root = root->copy(root, other.root);
	}

	// Destructor
	~BinaryTree() {
		delete root;
	}

	// Insert a new node with level order traversal
	void insert(int data) {
        // TODO
        Node* temp = root;
        Node* node = new Node(data);

        if(temp == nullptr) {
            root = node;
            return; 
        }

        std::queue<Node*> q;
        q.push(temp);

        while(q.size() > 0) {
            Node* cur = q.front();
            // std::cout<<"cur: "<<cur->data<<std::endl;
            // std::cout<<"node: "<<node->data<<std::endl;
            if(cur == nullptr)  std::cout<<"Error";
            if(cur->left == nullptr) {
                cur->left = node;
                
                break;
            } else if(cur->right == nullptr) {
                cur->right = node;
                break;
            }
            q.push(cur->left);
            q.push(cur->right);
            q.pop();
        }
	}
    bool first;
	void printInPreOrder() {
        // TODO
        first = true;
        if(root == nullptr) {
            return;
        }
        printSub(root);
        std::cout<<std::endl;
	}

    void printSub(Node* subRoot) {
        if(subRoot == nullptr) {
            return;
        }
        if(!first) {
            std::cout<<",";
        }
        first = false;
        std::cout<<subRoot->data;

        printSub(subRoot->left);
        printSub(subRoot->right);
    }

	void reverse() {
        if(root == nullptr) {
            return;
        }
        root = inverseSub(root);
	}


    Node* inverseSub(Node* subRoot) {
        if(subRoot == nullptr) {
            return nullptr;
        }
        // std::cout<<"node: "<<subRoot->data<<std::endl;
        Node* temp = subRoot->right;
        subRoot->right = subRoot->left;
        subRoot->left = temp;

        subRoot->right = inverseSub(subRoot->right);
        subRoot->left =  inverseSub(subRoot->left);
        
        return subRoot;
    }
};

int main(void) {
	BinaryTree bt;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int data;
		std::cin >> data;
		bt.insert(data);
	}
    bt.printInPreOrder();
	bt.reverse();
 	bt.printInPreOrder();

	BinaryTree bt2 = bt;
	bt2.printInPreOrder();
}