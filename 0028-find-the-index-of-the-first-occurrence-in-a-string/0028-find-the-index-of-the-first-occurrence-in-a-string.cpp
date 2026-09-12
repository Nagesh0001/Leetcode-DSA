//.Brute Force Approach. T.C :- O(N X M).  S.C :- O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        // Har possible starting position check karo
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            // needle ke characters compare karo
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            // Agar poori needle match ho gayi
            if (j == m) {
                return i;
            }
        }
        // Needle nahi mili
        return -1;
    }
};


// //.Optimized Algorithm. T.C :- O(N + M).  S.C :- O(M)
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.size();
//         int m = needle.size();
//         if (m == 0)
//             return 0;
//         // LPS array banate hain
//         vector<int> lps(m, 0);
//         int len = 0;
//         int i = 1;
//         // Needle ka LPS calculate karo
//         while (i < m) {
//             if (needle[i] == needle[len]) {
//                 // Matching prefix ki length increase karo
//                 len++;
//                 lps[i] = len;
//                 i++;
//             }
//             else {
//                 if (len != 0) {
//                     // Previous LPS par jump karo
//                     len = lps[len - 1];
//                 }
//                 else {
//                     // Koi matching prefix nahi mila
//                     lps[i] = 0;
//                     i++;
//                 }
//             }
//         }
//         // Haystack me needle search karo
//         i = 0;
//         int j = 0;
//         while (i < n) {
//             if (haystack[i] == needle[j]) {
//                 // Characters match hue
//                 i++;
//                 j++;
//             }
//             // Puri needle match ho gayi
//             if (j == m) {
//                 return i - j;
//             }
//             // Mismatch hua
//             else if (i < n && haystack[i] != needle[j]) {
//                 if (j != 0) {
//                     // Needle ko beginning se restart nahi karna
//                     j = lps[j - 1];
//                 }
//                 else {
//                     // Needle ka first character bhi match nahi hua
//                     i++;
//                 }
//             }
//         }
//         // Needle nahi mili
//         return -1;
//     }
// };