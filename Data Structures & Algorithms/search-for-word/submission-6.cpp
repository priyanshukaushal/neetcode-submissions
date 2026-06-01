class Solution {
public:
    bool helper(vector<vector<char>>& board, string &word, int i, int j, int k, int n, int m, vector<vector<bool>> &visited) {
        if(k==word.length()) return true;
        if(i >=n || j >= m || i < 0 || j < 0) return false;
        if(visited[i][j]) return false;
        if(board[i][j] != word[k]) return false;

        visited[i][j] = 1;

        bool left = helper(board,word,i-1,j,k+1,n,m,visited);
        bool right = helper(board,word,i+1,j,k+1,n,m,visited);
        bool up = helper(board,word,i,j-1,k+1,n,m,visited);
        bool down = helper(board,word,i,j+1,k+1,n,m,visited);

        bool res = left||right||up||down;
        if(res) return true;
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(helper(board,word,i,j,0,n,m,visited)) return true;
                }
            }
        }
        return false;
    }
};
