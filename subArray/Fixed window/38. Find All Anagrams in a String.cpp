class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;

        int n = s.size();
        int k = p.size();

        unordered_map<char,int> mp;

        for(char c : p) {
            mp[c]++;
        }

        int left = 0;

        for(int right = 0; right < n; right++) {

            // Include current character
            mp[s[right]]--;

            if(mp[s[right]] == 0) {
                mp.erase(s[right]);
            }

            // Window size reached
            if(right - left + 1 == k) {

                // Valid anagram
                if(mp.empty()) {
                    res.push_back(left);
                }

                // Remove left character
                mp[s[left]]++;

                if(mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }

                left++;
            }
        }

        return res;
    }
};
