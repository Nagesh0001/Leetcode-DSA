// //.Brute Force Approach. T.C = O(n^2), S.C = O(1), T.L.E
// class Solution{
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = 0;
//         for(int i=0; i<n; i++){
//             int minHeight = heights[i];
//             for(int j=i; j<n; j++){
//                 minHeight = min(minHeight, heights[j]);
//                 int width = j - i + 1;
//                 int area = minHeight * width;
//                 maxArea = max(maxArea, area);
//             }
//         }
//         return maxArea;
//     }
// };



//.Optimised Solution T.C = O(n), S.C = O(n)
class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};