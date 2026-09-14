/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//.Brute Force Approach. T.C :- O(N). S.C :- O(N)
class Solution {
public:
    TreeNode* build(vector<int>& nums, int left, int right) {
        if(left > right)
            return NULL;
        int mid = left + (right - left) / 2;   // Find middle
        TreeNode* root = new TreeNode(nums[mid]);  // Middle element becomes root
        root->left = build(nums, left, mid - 1); // Left half → left subtree
        root->right = build(nums, mid + 1, right); // Right half → right subtree
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL) { // Convert linked list to array
            nums.push_back(head->val);
            head = head->next;
        }
        return build(nums, 0, nums.size() - 1);     // Build balanced BST
    }
};


// //.Optimized Approach — Slow & Fast Pointer. T.C :- O(n log n) S.C :- O(log n)
// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         if(head == NULL) // Empty list
//             return NULL;
//         if(head->next == NULL) // Only one node
//             return new TreeNode(head->val);
//         ListNode* slow = head;  // slow will find middle
//         ListNode* prev = NULL; // prev stores node before middle
//         ListNode* fast = head; // fast moves twice as fast as slow
//         while(fast != NULL && fast->next != NULL) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         prev->next = NULL; // Break left half from middle
//         TreeNode* root = new TreeNode(slow->val); // Middle element becomes root
//         root->left = sortedListToBST(head); // Left half → left subtree
//         root->right = sortedListToBST(slow->next); // Right half → right subtree
//         return root;
//     }
// };