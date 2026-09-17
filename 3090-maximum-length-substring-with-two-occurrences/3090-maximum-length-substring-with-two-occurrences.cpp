//.Brute Force Approach. T.C :- O(N^2 X 26). S.C :- O(1)
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                bool valid = true;
                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 2) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }
};


// //.Optimised Approach - Sliding window
// class Solution {
// public:
//     int maximumLengthSubstring(string s) {
//         vector<int>freq(26, 0);
//         int left = 0;
//         int maxLength = 0;
//         for(int right = 0; right<s.size(); right++){
//             freq[s[right] - 'a']++;
//             while(freq[s[right] - 'a'] > 2){
//                 freq[s[left] - 'a']--;
//                 left++;
//             }
//             maxLength = max(maxLength, right - left + 1);
//         }
//         return maxLength;
//     }
// };