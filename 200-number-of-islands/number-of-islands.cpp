class Solution {
private:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int column = q.front().second;
            q.pop();
            int delRow[4]={-1,0,1,0};
            int delCol[4]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newRow = row+delRow[i];
                int newCol = column+delCol[i];
                if(newRow<n && newRow>=0 && newCol<m && newCol>=0 && grid[newRow][newCol]=='1' && vis[newRow][newCol]==0){
                    vis[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};