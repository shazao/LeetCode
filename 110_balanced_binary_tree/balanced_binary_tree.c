/* Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1. */

// Star: 7.5.
// This method is better.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isBalancedHeight(struct TreeNode * tn, int * height) {
    if (tn == NULL)
        return true;
    
    int hl = 0;
    if (isBalancedHeight(tn->left, &hl) == false)
        return false;
        
    int hr = 0;
    if (isBalancedHeight(tn->right, &hr) == false)
        return false;
    
    *height = (hl>hr?hl:hr) + 1;
    
    if (abs(hl-hr) > 1)
        return false;
    
    return true;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    
    int height = 0;
    return isBalancedHeight(root, &height);
}


// Another method, runs faster.
//int depth(struct TreeNode * tn) {
//    if (tn == NULL)
//        return -1;
//    
//    int dl = depth(tn->left);
//    int dr = depth(tn->right);
//    int d = dl>dr ? dl : dr;
//    return ++d;
//}
//
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//    
//    //if (root->left==NULL && root->right==NULL)
//    //    return true;
//    //else if (!(root->left!=NULL && root->right!=NULL))
//    //    if (depth(root) > 1)
//    //        return false;
//    //    else 
//    //        return true;
//    //else 
//        return abs(depth(root->left) - depth(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
//}
