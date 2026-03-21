class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int i, int j) {
        // center must be 5
        if(g[i+1][j+1] != 5) return false;

        vector<int> seen(10, 0);

        for(int x = i; x < i+3; x++) {
            for(int y = j; y < j+3; y++) {
                int val = g[x][y];
                if(val < 1 || val > 9 || seen[val]) return false;
                seen[val] = 1;
            }
        }

        // check sums
        for(int x = 0; x < 3; x++) {
            if(g[i+x][j] + g[i+x][j+1] + g[i+x][j+2] != 15) return false;
            if(g[i][j+x] + g[i+1][j+x] + g[i+2][j+x] != 15) return false;
        }

        if(g[i][j] + g[i+1][j+1] + g[i+2][j+2] != 15) return false;
        if(g[i][j+2] + g[i+1][j+1] + g[i+2][j] != 15) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for(int i = 0; i + 2 < m; i++) {
            for(int j = 0; j + 2 < n; j++) {
                if(isMagic(grid, i, j)) count++;
            }
        }

        return count;
    }
};