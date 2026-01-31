class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '{';
        
        for (char c : letters) {
            if (c > target && c < ans) {
                ans = c;
            }
        }


        if (ans == '{') return letters[0];

        return ans;
    }
};
