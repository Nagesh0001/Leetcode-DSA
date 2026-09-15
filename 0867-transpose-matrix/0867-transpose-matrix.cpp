class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();        // rows
        int n = matrix[0].size();     // columns
        vector<vector<int>> t(n, vector<int>(m));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                t[j][i] = matrix[i][j];
            }
        }
        return t;
    }
};





// class Solution {
// public:
//     vector<vector<int>> transpose(vector<vector<int>>& matrix) {
//         int m = matrix.size();        // rows
//         int n = matrix[0].size();     // columns
//         vector<vector<int>> ans(n, vector<int>(m));
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 ans[j][i] = matrix[i][j];
//             }
//         }
//         return ans;
//     }
// };
