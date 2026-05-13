class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for(char c : t) {
            mp[c]++;
        }

       
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;


        int left = 0;
        for(int right = 0; right < s.size(); right++) {

            // If character needed
            if(mp[s[right]] > 0) {
                count--;
            }

            mp[s[right]]--;

            // Valid window
            while(count == 0) {

               
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                mp[s[left]]++;

                
                if(mp[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
