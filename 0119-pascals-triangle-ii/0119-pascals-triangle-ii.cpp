//.Brute Force Approach. T.C :- O(n^2). S.C :- O(n^2)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle[rowIndex];
    }
};


// //.Optimized Approach. T.C :- O(n^2). S.C :- O(n)
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> row(rowIndex + 1, 0);
//         row[0] = 1;
//         for (int i = 1; i <= rowIndex; i++) {
//             for (int j = i; j >= 1; j--) {
//                 row[j] = row[j] + row[j - 1];
//             }
//         }
//         return row;
//     }
// };