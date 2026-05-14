class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix;
        prefix.push_back(0);

        for(int num : nums){
            prefix.push_back(prefix.back() + num);
        }

        for(int p:prefix){
            cout<<p<<" ";
        }

        for(int i = 0; i < n; i++) {
            int leftSum = prefix[i];
            int rightSum = prefix[n] - prefix[i+1];

            if(leftSum == rightSum)
                return i;
        }

        return -1;
    }
};
