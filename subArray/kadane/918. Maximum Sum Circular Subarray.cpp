class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int currMax = 0, maxSum = nums[0];
        int currMin = 0, minSum = nums[0];

        for(int num : nums){

            // Normal Kadane
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            // Min Kadane
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);

            total += num;
        }

        // all negative case
        if(maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};
