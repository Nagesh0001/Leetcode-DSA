// //.Brute Force Approach. T.C :- O(n^2), S.C :- O(1), T.L.E
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         for (int i=0; i<nums.size(); i++) {
//             int count = 1;
//             int arr = nums[i];
//             for(int j=i+1; j<nums.size(); j++){
//                 if (arr == nums[j] && abs(i - j) <= k) return true;
//             }
//         }
//         return false;
//     }
// };


//.Optimise Approach. T.C :- O(n), S.C :- O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            // Check if element already exists in window
            if(st.count(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
            // Maintain window size k
            if(st.size() > k) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};