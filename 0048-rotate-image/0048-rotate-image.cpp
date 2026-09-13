//.Approach: Transpose + Reverse   T C: O(n²), S C: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
        // Step 1: Transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // Step 2: Reverse each row
        for(int i = 0; i < n; i++){
            int start = 0, end = n - 1;
            while(start < end){
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start++;
                end--;
            }
        }
    }
};