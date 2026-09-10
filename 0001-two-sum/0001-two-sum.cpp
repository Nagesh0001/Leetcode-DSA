// //.Brust Force Approach
// class Solution{
// public:
//     vector<int> twoSum(vector<int>& nums, int target){
//         int n = nums.size();
//         for(int i=0; i<n; i++){      // outer loop
//             for(int j=i+1; j<n; j++){     // inner loop
//                 if(nums[i] + nums[j] == target){    // check sum
//                     return {i, j};
//                 }
//             }
//         }
//         return {}; 
//     }
// };


//.Hash Map
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int need = target - nums[i];
            if(mp.find(need) != mp.end()){
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return{};
    }
};
