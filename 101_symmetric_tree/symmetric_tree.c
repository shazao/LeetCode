/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Star: 7.

bool isMirrorTree(struct TreeNode * p, struct TreeNode * q) {
    if (p==NULL && q==NULL)
        return true;
        
    if (p!=NULL && q!=NULL)
        if (p->val==q->val && isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left))
            return true;
        else
            return false;
    else
        return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    
    if (isMirrorTree(root->left, root->right))
        return true;
        
    return false;
}
