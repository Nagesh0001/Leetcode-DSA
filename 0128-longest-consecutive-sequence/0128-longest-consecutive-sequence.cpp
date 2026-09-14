// class Solution{
// public:
//     int longestConsecutive(vector<int>& nums){
//         if(nums.empty()) return 0;
//         sort(nums.begin(), nums.end());
//         int len = 1;
//         int mL = 1;
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i] == nums[i - 1]){
//                 continue;
//             }
//             else if(nums[i] == nums[i - 1] + 1){
//                 len++;
//             }
//             else{
//                 mL = max(mL, len);
//                 len = 1;
//             }
//         }
//         return max(mL, len);
//     }
// };





//.Two Pointer Approach
class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> s(nums.begin(), nums.end());
        int l = 0;
        for(int num : s){
            if(s.find(num - 1) == s.end()){
                int curr = num;
                int str = 1;
                while(s.find(curr + 1) != s.end()){
                    curr++;
                    str++;
                }
                l = max(l, str);
            }
        }
        return l;
    }
};
