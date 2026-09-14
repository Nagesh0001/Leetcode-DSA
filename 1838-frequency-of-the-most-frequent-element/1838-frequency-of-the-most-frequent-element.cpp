// //.Brute Force Approach
// class Solution{
// public:
//     int maxFrequency(vector<int>& nums, int k){
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int ans = 1;
//         for(int i=0; i<n; i++){
//             int curr = nums[i];
//             long long ops = 0;
//             int count = 1;
//             for(int j=i-1; j>=0; j--){
//                 ops += curr - nums[j];
//                 if(ops > k) break;
//                 count++;
//             }
//             ans = max(ans, count);
//         }
//         return ans;
//     }
// };




// //.Simple Brute Force Approach  (Wrong)
// class Solution{
// public:
//     int maxFrequency(vector<int>& nums, int k){
//         int maxFreq = 0;
//         for(int i=0; i<nums.size(); i++){   
//             int count = 0;                       
//             for(int j=0; j<nums.size(); j++){
//                 if(nums[j] == nums[i])
//                     count++;
//             }
//             maxFreq = max(maxFreq, count);       
//         }
//         return maxFreq;
//     }
// };





//.Optimized Sliding Window + Greedy approach
class Solution{
public:
    int maxFrequency(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int left = 0, ans = 1;
        for(int r=0; r<nums.size(); r++){
            sum += nums[r];
            while((long long)nums[r] * (r - left + 1) - sum > k){
                sum -= nums[left];
                left++;
            }
            ans = max(ans, r - left + 1);
        }
        return ans;
    }
};