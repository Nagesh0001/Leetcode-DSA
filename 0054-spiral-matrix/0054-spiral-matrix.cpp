//.Brute Force Approach     T C:- O(m*n),   S C:- O(m*n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> result;
        int total = m * n;
        int count = 0;
        // Directions: right, down, left, up
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int r = 0, c = 0, dir = 0;
        while(count < total) {
            result.push_back(matrix[r][c]);
            visited[r][c] = true;
            count++;
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                r = nr;
                c = nc;
            } else {
                dir = (dir + 1) % 4; // Change direction
                r += dr[dir];
                c += dc[dir];
            }
        }
        return result;
    }
};



// //.Two Pointer / Layer Approach   T C:- O(m*n),  S C:- O(1)
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         vector<int> result;
//         int m = matrix.size();
//         if(m == 0) return result;
//         int n = matrix[0].size();
//         int top = 0, bottom = m-1, left = 0, right = n-1;
//         while(top <= bottom && left <= right) {
//             // Top row
//             for(int j=left; j<=right; j++) result.push_back(matrix[top][j]);
//             top++;
//             // Right column
//             for(int i=top; i<=bottom; i++) result.push_back(matrix[i][right]);
//             right--;
//             // Bottom row 
//             if(top <= bottom){
//                 for(int j=right; j>=left; j--) result.push_back(matrix[bottom][j]);
//                 bottom--;
//             }
//             // Left column 
//             if(left <= right){
//                 for(int i=bottom; i>=top; i--) result.push_back(matrix[i][left]);
//                 left++;
//             }
//         }
//         return result;
//     }
// };