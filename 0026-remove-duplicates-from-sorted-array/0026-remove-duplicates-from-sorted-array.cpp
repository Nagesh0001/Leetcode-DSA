//.Brute Force Approach  T.C :- O(n). S.C :- O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (temp.empty() || temp.back() != nums[i]) {
                temp.push_back(nums[i]);
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }
        return temp.size();
    }
};


// //.Optimise Approach
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() == 0)
//             return 0;
//         int i = 0;
//         for (int j = 1; j < nums.size(); j++) {
//             if (nums[i] != nums[j]) {
//                 i++;
//                 nums[i] = nums[j];
//             }
//         }
//         return i + 1;
//     }
// };


// //.Using Map. T.C :- O(N log N). S.C :- O(n)
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         map<int, int> mp;
//         // Store frequency of every element
//         for (int i = 0; i < nums.size(); i++) {
//             mp[nums[i]]++;
//         }
//         int index = 0;
//         // Copy unique elements back to nums
//         for (auto it : mp) {
//             nums[index] = it.first;
//             index++;
//         }
//         return index;
//     }
// };