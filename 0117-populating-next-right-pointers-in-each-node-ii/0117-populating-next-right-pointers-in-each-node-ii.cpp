/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//.Brute Force Approach. T.C :- O(n). S.C :- O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* prev = NULL;
            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                // Previous node ko current node se connect karo
                if (prev != NULL) {
                    prev->next = curr;
                }
                prev = curr;
                // Left child ko queue me add karo
                if (curr->left != NULL)
                    q.push(curr->left);
                // Right child ko queue me add karo
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            // Har level ke last node ka next NULL hoga
            prev->next = NULL;
        }
        return root;
    }
};


// //.Optimized / Iterative Approach. T.C :- O(n).  S.C :- O(1)
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (root == NULL)
//             return NULL;
//         Node* head = root;
//         while (head != NULL) {
//             // Dummy node next level ko connect karne ke liye
//             Node dummy(0);
//             // Tail next level ke last connected node ko track karega
//             Node* tail = &dummy;
//             Node* curr = head;
//             while (curr != NULL) {
//                 // Left child ko next level me add karo
//                 if (curr->left != NULL) {
//                     tail->next = curr->left;
//                     tail = tail->next;
//                 }
//                 // Right child ko next level me add karo
//                 if (curr->right != NULL) {
//                     tail->next = curr->right;
//                     tail = tail->next;
//                 }
//                 // Current level ke next node par jao
//                 curr = curr->next;
//             }
//             // Dummy ke next se next level ka first node milega
//             head = dummy.next;
//         }
//         return root;
//     }
// };