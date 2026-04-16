class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }
        
        // If total sum is odd, no valid partitions
        if (totalSum % 2 != 0) return 0;
        
        // Otherwise, all partitions are valid
        return nums.size() - 1;
    }
};