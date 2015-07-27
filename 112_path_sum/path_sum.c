/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22. */

// Star: 7.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL)
        return false;
    
    if (root->left==NULL && root->right==NULL)
        if (sum == root->val)
            return true;
    
    sum -= root->val;
    
    if (root->left)
        if (hasPathSum(root->left, sum) == true)
            return true;
    if (root->right)
        if (hasPathSum(root->right, sum) == true)
            return true;
            
    return false;
}
