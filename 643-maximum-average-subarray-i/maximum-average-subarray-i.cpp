class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long currSum = 0;
        double maxAvg = -1e9;

        for(int j = 0; j < n; j++) {
            currSum += nums[j];

            if(j - i + 1 == k) {
                maxAvg = max(maxAvg, (double)currSum / k);
                currSum -= nums[i];  // remove left element
                i++;
            }
        }

        return maxAvg;
    }
};