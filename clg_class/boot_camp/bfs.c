#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_Q_SIZE 100 // Fixed size to avoid dynamic allocation overhead

// 1. Define the Tree Node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 2. Define the Circular Queue (Embedded Style - Fixed Array)
TreeNode* queue[MAX_Q_SIZE];
int front = 0;
int rear = 0;

bool is_empty() {
    return front == rear;
}

bool is_full() {
    return (rear + 1) % MAX_Q_SIZE == front;
}

void enqueue(TreeNode* node) {
    if (is_full()) {
        printf("Error: Queue Overflow. Increase MAX_Q_SIZE.\n");
        return;
    }
    queue[rear] = node;
    rear = (rear + 1) % MAX_Q_SIZE;
}

TreeNode* dequeue() {
    if (is_empty()) {
        return NULL;
    }
    TreeNode* node = queue[front];
    front = (front + 1) % MAX_Q_SIZE;
    return node;
}

// 3. The Breadth-First Traversal Logic
void bft(TreeNode* root) {
    if (root == NULL) return;

    // Start by pushing the root into the queue
    enqueue(root);

    // Loop until the queue is empty
    while (!is_empty()) {
        // Pop the front node
        TreeNode* current = dequeue();
        
        // Process the node (e.g., print it)
        printf("%d ", current->data);

        // Enqueue left child
        if (current->left != NULL) {
            enqueue(current->left);
        }
        // Enqueue right child
        if (current->right != NULL) {
            enqueue(current->right);
        }
    }
    printf("\n");
}

// Helper to create new tree nodes
TreeNode* create_node(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    /*
        Constructing the following binary tree:
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
    */
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    printf("Breadth-First Traversal: ");
    bft(root); // Expected Output: 1 2 3 4 5 6 7 

    // Note: In a real system, remember to write a function to free the tree memory.
    return 0;
}