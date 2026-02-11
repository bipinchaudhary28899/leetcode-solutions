class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int m = guess.size();
        string ans="";
        unordered_map<char,int> mp; 
        int cows=0,bulls=0;
        for(int i=0;i<min(m,n);i++){
            if(secret[i]==guess[i]){
                bulls++;
                }
            else{
                if(mp[secret[i]] < 0) cows++;
                mp[secret[i]]++;
                if(mp[guess[i]] > 0) cows++;
                mp[guess[i]]--;
            }
        }
        ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;

    }
};