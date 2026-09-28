// //.Brute Force Approach. T.C :- O(n^3), S.C :- O(1), M.L.E
// class Solution {
// public:
//     bool isUnique(string s, int start, int end) {
//         vector<bool> seen(256, false);
//         for(int i = start; i <= end; i++) {
//             if(seen[s[i]]) {
//                 return false;
//             }
//             seen[s[i]] = true;
//         }
//         return true;
//     }
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int ans = 0;
//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {
//                 // Check karo substring mein duplicate hai ya nahi
//                 if(isUnique(s, i, j)) {
//                     ans = max(ans, j - i + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };


//.Optimized Approach — Sliding Window. T.C :- O(n), S.C :- O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int ans = 0;
        unordered_set<char> st;
        for(int right = 0; right < n; right++) {
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            // Current character window mein add karo
            st.insert(s[right]);
            // Current window ki maximum length
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


// //.Better Optimized Version. T.C :- O(n), S.C :- O(1)
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> last(256, -1);
//         int left = 0;
//         int ans = 0;
//         for(int right = 0; right < s.size(); right++) {
//             if(last[s[right]] >= left) {
//                 left = last[s[right]] + 1;
//             }
//             // Current character ka latest index store karo
//             last[s[right]] = right;
//             // Current window ki length
//             ans = max(ans, right - left + 1);
//         }
//         return ans;
//     }
// };