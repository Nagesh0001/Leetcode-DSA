//.Two Pointer Approach   T C:- O(n),  S C:- O(1)
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         vector<int> temp = nums;
//         vector<vector<int>> perms;
//         sort(temp.begin(), temp.end());
//         do {
//             perms.push_back(temp);
//         } while(next_permutation(temp.begin(), temp.end()));
//         for(int i=0; i<perms.size(); i++){
//             if(perms[i] == nums){
//                 if(i+1 < perms.size()){
//                     nums = perms[i+1];
//                 } else {
//                     nums = perms[0];
//                 }
//                 break;
//             }
//         }
//     }
// };



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if(i >= 0) {
            int j = n - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};




// //.Brute Force Approach   Memory Limit Exceeded
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         vector<int> temp = nums;
//         vector<vector<int>> perms;
//         sort(temp.begin(), temp.end());
//         do {
//             perms.push_back(temp);
//         } while(next_permutation(temp.begin(), temp.end()));
//         for(int i = 0; i < perms.size(); i++){
//             if(perms[i] == nums){
//                 if(i + 1 < perms.size()){
//                     nums = perms[i+1];
//                 } else {
//                     nums = perms[0];
//                 }
//                 break;
//             }
//         }
//     }
// };