//.Brute Force Approach. T.C :- O(m × n), S.C :- O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i = 0; i < m; i++) { // Original zero positions find karo
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {   // Stored rows aur columns ko zero karo
            for(int j = 0; j < n; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// //.Optimized Approach. T.C :- O(m X n). S.C :- O(1)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         bool firstRowZero = false;
//         bool firstColZero = false;
//         // Check first row
//         for(int j = 0; j < n; j++) {
//             if(matrix[0][j] == 0)
//                 firstRowZero = true;
//         }
//         // Check first column
//         for(int i = 0; i < m; i++) {
//             if(matrix[i][0] == 0)
//                 firstColZero = true;
//         }
//         // Main logic
//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 if(matrix[i][j] == 0) {
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//             }
//         }
//         // Marked rows ko zero karo
//         for(int i = 1; i < m; i++) {
//             if(matrix[i][0] == 0) {
//                 for(int j = 1; j < n; j++)
//                     matrix[i][j] = 0;
//             }
//         }
//         // Marked columns ko zero karo
//         for(int j = 1; j < n; j++) {
//             if(matrix[0][j] == 0) {
//                 for(int i = 1; i < m; i++)
//                     matrix[i][j] = 0;
//             }
//         }
//         // Finally first row
//         if(firstRowZero) {
//             for(int j = 0; j < n; j++)
//                 matrix[0][j] = 0;
//         }
//         // Finally first column
//         if(firstColZero) {
//             for(int i = 0; i < m; i++)
//                 matrix[i][0] = 0;
//         }
//     }
// };