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
//.Brute Force Approach. T.C :- O(N). S.C :- O(H)
class Solution {
public:
    int ans = 0;
    vector<int> path;
    void solve(TreeNode* root, vector<int>& path) {
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            int num = 0;
            for(int digit : path) {
                num = num * 10 + digit;
            }
            ans += num;
        }
        solve(root->left, path);
        solve(root->right, path);
        path.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        solve(root, path);
        return ans;
    }
};


// //.Iterative Approach Algorithm. T.C :- O(N). S.C :- O(N)
// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         if(head == NULL) // Empty list
//             return NULL;
//         if(head->next == NULL) // Only one node
//             return new TreeNode(head->val);
//         ListNode* slow = head; // slow will find middle
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
