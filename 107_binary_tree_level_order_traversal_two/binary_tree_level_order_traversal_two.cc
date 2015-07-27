/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
] */

// Star: 7.3.

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        std::vector<std::vector<int> > rtn;
        if (root == NULL)
            return rtn;
            
        std::stack<TreeNode*> stk;
        stk.push(NULL);     // Note 1: Push "NULL" at the bottom to ensure "push_back" the root->val.
        stk.push(root);
        stk.push(NULL);
        
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while (q.empty() == false) {
            TreeNode * tn = q.front();
            q.pop();
            
            if (tn->right) {
                q.push(tn->right);
                stk.push(tn->right);
            }
            if (tn->left) {
                q.push(tn->left);
                stk.push(tn->left);
            }
            
            if (q.front() == NULL)
                if (q.size() == 1)
                    break;
                else {
                    q.push(NULL);
                    stk.push(NULL);
                    q.pop();
                }
        }
        
        std::vector<int> lv;
        stk.pop();      // Note 0: Pop "NULL".
        while (stk.empty() == false) {
            TreeNode * tn = stk.top();
            
            if (tn != NULL) {
                lv.push_back(tn->val);
                stk.pop();
            } else {
                stk.pop();
                rtn.push_back(lv);
                lv.clear();
            }
        }
        
        return rtn;
    }
};
