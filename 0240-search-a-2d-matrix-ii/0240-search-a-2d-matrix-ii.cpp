// // Brute Force Approach  T C:- O(m × n)    S C:- O(1)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };



// // Binary Search Approach    T C:- O(m log n), S C:- O(1)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         for(int i=0;i<rows;i++){
//             int left = 0;
//             int right = cols - 1;
//             while(left <= right){
//                 int mid = left + (right - left) / 2;
//                 if(matrix[i][mid] == target)
//                     return true;
//                 else if(matrix[i][mid] < target)
//                     left = mid + 1;
//                 else
//                     right = mid - 1;
//             }
//         }
//         return false;
//     }
// };



// // Optimal Approach    T C:- O(m + n),   S C:- O(1)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         int i = 0;
//         int j = cols - 1;
//         while(i < rows && j >= 0){
//             if(matrix[i][j] == target)
//                 return true;
//             else if(matrix[i][j] > target)
//                 j--;
//             else
//                 i++;
//         }
//         return false;
//     }
// };




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0;
        int j = cols - 1;
        while(i <= rows - 1 && j >= 0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};