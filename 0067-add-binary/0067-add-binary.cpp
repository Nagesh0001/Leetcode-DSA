// //.Brute Force Approach. T.C :- O(N+M). S.C :- O(N+M)
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         long long x = 0, y = 0;
//         for (char c : a) {
//             x = x * 2 + (c - '0');
//         }
//         for (char c : b) {
//             y = y * 2 + (c - '0');
//         }
//         long long sum = x + y;
//         if (sum == 0)
//             return "0";
//         string ans;
//         while (sum > 0) {
//             ans += char((sum % 2) + '0');
//             sum /= 2;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };


//.Optimised / Iterative Approach.
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            ans += char((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};