class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        for(string inp : operations){

            if(inp == "C"){
                st.pop();
            }

            else if(inp == "D"){
                st.push(st.top() * 2);
            }

            else if(inp == "+"){

                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first); 

                st.push(first + second);
            }

            else{
                st.push(stoi(inp));
            }
        }

        int sum = 0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
