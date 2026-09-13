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
//.Brute Force Approach. T.C :- O(nlogn). S.C :- O(nlogn)
class Solution {
public:
    TreeNode* build(vector<int> nums) {
        if (nums.empty())
            return NULL;
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = build(left);
        root->right = build(right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums);
    }
};


// //.Optimise Approach. T.C :- O(n).  S.C : O(logn)
// class Solution {
// public:
//     TreeNode* build(vector<int>& nums, int left, int right) {
//         if (left > right)
//             return NULL;
//         int mid = left + (right - left) / 2;
//         TreeNode* root = new TreeNode(nums[mid]);
//         root->left = build(nums, left, mid - 1);
//         root->right = build(nums, mid + 1, right);
//         return root;
//     }
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return build(nums, 0, nums.size() - 1);
//     }
// };