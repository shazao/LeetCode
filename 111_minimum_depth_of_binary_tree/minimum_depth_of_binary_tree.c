/* Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. */

// Star: 7.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Solution 0: Not so efficient.
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    
    int mdl = minDepth(root->left);
    int mdr = minDepth(root->right);
    
    if (mdl!=0 && mdr!=0)
        return (mdl<mdr ? mdl : mdr) + 1;
    else if (mdl==0 && mdr==0)
        return 1;
    else 
        return (mdl>mdr ? mdl : mdr) + 1;
}

// Solution 1.
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    
    int mdl = minDepth(root->left);
    int mdr = minDepth(root->right);
    
    if (mdl == 0)
      return mdr + 1;
    if (mdr == 0)
      return mdl +1;

    return (mdl<mdr ? mdl : mdr) + 1;
}
