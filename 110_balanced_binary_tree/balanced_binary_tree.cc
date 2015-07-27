/* Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1. */

// Star: 7.5.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode * tn) {
        if (tn == NULL)
            return -1;
        
        int left_depth = depth(tn->left);
        int right_depth = depth(tn->right);
        int depth = left_depth>right_depth ? left_depth : right_depth;
        return ++depth;
        
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
            
        if (root->left==NULL && root->right==NULL)
            return true;
        else if (!(root->left!=NULL && root->right!=NULL))
            if (depth(root) > 1)      // Note 0: Condition 0.
                return false;
            else 
                return true;
        else   // Note 1: Conditino 1 and 2(Condition is for recursion).
            return std::abs(depth(root->left) - depth(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
