//.Brute Force Approach. T.C :- O(n^2)  S.C(n)
class Solution {
public:
    bool isValid(string s) {
        while (s.find("abc") != string::npos) {
            int pos = s.find("abc");
            s.erase(pos, 3);
        }
        return s.empty();
    }
};


// //.Optimised Approach — Stack.  T.C :- O(n)  S.C :- O(n)
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for (char ch : s) {
//             if (ch == 'a' || ch == 'b') {
//                 st.push(ch);
//             }
//             else {
//                 if (st.size() < 2)
//                     return false;
//                 if (st.top() != 'b')
//                     return false;
//                 st.pop();
//                 if (st.top() != 'a')
//                     return false;
//                 st.pop();
//             }
//         }
//         return st.empty();
//     }
// };