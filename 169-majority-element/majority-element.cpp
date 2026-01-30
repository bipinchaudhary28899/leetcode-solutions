class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int countRequired=n/2;
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        for(auto it:mp){
            if(it.second>countRequired){
                return it.first;
            }
        }
        return -1;
    }
};