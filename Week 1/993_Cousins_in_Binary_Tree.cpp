/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

 

Note:

    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.

*/

// Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* xParent = NULL;
    TreeNode* yParent = NULL;
    int xDepth = 0;
    int yDepth = 0;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        findDepthandParent(root,x,y,0,NULL);
        return xDepth==yDepth && xParent!=yParent;
    }
    void findDepthandParent(TreeNode* root,int x,int y,int depth,TreeNode* parent) {
        if(root == NULL)
            return;
        if(root->val == x) {
            xDepth = depth;
            xParent = parent;
        }
        else if(root->val == y) {
            yDepth = depth;
            yParent = parent;
        }
        else {
            findDepthandParent(root->left,x,y,depth+1,root);
            findDepthandParent(root->right,x,y,depth+1,root);
        }
    }
};
