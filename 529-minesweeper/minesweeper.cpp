class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int n = board.size();
        int m = board[0].size();
        
        queue<pair<int,int>> q;
        q.push({click[0], click[1]});
        
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        while(!q.empty()){
            
            auto [row, col] = q.front();
            q.pop();
            
            if(board[row][col] != 'E') continue;
            
            int count = 0;
            
        
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    
                    int newRow = row + i;
                    int newCol = col + j;
                    
                    if(newRow >= 0 && newRow < n &&
                       newCol >= 0 && newCol < m){
                        
                        if(board[newRow][newCol] == 'M'){
                            count++;
                        }
                    }
                }
            }
            
            if(count > 0){
                board[row][col] = '0' + count;
            }
            else{
                board[row][col] = 'B';
                
                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        
                        int newRow = row + i;
                        int newCol = col + j;
                        
                        if(newRow >= 0 && newRow < n &&
                           newCol >= 0 && newCol < m &&
                           board[newRow][newCol] == 'E'){
                            
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
        }
        
        return board;
    }
};
