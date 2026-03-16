class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                
                st.insert(grid[i][j]);

                for(int r=1; ; r++){
                    if(i-r<0 || i+r>=m || j-r<0 || j+r>=n) break;

                    int sum = 0;

                    
                    for(int k=0;k<r;k++)
                        sum += grid[i-r+k][j+k];

                    for(int k=0;k<r;k++)
                        sum += grid[i+k][j+r-k];


                    for(int k=0;k<r;k++)
                        sum += grid[i+r-k][j-k];


                    for(int k=0;k<r;k++)
                        sum += grid[i-k][j-r+k];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(int x: st){
            ans.push_back(x);
            if(ans.size()==3) break;
        }

        return ans;
    }
};