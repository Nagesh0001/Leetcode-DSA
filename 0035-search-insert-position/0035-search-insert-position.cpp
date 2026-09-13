//.Brute Force Approach. T.C :- O(n).  S.C :- O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.size();
    }
};


// //.Optimized / Iterative Approach. T.C :- O(nlogn). S.C :- O(1)
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] < target) {
//                 left = mid + 1;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
//         return left;
//     }
// };