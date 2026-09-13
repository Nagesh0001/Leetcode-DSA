//.Brute Force Approach. T.C :- O(n). S.C :- O(n)
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        string lastWord;
        while (ss >> word) {
            lastWord = word;
        }
        return lastWord.length();
    }
};


// //.Optimised / Iterative Approach. T.C :- O(n). S.C :- O(1)
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int i = s.length() - 1;
//         int count = 0;
//         while (i >= 0 && s[i] == ' ') {
//             i--;
//         }
//         while (i >= 0 && s[i] != ' ') {
//             count++;
//             i--;
//         }
//         return count;
//     }
// };