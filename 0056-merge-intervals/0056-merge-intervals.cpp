// //.Brute Force Approach.
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ans;
//         for(int i = 0; i < intervals.size(); i++) {
//             int start = intervals[i][0];
//             int end = intervals[i][1];
//             for(int j = i + 1; j < intervals.size(); j++) {
//                 if(intervals[j][0] <= end &&
//                    intervals[j][1] >= start) {
//                     start = min(start, intervals[j][0]);
//                     end = max(end, intervals[j][1]);
//                 }
//             }
//             ans.push_back({start, end});
//         }
//         return ans;
//     }
// };


//.Brute Force Approach. T.C :- O(n^3)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        bool merged = true;
        while(merged) {
            merged = false;
            for(int i = 0; i < intervals.size(); i++) {
                for(int j = i + 1; j < intervals.size(); j++) {
                    if(intervals[i][0] <= intervals[j][1] &&
                       intervals[j][0] <= intervals[i][1]) {
                        intervals[i][0] =
                            min(intervals[i][0], intervals[j][0]);
                        intervals[i][1] =
                            max(intervals[i][1], intervals[j][1]);
                        intervals.erase(intervals.begin() + j);
                        merged = true;
                        break;
                    }
                }
                if(merged)
                    break;
            }
        }
        return intervals;
    }
};


// //.Optimised Approach. T.C :- O(n log n), S.C :- O(n)
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> ans;
//         ans.push_back(intervals[0]);
//         for(int i = 1; i < intervals.size(); i++) {
//             if(intervals[i][0] <= ans.back()[1]) {
//                 ans.back()[1] = max(ans.back()[1], intervals[i][1]);
//             }
//             else {
//                 ans.push_back(intervals[i]);
//             }
//         }
//         return ans;
//     }
// };