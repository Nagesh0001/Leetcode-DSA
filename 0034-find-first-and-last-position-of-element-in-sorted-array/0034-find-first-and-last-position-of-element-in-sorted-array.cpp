// //.Brute Force Approach. T.C :- O(n). S.C :- O(1); Restrictions Failed
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int first = -1;
//         int last = -1;
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target) {
//                 if(first == -1)
//                     first = i;
//                 last = i;
//             }
//         }
//         return {first, last};
//     }
// };


//.Optimised Approach - Binary search. T.C ;- O(logn). S.C :- O(logn)
class Solution {
public:
    int firstPosition(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                ans = mid;
                hi = mid - 1;
            }
            else if(nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
    int lastPosition(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                ans = mid;
                lo = mid + 1;
            }
            else if(nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPosition(nums, target);
        int last = lastPosition(nums, target);
        return {first, last};
    }
};