
#include "AVL.h"
#include <iostream>
#include <fstream>

#define MAX_LIMIT 1000

using namespace std;

AVL::AVL() {
    root = nullptr;
    totalNodes = 0;
}

AVL::AVL(const AVL& orig) {
}

AVL::~AVL() {
}

int AVL::max(int a, int b) {
    return (a > b) ? a : b;
}

Node* AVL::rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation 
    x->right = y;
    y->left = T2;

    // Update heights 
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root 
    return x;
}

Node* AVL::leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation 
    y->left = x;
    x->right = T2;

    //  Update heights 
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root 
    return y;
}

int AVL::getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

int AVL::getHeight(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

Node* AVL::newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // new node is initially added at leaf 
    totalNodes++;
    return (node);
}

bool AVL::elementExists(int key) {
    return ( find(root, key) == nullptr ? false : true);
}

Node* AVL::find(Node* node, int key) {
    if (node == nullptr)
        return nullptr;
    else if (node->key = key)
        return root;
    else if (node->key < key)
        return find(node->right, key);
    else if (node->key > key)
        return find(node->left, key);
}

Node* AVL::insert(Node* node, int key) {

    /* 1.  Perform the normal BST insertion */

    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST 
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(getHeight(node->left),
            getHeight(node->right));

    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then 
    // there are 4 cases 

    // Left Left Case 
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case 
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case 
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case 
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void AVL::inOrder(Node *node, fstream& outfile) {
    if (node != nullptr) {
        inOrder(node->left, outfile);
        std::cout << node->key << " ";
        outfile << node->key << " ";
        inOrder(node->right, outfile);
    }
}

void AVL::preOrder(Node *node, fstream& outfile) {
    if (node != nullptr) {
        std::cout << node->key << " ";
        outfile << node->key << " ";
        preOrder(node->left, outfile);
        preOrder(node->right, outfile);
    }
}

void AVL::postOrder(Node *node, fstream& outfile) {
    if (node != nullptr) {

        postOrder(node->left, outfile);
        postOrder(node->right, outfile);
        std::cout << node->key << " ";
        outfile << node->key << " ";
    }
}

void AVL::insert(int key) {

    if (MAX_LIMIT == totalNodes) {
        cout << " The total node number of the AVL will not exceed 1000." << endl;

    } else {
        root = insert(root, key);
    }
}

void AVL::inorderTraversal(fstream& outfile) {
    if (root == nullptr) {
        std::cout << "There is no tree.";
        outfile << "There is no tree.";
    } else {
        inOrder(root, outfile);
        std::cout << endl;
        outfile << endl;
    }

}

void AVL::preorderTraversal(fstream& outfile) {
    if (root == nullptr) {
        std::cout << "There is no tree.";

        outfile << "There is no tree.";
    } else {
        preOrder(root, outfile);
        std::cout << endl;
        outfile << "\n";
    }
}

void AVL::postorderTraversal(fstream& outfile) {
    if (root == nullptr) {
        std::cout << "There is no tree.";
        outfile << "There is no tree.";
    } else {
        postOrder(root, outfile);
        std::cout << endl;
        outfile << "\n";
    }
}

/* Function to line by line print level order traversal a tree*/
void AVL::printGivenLevel(int level, fstream& outfile) {

    int h = getHeight(root);
    if (h < level) {
        cout << "empty" << endl;
        outfile << "empty" << endl;
        return;
    }
    int i;
    for (i = 1; i <= h; i++) {
        if (i == level) {
            printGivenLevel(root, i, outfile);
            cout << endl;
        }
    }
    outfile << "\n";
}

/* Print nodes at a given level */
void AVL::printGivenLevel(Node* node, int level, fstream& outfile) {
    if (node == NULL)
        return;
    if (level == 1) {
        cout << node->key << " ";
        outfile << node->key << " ";
    } else if (level > 1) {
        printGivenLevel(node->left, level - 1, outfile);
        printGivenLevel(node->right, level - 1, outfile);
    }
} 