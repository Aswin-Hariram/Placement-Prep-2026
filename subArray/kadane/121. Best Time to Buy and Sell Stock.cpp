class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int cur = 0;
        int ans = 0;

        for(int i = 1; i < prices.size(); i++) {

            int diff = prices[i] - prices[i-1];

            // Kadane
            cur = max(diff, cur + diff);

            ans = max(ans, cur);
        }

        return ans;
    }
};
