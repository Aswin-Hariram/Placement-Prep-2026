class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s2.size();
        int k = s1.size();

        unordered_map<char,int> mp;
        for(char c : s1){

            mp[c]++;
        }

        int left = 0;

        for(int right = 0; right<n;right++){
            mp[s2[right]]--;
            if(mp[s2[right]] == 0 ){
                mp.erase(s2[right]);
            }

            if(right-left+1 == k){

                if(mp.size()==0){
                    return true;
                }

                mp[s2[left]]++;

                if(mp[s2[left]]==0){
                    mp.erase(s2[left]);
                }
                left++;

            }
        }
        return false;
    }
};
