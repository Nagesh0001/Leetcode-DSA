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
 //.Brute Force Approach. T.C :- O(N X M). S.C :- O(H)
class Solution {
public:
    bool check(ListNode* head, TreeNode* root) {
        if (head == NULL)
            return true;
        if (root == NULL)
            return false;
        if (head->val != root->val)
            return false;
        return check(head->next, root->left) ||
               check(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL)
            return false;
        if (check(head, root))
            return true;
        if (isSubPath(head, root->left))
            return true;
        return isSubPath(head, root->right);
    }
};


// //.Optimized Approach. T.C :- O(N + M). S.C :- O(M + H)
// class Solution {
// public:
//     vector<int> pattern;
//     vector<int> lps;
//     void makePattern(ListNode* head) {
//         while (head != NULL) {
//             pattern.push_back(head->val);
//             head = head->next;
//         }
//     }
//     void makeLPS() {
//         lps.resize(pattern.size(), 0);
//         int len = 0;
//         int i = 1;
//         while (i < pattern.size()) {
//             if (pattern[i] == pattern[len]) {
//                 len++;
//                 lps[i] = len;
//                 i++;
//             }
//             else {
//                 if (len != 0) {
//                     len = lps[len - 1];
//                 }
//                 else {

//                     lps[i] = 0;
//                     i++;
//                 }
//             }
//         }
//     }
//     bool dfs(TreeNode* root, int j) {
//         if (root == NULL)
//             return false;
//         while (j > 0 && root->val != pattern[j]) {
//             j = lps[j - 1];
//         }
//         if (root->val == pattern[j]) {
//             j++;
//         }
//         if (j == pattern.size())
//             return true;
//         return dfs(root->left, j) ||
//                dfs(root->right, j);
//     }
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         makePattern(head);
//         makeLPS();
//         return dfs(root, 0);
//     }
// };