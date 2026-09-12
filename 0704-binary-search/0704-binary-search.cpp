//.Optimised Approach. T.C :- O(logn). S.c :- O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo <= hi){
            int mid = (hi + lo) / 2;
            //int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};


// //.Brute Force Approach. T.C :- O(n). S.C :- O(1)
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             // Check every element with target
//             if (nums[i] == target)
//                 return i;
//         }
//         // Target not found
//         return -1;
//     }
// };