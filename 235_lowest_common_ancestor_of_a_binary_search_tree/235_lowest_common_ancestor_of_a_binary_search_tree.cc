/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w 

as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 

since a node can be a descendant of itself according to the LCA definition.
*/

// Star: 7.
// Info.: One-time pass(Re-order the conditions to get more concise).

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rv = root->val;
        int pv = p->val;
        int qv = q->val;
        
        TreeNode * ancestor = root;
        
        if (rv==pv || rv==qv)
            return root;
        
        if ((rv>pv && rv<qv) || (rv<pv && rv>qv))
            return root;
        else if (rv > pv)
            ancestor = lowestCommonAncestor(root->left, p, q);
        else
            ancestor = lowestCommonAncestor(root->right, p, q);
            
        return ancestor;
    }
};

// Iterative solution.
/*
class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};
*/
