#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    struct TreeNode* left_signal = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right_signal = lowestCommonAncestor(root->right, p, q);
    
    
    if (left_signal != NULL && right_signal != NULL) {
        return root;
    }
    return (left_signal != NULL) ? left_signal : right_signal;
}   