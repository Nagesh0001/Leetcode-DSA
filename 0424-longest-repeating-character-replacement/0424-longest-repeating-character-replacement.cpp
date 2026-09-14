// //.Brute Force Approach. T.C :- O(n^2). S.C :- O(1)
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.length();
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             int freq[26] = {0};
//             int maxFreq = 0;
//             for (int j = i; j < n; j++) {
//                 freq[s[j] - 'A']++;
//                 maxFreq = max(maxFreq, freq[s[j] - 'A']);
//                 int windowLength = j - i + 1;
//                 int replacements = windowLength - maxFreq;
//                 if (replacements <= k) {
//                     ans = max(ans, windowLength);
//                 }
//             }
//         }
//         return ans;
//     }
// };


//.Optimised Approach — Sliding Window.  T.C :- O(n). S.C :- O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int ans = 0;
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};