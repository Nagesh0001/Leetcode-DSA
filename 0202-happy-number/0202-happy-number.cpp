// //.Brute Force Approach.  T.C :- O(K X D). S.D :- O(K)
class Solution {
public:
    // Digits ke squares ka sum calculate karta hai
    int getSum(int n) {
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1) {
            if(seen.count(n))
                return false;
            seen.insert(n);
            n = getSum(n);
        }
        return true;
    }
};


// //.Optimised Approach-Iterative+slow/Fast Pointer. T.C :- O(K X D). S.C :- O(1)
// class Solution {
// public:
//     int getSum(int n) {
//         int sum = 0;
//         while(n > 0) {
//             int digit = n % 10;
//             sum += digit * digit;
//             n = n / 10;
//         }
//         return sum;
//     }
//     bool isHappy(int n) {
//         int slow = n;
//         int fast = n;
//         do {
//             slow = getSum(slow);
//             fast = getSum(getSum(fast));
//         } while(slow != fast);
//         return slow == 1;
//     }
// };