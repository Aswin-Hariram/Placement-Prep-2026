class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n < k) return 0;

        long long ans = LLONG_MIN;
        long long sum = 0;

        int left = 0;

        for(int right = 0; right < n; right++) {

            sum += nums[right];

            // Window size becomes k
            if(right - left + 1 == k) {

                ans = max(ans, sum);

                // Slide window
                sum -= nums[left];
                left++;
            }
        }

        return ans;
    }
};
