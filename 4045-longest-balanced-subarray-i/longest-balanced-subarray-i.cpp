class Solution {
public:
    int longestBalanced(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    for(int start = 0; start < n; start++){
        unordered_map<int,int> oddFreq, evenFreq;
        for(int end = start; end < n; end++){
            int x = nums[end];
            if(x % 2 == 0)
                evenFreq[x]++;
            else
                oddFreq[x]++;
            
            if(oddFreq.size() == evenFreq.size())
                ans = max(ans, end-start+1);
        }
    }

    return ans;
}

};