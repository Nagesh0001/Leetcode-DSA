//.Brute Force Approach
class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if (s[0] == '-') {
            std::reverse(s.begin() + 1, s.end());
        }
        else {
            std::reverse(s.begin(), s.end());
        }
        long long num = stoll(s);
        if (num < INT_MIN || num > INT_MAX)
            return 0;
        return (int)num;
    }
};


// //.Optimise Approach
// class Solution {
// public:
//     int reverse(int x) {
//         int rev = 0;
//         while (x != 0) {
//             int digit = x % 10;
//             x = x / 10;
//             if (rev > INT_MAX / 10 ||
//                 (rev == INT_MAX / 10 && digit > 7))
//                 return 0;
//             if (rev < INT_MIN / 10 ||
//                 (rev == INT_MIN / 10 && digit < -8))
//                 return 0;
//             rev = rev * 10 + digit;
//         }
//         return rev;
//     }
// };