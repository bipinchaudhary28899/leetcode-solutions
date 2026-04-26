class Solution {
private:
    bool detectCycle(int row, int col,
                     vector<vector<int>>& vis,
                     vector<vector<char>>& grid,
                     int n, int m) {

        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({{row, col}, {-1, -1}});
        vis[row][col] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int nr = curr.first.first;
            int nc = curr.first.second;
            int pr = curr.second.first;
            int pc = curr.second.second;

            for (int i = 0; i < 4; i++) {
                int newRow = nr + delRow[i];
                int newCol = nc + delCol[i];

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
                    continue;

                if (grid[newRow][newCol] != grid[nr][nc])
                    continue;

                if (vis[newRow][newCol] &&
                    !(newRow == pr && newCol == pc))
                    return true;

                if (!vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, {nr, nc}});
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (detectCycle(i, j, vis, grid, n, m))
                        return true;
                }
            }
        }
        return false;
    }
};
