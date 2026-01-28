class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentReach = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>currentReach) return false;
            currentReach=max(currentReach,i+nums[i]);
        }
        return true;

    }
};