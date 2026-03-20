class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;

        vector<int> mod1, mod2;

        for(int x : nums) {
            total += x;

            if(x % 3 == 1) mod1.push_back(x);
            else if(x % 3 == 2) mod2.push_back(x);
        }

        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if(total % 3 == 0) return total;

        int ans = 0;

        if(total % 3 == 1) {
            int option1 = (mod1.size() >= 1) ? total - mod1[0] : 0;
            int option2 = (mod2.size() >= 2) ? total - mod2[0] - mod2[1] : 0;
            ans = max(option1, option2);
        } 
        else { // total % 3 == 2
            int option1 = (mod2.size() >= 1) ? total - mod2[0] : 0;
            int option2 = (mod1.size() >= 2) ? total - mod1[0] - mod1[1] : 0;
            ans = max(option1, option2);
        }

        return ans;
    }
};