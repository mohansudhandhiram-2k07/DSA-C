#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

// --- CORE OPERATIONS ---

// 1. Create a new isolated node
struct tree* createNode(int value) {
    struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
    if (newNode == NULL) {
        printf("Heap exhaustion: malloc failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 2. Insert a node (Enforcing BST Rules)
struct tree* insert(struct tree* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Note: Duplicate values are ignored in a standard BST
    return root;
}

// 3. Search for a value (O(log N) speed)
struct tree* search(struct tree* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Helper for Deletion: Find the minimum value in a subtree
struct tree* findMin(struct tree* node) {
    struct tree* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// 4. Delete a node (The most complex operation)
struct tree* deleteNode(struct tree* root, int key) {
    if (root == NULL) return root;

    // Traverse to find the node
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found. 
        
        // Case 1 & 2: No child or 1 child
        if (root->left == NULL) {
            struct tree *temp = root->right;
            free(root); // Free the memory!
            return temp;
        } else if (root->right == NULL) {
            struct tree *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        struct tree* temp = findMin(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// --- METRICS & TRAVERSALS ---

// 5. Calculate Height of the tree
int getHeight(struct tree* root) {
    if (root == NULL) {
        return -1; // -1 for edges, 0 for nodes
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 6. Inorder Traversal (Left, Root, Right) - Prints BST in ascending order
void inorder(struct tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 7. Prevent Memory Leaks (Postorder deletion)
void freeTree(struct tree* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root); // Free children before parent
    }
}

// --- MAIN EXECUTION ---
int main() {
    struct tree *root = NULL;

    // Building the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal (Sorted Data): ");
    inorder(root);
    printf("\n");

    printf("Tree Height: %d\n", getHeight(root));

    // Searching
    int searchKey = 40;
    if (search(root, searchKey) != NULL) {
        printf("Found %d in the tree.\n", searchKey);
    } else {
        printf("%d not found.\n", searchKey);
    }

    // Deleting
    printf("Deleting node 50 (Root node with two children)...\n");
    root = deleteNode(root, 50);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    // Clean up memory before exit
    freeTree(root);
    printf("Tree memory freed. Exiting.\n");

    return 0;
}