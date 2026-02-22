class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int blocks = 1; 
        
        for (int i = 1; i < n; i++) {
            if (word[i] <= word[i - 1]) {
                blocks++;
            }
        }
        
        return blocks * 3 - n;
    }
};