class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s1.size();
        int m = s2.size();
        vector<int> freqS1(26,0);
        for(char c:s1){
            freqS1[c-'a']++;
        }
        int left=0;
        for(int right=0;right<m;right++){
            if(right-left+1==n){
                vector<int> freqS2(26,0);
                for(int i=left;i<=right;i++){
                    freqS2[s2[i]-'a']++;
                }
                if(freqS1==freqS2){
                    return true;
                }
                left++;
            }
        }
     return false;   
    }
};