// //.Brute Force Approach. T.C :- O(N^2). S.C :- O(1)
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& he) {
//         int n = he.size();
//         int maxArea = INT_MIN;
//         for(int i = 0; i < n; i++) {
//             int currHeight = he[i];
//             int currArea = currHeight;
//             // Check left side
//             for(int left = i - 1; left >= 0; left--) {
//                 if(he[left] < currHeight)
//                     break;
//                 currArea += currHeight;
//             }
//             // Check right side
//             for(int right = i + 1; right < n; right++) {
//                 if(he[right] < currHeight)
//                     break;
//                 currArea += currHeight;
//             }
//             maxArea = max(maxArea, currArea);
//         }
//         return maxArea;
//     }
// };


//.Optimised Approach. T.C :- O(n), S.C :- O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;
        // Right Smaller
        for(int i = n - 1; i >= 0; i--) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        // Left Smaller
        for(int i = 0; i < n; i++) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};