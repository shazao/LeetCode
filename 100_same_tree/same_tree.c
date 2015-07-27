/* Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. */

// Star: 6.5.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    if (p==NULL && q==NULL)
        return true;
        
    if (p!=NULL && q!=NULL)
        if (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        else
            return false;
    else
        return false;

}
        
