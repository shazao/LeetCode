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

// Star: 7.5.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
            
        std::queue<TreeNode*> ql;
        std::queue<TreeNode*> qr;
        ql.push(root->left);    // Don't check whether root->left is NULL or not.
        qr.push(root->right);
        
        while (ql.empty()==false && qr.empty()==false) {
            TreeNode * nl = ql.front();
            ql.pop();
            TreeNode * nr = qr.front();
            qr.pop();
            
            if (nl!=NULL && nr!=NULL)
                if (nl->val == nr->val) {
                    ql.push(nl->left);      // Don't check whether left child pointer is NULL or not.
                    ql.push(nl->right);
                    
                    qr.push(nr->right);
                    qr.push(nr->left);
                } else
                    return false;
            else if (!(nl==NULL && nr==NULL))
                return false;
                
        }
        
        if (ql.empty()==true && qr.empty()==true)
            return true;
        else
            return false;
            
    }
};
