class Solution {
private:
    bool isValidCube(vector<vector<char>> &matrix, int startRow, int startCol){
        vector<int> arr(9, 0);

        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(matrix[i][j] == '.') continue;

                int idx = matrix[i][j] - '1';
                arr[idx]++;
                if(arr[idx] > 1) return false;
            }
        }
        return true;
    }

    bool isValidRow(vector<vector<char>> &board, int r){
        vector<int> arr(9, 0);
        for(int c = 0; c < 9; c++){
            if(board[r][c] == '.') continue;

            int idx = board[r][c] - '1';
            arr[idx]++;
            if(arr[idx] > 1) return false;
        }
        return true;
    }

    bool isValidColumn(vector<vector<char>> &board, int c){
        vector<int> arr(9, 0);
        for(int r = 0; r < 9; r++){
            if(board[r][c] == '.') continue;

            int idx = board[r][c] - '1';
            arr[idx]++;
            if(arr[idx] > 1) return false;
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if(!isValidRow(board, i)) return false;
            if(!isValidColumn(board, i)) return false;
        }


        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if(!isValidCube(board, i, j)) return false;
            }
        }

        return true;
    }
};
