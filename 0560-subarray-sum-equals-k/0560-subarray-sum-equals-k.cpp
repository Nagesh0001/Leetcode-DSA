//.Brute Force Approach. T.C :- O(n^2), S.C :- O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};


// //.Optimised Approach. T.C :- O(n). S.C :- O(n)
// class Solution {
// public:
//     int subarraySum(vector<int>& arr, int k) {
//         int n = arr.size();
//         int count = 0;
//         vector<int> prefixSum(n, 0);
//         prefixSum[0] = arr[0];
//         for(int i = 1; i < n; i++) {
//             prefixSum[i] = prefixSum[i - 1] + arr[i];
//         }
//         unordered_map<int, int> m;
//         for(int j = 0; j < n; j++) {
//             if(prefixSum[j] == k)
//                 count++;
//             int val = prefixSum[j] - k;
//             if(m.find(val) != m.end()) {
//                 count += m[val];
//             }
//             m[prefixSum[j]]++;
//         }
//         return count;
//     }
// };