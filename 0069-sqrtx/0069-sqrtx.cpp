//.Brute Force Approach. T.C :- O(root X). S.C :- O(1)
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int ans = 1;
        for (int i = 1; i <= x / i; i++) {
            if (i <= x / i)
                ans = i;
        }
        return ans;
    }
};


// //.Optimised Approach, Binary Search.  T.C :- O(log x). S.C :- O(1)
// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x < 2)
//             return x;
//         int left = 1;
//         int right = x;
//         int ans = 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (mid <= x / mid) {
//                 ans = mid;
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         return ans;
//     }
// };