class Solution {
public:

    vector<int> prevSmaller(vector<int>& heights) {

        int n = heights.size();

        vector<int> ans(n);

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmaller(vector<int>& heights) {

        int n = heights.size();

        vector<int> ans(n);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            int width = next[i] - prev[i] - 1;

            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};
