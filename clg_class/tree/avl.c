#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 1. Node Structure (Using int8_t for embedded memory efficiency)
struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int8_t height; 
};

// 2. Inline Utility Functions
static inline int8_t max(int8_t a, int8_t b) {
    return (a > b) ? a : b;
}

static inline int8_t getHeight(struct AVLNode *n) {
    if (n == NULL) return 0;
    return n->height;
}

static inline int8_t getBalance(struct AVLNode *n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// 3. Node Creation
struct AVLNode* createNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New nodes are added at the leaf level
    return node;
}

// 4. Right Rotation (Fixes Left-Left heavy)
struct AVLNode* rightRotate(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights (Child first, then Parent)
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// 5. Left Rotation (Fixes Right-Right heavy)
struct AVLNode* leftRotate(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// 6. AVL Insertion Logic
struct AVLNode* insertNode(struct AVLNode* node, int data) {
    // Standard BST Insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else // Equal keys not allowed
        return node;

    // Update height of current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor
    int8_t balance = getBalance(node);

    // Rebalance if needed (The 4 Cases)
    
    // Left-Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right-Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left-Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// 7. Pre-Order Traversal (Root, Left, Right)
void preOrder(struct AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 8. Main Execution
int main() {
    struct AVLNode *root = NULL;

    /* Constructing tree given in the classic exam sequence
       Inserting: 10, 20, 30, 40, 50, 25 
       This specifically forces multiple types of rotations */

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30); // Triggers RR -> Left Rotation. Root becomes 20.
    root = insertNode(root, 40);
    root = insertNode(root, 50); // Triggers RR -> Left Rotation.
    root = insertNode(root, 25); // Triggers RL -> Right-Left Rotation.

    /* The constructed AVL Tree should look like this:
            30
           /  \
         20    40
        /  \     \
       10  25    50
    */

    printf("Pre-order traversal of the constructed AVL tree is: \n");
    preOrder(root);
    printf("\n");

    return 0;
}