class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int n = s.length();
        string res;
        
        for(int i = 0; i < n; i++){
            if(count != 0){
                if(s[i] == '('){
                    res.push_back(s[i]);
                    count++;
                }
                else {
                    
                    if(count > 1) {
                        res.push_back(s[i]);
                    }
                    count--;
                }
            }
            else{
                
                count++;
            }
        }
        return res;
    }
};
