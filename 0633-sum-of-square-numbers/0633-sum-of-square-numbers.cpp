//.Brute Force Approach. 
class Solution {
public:
    bool isPerfectSquare(long long n) {
        long long root = sqrt(n);
        return root * root == n;
    }
    bool judgeSquareSum(int c) {
        for(long long a = 0; a * a <= c; a++) {
            long long b = c - a * a;
            if(isPerfectSquare(b))
                return true;
        }
        return false;
    }
};


// //.Optimised - Two Pointer Approach
// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         long long a = 0;
//         long long b = sqrt(c);
//         while(a <= b) {
//             long long sum = a * a + b * b; 
//             if(sum == c)
//                 return true;
//             else if(sum < c)
//                 a++;
//             else
//                 b--;
//         }
//         return false;
//     }
// };


// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         long long x = 0;
//         long long y = sqrt(c);
//         while(x <= y) {
//             long long sum = x * x + y * y;
//             if(sum == c)
//                 return true;
//             else if(sum < c)
//                 x++;
//             else
//                 y--;
//         }
//         return false;
//     }
// };