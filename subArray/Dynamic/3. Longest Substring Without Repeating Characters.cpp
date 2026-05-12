class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;

        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right++ ){
            
            mp[s[right]]++;
            if(mp[s[right]]==0){
                mp.erase(s[right]);
            }

            while(right-left+1 > mp.size()){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
            if(right-left+1 == mp.size()){
                ans = max(ans,(right-left+1));
            }
        }



        return ans;
    }
};
