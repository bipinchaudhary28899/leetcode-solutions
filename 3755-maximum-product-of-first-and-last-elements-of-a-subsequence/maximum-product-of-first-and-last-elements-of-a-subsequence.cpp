class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long ans = LLONG_MIN;

        long long maxVal = nums[0];
        long long minVal = nums[0];

        for(int j = m - 1; j < n; j++) {
            int i = j - m + 1;

            maxVal = max(maxVal, (long long)nums[i]);
            minVal = min(minVal, (long long)nums[i]);

            ans = max({
                ans,
                maxVal * nums[j],
                minVal * nums[j]
            });
        }

        return ans;
    }
};