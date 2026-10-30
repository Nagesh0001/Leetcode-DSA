//.Brute Force Approach. T.C :- (O(n + mlog m)), S.C :- O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        vector<pair<int,int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }
};


// //.Best Approach. T.C :- O(n), S.C :- O(n)
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> freq;
//         for(int num : nums) {
//             freq[num]++;
//         }
//         vector<vector<int>> buckets(nums.size() + 1);
//         for(auto &p : freq) {
//             buckets[p.second].push_back(p.first);
//         }
//         vector<int> result;
//         for(int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
//             for(int num : buckets[i]) {
//                 result.push_back(num);
//                 if(result.size() == k)
//                     return result;
//             }
//         }
//         return result;
//     }
// };