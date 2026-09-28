//.Main Approach — Backtracking + DFS. T.C :- O(m × n × 4^L), S.C :- O(L)
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,
            int i, int j, int index) {
        // Main logic
        if(index == word.size())
            return true;
        // Boundary check
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size())
            return false;
        // Character match nahi karta
        if(board[i][j] != word[index])
            return false;
        // Main logic:
        char temp = board[i][j];
        board[i][j] = '#';
        bool found =
            dfs(board, word, i + 1, j, index + 1) ||  // Down
            dfs(board, word, i - 1, j, index + 1) ||  // Up
            dfs(board, word, i, j + 1, index + 1) ||  // Right
            dfs(board, word, i, j - 1, index + 1);    // Left
        // Backtracking:
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // Har cell ko starting point maan kar try karo
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};