// //.Brute Force Approach. T.C :- O(n^2). S.C :- O(n)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         for(int i = 0; i < nums.size(); i++) {
//             int count = 0;
//             for(int j = 0; j < nums.size(); j++) {
//                 if(nums[i] == nums[j])
//                     count++;
//             }
//             if(count == 1) // Jo element sirf ek baar mila
//                 return nums[i];
//         }
//         return -1;
//     }
// };


// //.Better Approach -> Hashing. T.C :- O(n). S.C :- O(n)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(int x : nums)
//             mp[x]++;
//         for(auto it : mp) {
//             if(it.second == 1) // Jo element sirf ek baar aaya
//                 return it.first;
//         }
//         return -1;
//     }
// };


//.Optimised Approach -> XOR. T.C :- O(n). S.C :- O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int x : nums) {
            // Duplicate elements cancel each other
            ans = ans ^ x;
        }
        return ans;
    }
};