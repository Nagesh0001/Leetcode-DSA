//.Brute Force Approach. T.C :- O(n), S.C :- O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increasing = true;
        bool decreasing = true;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                increasing = false;
            }
            if(nums[i] < nums[i + 1]) {
                decreasing = false;
            }
        }
        return increasing || decreasing;
    }
};


// //.Optimised Approach - Single Traversal. T.C :- O(n), S.C :- O(1).
// class Solution {
// public:
//     bool isMonotonic(vector<int>& nums) {
//         int n = nums.size();
//         bool inc = true;
//         bool dec = true;
//         for(int i = 1; i < n; i++) {
//             // Check increasing order
//             if(nums[i] < nums[i - 1]) {
//                 inc = false;
//             }
//             // Check decreasing order
//             if(nums[i] > nums[i - 1]) {
//                 dec = false;
//             }
//             if(!inc && !dec) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };