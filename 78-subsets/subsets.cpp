class Solution {
public:
    
    void dfs(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans){
        ans.push_back(current);
        
        for(int i = index; i < nums.size(); i++){
            current.push_back(nums[i]);
            dfs(i + 1, nums, current, ans);
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        
        dfs(0, nums, current, ans);
        
        return ans;
    }
};