class Solution {
private:
    void bfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int rh = q.front().first;
            int ch = q.front().second;
            q.pop();
            int delR[4]={-1,0,1,0};
            int delC[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newRow = delR[i] + rh;
                int newCol = delC[i] + ch;
                
                if(newRow>0 && newRow<n && newCol>0 && newCol<m && board[newRow][newCol]=='O' && !vis[newRow][newCol]){
                    vis[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]) bfs(0, j,board,vis);
        }

        for(int j = 0; j < m; j++){
            if(board[n-1][j] == 'O' && !vis[n-1][j]) bfs(n-1, j,board,vis);
        }

        for(int i = 1; i < n-1; i++){
            if(board[i][0] == 'O' && !vis[i][0]) bfs(i, 0,board,vis);
        }

        for(int i = 1; i < n-1; i++){
            if(board[i][m-1] == 'O' && !vis[i][m-1]) bfs(i, m-1,board,vis);
        }

        for(int i=1;i<n-1;++i){
            for(int j=1;j<m-1;++j){
                if(board[i][j]=='O' && vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};