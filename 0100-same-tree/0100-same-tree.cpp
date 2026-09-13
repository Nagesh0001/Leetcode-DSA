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
//  //.Brute Force Approach. T.C :- 
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& v) {
//         // Store NULL also to preserve tree structure
//         if(root == NULL) {
//             v.push_back(-1);
//             return;
//         }
//         inorder(root->left, v);   // Left subtree
//         v.push_back(root->val);    // Root
//         inorder(root->right, v);  // Right subtree
//     }
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         vector<int> v1, v2;
//         inorder(p, v1);
//         inorder(q, v2);
//         // Compare both traversals
//         return v1 == v2;
//     }
// };


//.Optimise Approach. T.C :- O(N). S.C :- O(n). S.C :- O(h)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) // Both nodes are NULL → same
            return true;
        if(p == NULL || q == NULL) // One node is NULL → different
            return false;
        if(p->val != q->val)  // Values are different → different
            return false;
        return isSameTree(p->left, q->left) && // Check both left and right 
               isSameTree(p->right, q->right);
    }
};