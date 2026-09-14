//.Brute Froce Approach (Time Limit Exceeded)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(nums[i] == nums[j])
//                 return true;
//             }
//         }
//         return false;
//     }
// };




// //.Hashing + Map Approach
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int>m;
//         for(int i=0; i<n; i++){
//             m[nums[i]]++;
//         }
//         for(auto x : m){
//             if(m[x.second] > 1){
//                 return true;
//                 }
//             }
//             return false;
//         }
// };




//.Set-based Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int,int>m;
        set<int>s;
        for(int i=0; i<n; i++){
            if(s.count(nums[i]) != 0)
            return true;
            s.insert(nums[i]);
        }
        return false;
    }
};




// //.Hash Set Approach (GALAT HAI Test cases not pass)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         unordered_set<int> s;

//         for(int i = 0; i < n; i++){
//             s.insert(nums[i]);
//             if(s.size() < nums.size())
//                 return true;
//             else
//                 return false;
//         }
//         return false;
//     }
// };
