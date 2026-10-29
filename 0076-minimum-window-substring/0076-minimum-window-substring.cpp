// //.Brute Force Approach. T.C :- O(n^3), S.C :- O(n), T.L.E
// class Solution{
// public:
//    bool hasAllRequiredChars(string& segment, string& t){
//        int freq[256] = {0};
//        // Count each character in the pattern string
//        for (char ch : t)
//            freq[ch]++;
//        // Reduce the frequency based on characters in the current segment
//        for (char ch : segment) {
//            if (freq[ch] > 0)
//                freq[ch]--;
//        }
//        // Verify if any character is still missing
//        for (int i = 0; i < 256; i++) {
//            if (freq[i] > 0)
//                return false;
//        }
//        return true;
//    }
//    string minWindow(string s, string t) {
//        int sSize = s.length();
//        int tSize = t.length();
//        string result = "";
//        int minLength = INT_MAX;
//        // Iterate over all possible substrings of s
//        for (int left = 0; left < sSize; ++left) {
//            for (int right = left; right < sSize; ++right) {
//                string sub = s.substr(left, right - left + 1);
//                // If this substring contains all characters from t
//                if (hasAllRequiredChars(sub, t)) {
//                    int subLen = sub.length();
//               // Update result if this is the smallest valid substring so far
//                    if (subLen < minLength) {
//                        minLength = subLen;
//                        result = sub;
//                    }
//                }
//            }
//        }
//        return result;
//    }
// };


//.Better Approach. T.C :- O(nlog(n)), S.C :- O(1)
class Solution {
public:
   // Helper function to check if a substring of given length includes all characters of target
   bool containsPatternInWindow(string& text, string& pattern, int windowLen, int& matchStart) {
       int freq[256] = {0};
       int uniqueChars = 0;
       // Count frequency of characters in pattern
       for (char ch : pattern) {
           if (freq[ch] == 0) uniqueChars++;
           freq[ch]++;
       }
       int matched = 0;
       for (int i = 0; i < text.length(); ++i) {
           freq[text[i]]--;
           if (freq[text[i]] == 0)
               matched++;
           if (i >= windowLen) {
               freq[text[i - windowLen]]++;
               if (freq[text[i - windowLen]] == 1)
                   matched--;
           }
           if (i >= windowLen - 1) {
               if (matched == uniqueChars) {
                   matchStart = i - windowLen + 1;
                   return true;
               }
           }
       }
       return false;
   }
   string minWindow(string s, string t) {
       int sLen = s.size();
       int tLen = t.size();
       if (sLen < tLen) return "";
       int left = tLen, right = sLen;
       int minWindowLength = INT_MAX;
       int windowStartIndex = -1;
       // Binary search to minimize the window size
       while (left <= right) {
           int mid = (left + right) / 2;
           int currentStart;
           if (containsPatternInWindow(s, t, mid, currentStart)) {
               if (mid < minWindowLength) {
                   minWindowLength = mid;
                   windowStartIndex = currentStart;
               }
               right = mid - 1;
           } else {
               left = mid + 1;
           }
       }
       if (windowStartIndex == -1) return "";
       return s.substr(windowStartIndex, minWindowLength);
   }
};


// //.Best Approach. T.C :- O(n), S.C :- O(1)
// class Solution{
// public:
//    string minWindow(string s, string t){
//        int target[256] = {0};  // Character frequency in t
//        for (char ch : t) {
//            target[ch]++;
//        }
//        int n = s.length();
//        int i = 0, j = 0;
//        int count = 0;
//        int required = t.length();
//        int start = 0;
//        int minLen = INT_MAX;
//        while (j < n) {
//         // Decrease the frequency and increase count only if character is needed
//            if (target[s[j]] > 0) {
//                count++;
//            }
//            target[s[j]]--;
//            // If all required characters are in the window
//            while (count == required) {
//                if (minLen > j - i + 1) {
//                    minLen = j - i + 1;
//                    start = i;
//                }
//                // Restore character back to target count
//                target[s[i]]++;
//                // If that character is needed in t, reduce the match count
//                if (target[s[i]] > 0) {
//                    count--;
//                }
//                i++;
//            }
//            j++;
//        }
//        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
//    }
// };