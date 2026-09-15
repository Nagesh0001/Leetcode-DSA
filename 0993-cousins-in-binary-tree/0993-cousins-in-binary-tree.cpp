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
 //.Brute Force Approach. T.C :- O(N)  S.C :- O(H)
class Solution {
public:
    void findNode(TreeNode* root, int target, int depth,
                  TreeNode* parent, int& targetDepth,
                  TreeNode*& targetParent) {
        if (root == NULL)
            return;
        if (root->val == target) {
            targetDepth = depth;
            targetParent = parent;
            return;
        }
        findNode(root->left, target, depth + 1, root,
                 targetDepth, targetParent);
        findNode(root->right, target, depth + 1, root,
                 targetDepth, targetParent);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = -1;
        int depthY = -1;
        TreeNode* parentX = NULL;
        TreeNode* parentY = NULL;
        findNode(root, x, 0, NULL, depthX, parentX);
        findNode(root, y, 0, NULL, depthY, parentY);
        return depthX == depthY && parentX != parentY;
    }
};


// //.Optimized / Iterative Approach.  T.C :- O(N). S.C :- O(N)
// class Solution {
// public:
//     bool isCousins(TreeNode* root, int x, int y) {
//         if (root == NULL)
//             return false;
//         queue<pair<TreeNode*, TreeNode*>> q;
//         q.push({root, NULL});
//         while (!q.empty()) {
//             int n = q.size();
//             bool foundX = false;
//             bool foundY = false;
//             TreeNode* parentX = NULL;
//             TreeNode* parentY = NULL;
//             for (int i = 0; i < n; i++) {
//                 TreeNode* node = q.front().first;
//                 TreeNode* parent = q.front().second;
//                 q.pop();
//                 if (node->val == x) {
//                     foundX = true;
//                     parentX = parent;
//                 }
//                 if (node->val == y) {
//                     foundY = true;
//                     parentY = parent;
//                 }
//                 if (node->left != NULL) {
//                     q.push({node->left, node});
//                 }
//                 if (node->right != NULL) {
//                     q.push({node->right, node});
//                 }
//             }
//             if (foundX && foundY) {
//                 return parentX != parentY;
//             }
//             if (foundX || foundY) {
//                 return false;
//             }
//         }
//         return false;
//     }
// };