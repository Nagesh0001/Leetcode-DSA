// //.Brute Force Approach. T.C :- O(n). S.C :- O(n)
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         long long num = 0;
//         for (int i = 0; i < digits.size(); i++) {
//             num = num * 10 + digits[i];
//         }
//         num = num + 1;
//         vector<int> ans;
//         while (num > 0) {
//             ans.push_back(num % 10);
//             num = num / 10;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };


//.Optimised Approach. T.C :- O(n). S.C :- O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};