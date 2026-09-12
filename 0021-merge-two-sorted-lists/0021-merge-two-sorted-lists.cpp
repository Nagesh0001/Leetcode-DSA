//.Brute Force Approach. T.C :- O((N+M) log(N+M)). S.C :- O(N+M)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        while (list1 != NULL) {
            arr.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != NULL) {
            arr.push_back(list2->val);
            list2 = list2->next;
        }
        sort(arr.begin(), arr.end());
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (int x : arr) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
        return dummy->next;
    }
};


// //.Optimized / Iterative Approach. T.C :- O(N + M). S.C :- O(1)
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* tail = dummy;
//         while (list1 != NULL && list2 != NULL) {
//             if (list1->val <= list2->val) {
//                 tail->next = list1;
//                 list1 = list1->next;
//             }
//             else {
//                 tail->next = list2;
//                 list2 = list2->next;
//             }
//             tail = tail->next;
//         }
//         if (list1 != NULL)
//             tail->next = list1;
//         else
//             tail->next = list2;
//         return dummy->next;
//     }
// };