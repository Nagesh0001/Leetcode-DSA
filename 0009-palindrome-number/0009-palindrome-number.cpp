//.Brute Force Approach
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};


// //.Optimised Approach
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0)
//             return false;
//         int original = x;
//         int rev = 0;
//         while (x != 0) {
//             int digit = x % 10;
//             rev = rev * 10 + digit;
//             x = x / 10;
//         }
//         return original == rev;
//     }
// };