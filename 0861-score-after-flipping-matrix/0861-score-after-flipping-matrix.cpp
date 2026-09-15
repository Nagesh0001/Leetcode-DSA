//.Greedy Approach   T C:- O(m × n),   S C:- O(1)
class Solution{
public:
    int matrixScore(vector<vector<int>>& grid){
        int rows = grid.size();
        int columns = grid[0].size();
        // Step 1: Make sure the first column is all 1s
        for(int i=0; i<rows; i++){
            if(grid[i][0] == 0) {
                for(int j=0; j<columns; j++){
                    grid[i][j] = 1 - grid[i][j]; 
                }
            }
        }
        // Step 2: For remaining columns, maximize the number of 1s
        for(int j=1; j<columns; j++){
            int countOnes = 0;
            for(int i=0; i<rows; i++){
                if(grid[i][j] == 1) countOnes++;
            }
            if(countOnes < rows - countOnes) { 
                for(int i=0; i<rows; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        // Step 3: Calculate the total score
        int sum = 0;
        for(int i=0; i<rows; i++){
            int rowValue = 0;
            for(int j=0; j<columns; j++){
                rowValue = rowValue * 2 + grid[i][j]; 
            }
            sum += rowValue;
        }
        return sum;
    }
};




// //Brute Force Approach   
// class Solution {
// public:
//     int getScore(vector<vector<int>> grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int sum = 0;
//         for(int i=0;i<m;i++){
//             int val = 0;
//             for(int j=0;j<n;j++){
//                 val = val*2 + grid[i][j];
//             }
//             sum += val;
//         }
//         return sum;
//     }
//     void flipRow(vector<vector<int>>& grid,int r){
//         for(int j=0;j<grid[0].size();j++)
//             grid[r][j] ^= 1;
//     }
//     void flipCol(vector<vector<int>>& grid,int c){
//         for(int i=0;i<grid.size();i++)
//             grid[i][c] ^= 1;
//     }
//     int matrixScore(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int ans = 0;
//         for(int rMask = 0; rMask < (1<<m); rMask++){
//             for(int cMask = 0; cMask < (1<<n); cMask++){
//                 vector<vector<int>> temp = grid;
//                 for(int i=0;i<m;i++)
//                     if(rMask & (1<<i))
//                         flipRow(temp,i);
//                 for(int j=0;j<n;j++)
//                     if(cMask & (1<<j))
//                         flipCol(temp,j);
//                 ans = max(ans, getScore(temp));
//             }
//         }
//         return ans;
//     }
// };