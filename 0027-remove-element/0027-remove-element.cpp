//.Brute Force Approach. T.C :- O(n^2). S.C :- O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            // Agar current element val ke equal hai
            if (nums[i] == val) {
                // Next elements ko left shift karo
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                // Effective size decrease karo
                n--;
            }
            else {
                // Agar val nahi hai to next element par jao
                i++;
            }
        }
        return n;
    }
};


// //.Optimized / Iterative Approach.  T.C :- O(n). S.C :- O(1)
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int k = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             // Agar element val nahi hai
//             if (nums[i] != val) {
//                 nums[k] = nums[i];
//                 // Next valid element ke liye k increase karo
//                 k++;
//             }
//         }
//         // k = remaining elements ki count
//         return k;
//     }
// };
