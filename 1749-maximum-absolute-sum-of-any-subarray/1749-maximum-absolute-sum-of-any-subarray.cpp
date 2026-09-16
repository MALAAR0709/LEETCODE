class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currentMax = 0;
        int maxsum = 0;
        int currentMin = 0;
        int minsum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            currentMax = max(0,currentMax+nums[i]);
            maxsum = max(currentMax,maxsum);
            currentMin = min(0,currentMin+nums[i]);
            minsum = min(currentMin,minsum);
        }
        return max(maxsum,-minsum);
    }
};