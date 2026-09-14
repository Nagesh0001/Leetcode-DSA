class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int prefixsum = 0;
        m[0] = 1;
        int count = 0; prefixsum = 0;
        for(int i=0; i<nums.size(); i++){
            prefixsum+=nums[i];
            if(m.find(prefixsum-k) != m.end()){
                count+=m[prefixsum - k];
            }
            m[prefixsum]++;
        }
        return count;
    }
};





// //.Prefix Sum + Hash Map
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//          m[0] = 1; 
//         int prefixSum = 0;
//         int count = 0;
//         for(int i = 0; i < nums.size(); i++){
//             prefixSum += nums[i];
//             if(m.find(prefixSum - k) != m.end()){
//                 count += m[prefixSum - k];
//             }
//             m[prefixSum]++;
//         }
//         return count;
//     }
// };