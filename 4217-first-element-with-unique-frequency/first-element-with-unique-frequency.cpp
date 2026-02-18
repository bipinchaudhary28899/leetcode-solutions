class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;   
        unordered_map<int,int> freqCount;

        for(auto i : nums){
            freq[i]++;
        }

        for(auto &i : freq){
            freqCount[i.second]++;
        }
        for(auto i : nums){
            if(freqCount[freq[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};
