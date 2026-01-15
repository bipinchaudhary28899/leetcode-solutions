class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int area=0;
        while(left<right){
            int currArea = min(height[left],height[right])*(right-left); 
                area=max(area,currArea);
            if(height[left]>height[right]) right--;
            else left++;
        }
        return area;
    }
};