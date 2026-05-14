class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map<int,int> mp;
        mp[0] = -1;

        int sum = 0;
        int ans = 0;
        
        for(int right = 0; right<n; right++ ){
            if(nums[right]==0) sum--;
            else sum++;
               

            if(mp.find(sum) != mp.end()){
                int len = right - mp[sum];
                ans = max(ans,len);
            }
            else{
                mp[sum] = right;
            }
        }
        return ans;
    }
};
