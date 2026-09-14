// //.Brute Force Approach.   T.L.E For this Solution
// class Solution {
// public:
//     int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
//         unordered_map<string, int> mp;
//         int ans = 0;
//         for(int len = minSize; len <= maxSize; len++) {
//             for(int i = 0; i + len <= s.size(); i++) {
//                 string sub = s.substr(i, len);
//                 unordered_set<char> st;
//                 for(char ch : sub) {
//                     st.insert(ch);
//                 }
//                 if(st.size() <= maxLetters) {
//                     mp[sub]++;
//                     ans = max(ans, mp[sub]);
//                 }
//             }
//         }
//         return ans;
//     }
// };


//.Optimized Approach — Hash Map + Sliding Window
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        int ans = 0;
        // Only minSize is sufficient
        for(int i = 0; i + minSize <= s.size(); i++) {
            string sub = s.substr(i, minSize);
            unordered_set<char> st;     // Store distinct characters
            for(char ch : sub) {
                st.insert(ch);
            }
            // Check if distinct characters are within limit
            if(st.size() <= maxLetters) {
                mp[sub]++;
                ans = max(ans, mp[sub]); // Update maximum frequency
            }
        }
        return ans;
    }
};


// //.Better Optimized Version
// class Solution {
// public:
//     int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
//         unordered_map<string, int> mp;
//         int count[26] = {0};
//         int distinct = 0;
//         int ans = 0;
//         for(int i = 0; i < s.size(); i++) {
//             if(count[s[i] - 'a'] == 0) // Add current character
//                 distinct++;
//             count[s[i] - 'a']++;
//             // Remove character if window becomes too large
//             if(i >= minSize) {
//                 char remove = s[i - minSize];
//                 count[remove - 'a']--;
//                 if(count[remove - 'a'] == 0)
//                     distinct--;
//             }
//             if(i >= minSize - 1) { // Window size = minSize
//                 if(distinct <= maxLetters) { // Check distinct character limit
//                     string sub = s.substr(i - minSize + 1, minSize);
//                     mp[sub]++;
//                     ans = max(ans, mp[sub]);
//                 }
//             }
//         }
//         return ans;
//     }
// };