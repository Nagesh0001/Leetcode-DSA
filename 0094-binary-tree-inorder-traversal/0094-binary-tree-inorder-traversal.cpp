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
//.Brute Force Approach.  T.C :- O(N). S.C :- O(H)
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL)  // If node is NULL, stop
            return;
        inorder(root->left, ans);    // 1. Visit Left subtree
        ans.push_back(root->val);   // 2. Visit Root 
        inorder(root->right, ans);  // 3. Visit Right subtree
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};


// //.Optimise Approach. T.C :- T.C :- O(N). S.C :- O(H)
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         stack<TreeNode*> st;
//         TreeNode* current = root;
//         while(current != NULL || !st.empty()) {
//             while(current != NULL) { // Go to the leftmost node
//                 st.push(current);
//                 current = current->left;
//             }
//             current = st.top();  // Get the node from stack
//             st.pop();
//             ans.push_back(current->val);     // Visit the root
//             current = current->right;  // Move to right subtree
//         }
//         return ans;
//     }
// };