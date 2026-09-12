// //.Brute Force Approach T.C :- O(N²). S.C :- O(N)
// class Solution {
// public:
//     bool isValid(string s) {
//         bool changed = true;
//         while (changed) {
//             changed = false;
//             for (int i = 0; i < s.size() - 1; i++) {
//                 if ((s[i] == '(' && s[i + 1] == ')') ||
//                     (s[i] == '[' && s[i + 1] == ']') ||
//                     (s[i] == '{' && s[i + 1] == '}')) {
//                     s.erase(i, 2);
//                     changed = true;
//                     break;
//                 }
//             }
//         }
//         return s.empty();
//     }
// };


//.Optimised / Iterative 
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                if (st.empty())
                    return false;
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};