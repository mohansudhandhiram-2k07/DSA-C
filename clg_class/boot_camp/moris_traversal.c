#include <stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void morrisInOrder(struct Node* root) {
    struct Node* current = root;
    struct Node* pre; // This will be our "anchor" for the rope

    while (current != NULL) {
        
        // CASE 1: No left child (No cave to the left)
        if (current->left == NULL) {
            printf("%d ", current->data); // Print node
            current = current->right;     // Move right
        } 
        
        // CASE 2: Has a left child
        else {
            // Step A: Find the In-order Predecessor
            pre = current->left; 
            // Go right as far as possible, BUT stop if we hit a tied rope (pre->right == current)
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }

            // Step B: The rope is NOT tied (pre->right is NULL)
            if (pre->right == NULL) {
                pre->right = current;     // Tie the rope! (Create the thread)
                current = current->left;  // Move down the left side
            } 
            
            // Step C: The rope IS tied (pre->right points back to current)
            else {
                pre->right = NULL;        // Untie the rope! (Restore the tree)
                printf("%d ", current->data); // We finished the left side, print current
                current = current->right; // Move right
            }
        }
    }
}