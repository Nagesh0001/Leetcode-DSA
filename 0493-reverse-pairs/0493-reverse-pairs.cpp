// //. Time Limit Exceeded
// class Solution {
// public:
//    int reversePairs(vector<int>& nums) {
//        int n=nums.size();
//        int count=0;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=i+1;j<n;j++)
//            {
//                if(nums[i]>(long long)2*nums[j])
//                count++;
//            }
//        }
//        return count;
//    }
// };


// //.Brute Force Approach. T.C :- O(n²), S.C :- O(1))
// //.Time Limit Exceeded
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int count = 0;
//         int n = nums.size();
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 if((long long)nums[i] > 2LL * nums[j])
//                     count++;
//             }
//         }
//         return count;
//     }
// };


//.Optimized Approach — Merge Sort. 
class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        // Count reverse pairs
        int j = mid + 1;
        for(int i = left; i <= mid; i++) {
            while(j <= right &&
                  (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            // Main logic:
            // mid + 1 se j-1 tak valid reverse pairs hain
            count += j - (mid + 1);
        }
        // Normal merge
        vector<int> temp;
        int i = left;
        j = mid + 1;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= right) {
            temp.push_back(nums[j]);
            j++;
        }
        // Copy back
        for(int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int count = 0;
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};