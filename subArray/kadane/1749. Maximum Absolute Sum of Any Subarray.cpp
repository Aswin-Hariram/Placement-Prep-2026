class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int maxCur = nums[0];
        int maxSum = nums[0];

        int minCur = nums[0];
        int minSum = nums[0];

        for(int i=1; i<nums.size(); i++) {

            // Maximum subarray sum
            maxCur = max(nums[i], maxCur + nums[i]);
            maxSum = max(maxSum, maxCur);

            // Minimum subarray sum
            minCur = min(nums[i], minCur + nums[i]);
            minSum = min(minSum, minCur);
        }

        

        return max(maxSum, abs(minSum));
    }
};
