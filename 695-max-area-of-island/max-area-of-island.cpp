class Solution {
private:
    int calculatedIslandArea(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int area=0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            area++;
            q.pop();
            int delRow[4]={-1,0,1,0};
            int delCol[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol]==1){
                    visited[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int area = calculatedIslandArea(i,j,visited,grid);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};