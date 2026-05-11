vector<int> firstNegative(vector<int>& arr, int k) {

    queue<int> q;
    vector<int> ans;

    int left = 0;

    for(int right = 0; right < arr.size(); right++) {

        if(arr[right] < 0)
            q.push(right);

        if(right - left + 1 == k) {

            if(q.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[q.front()]);

            // remove out-of-window negative
            if(!q.empty() && q.front() == left)
                q.pop();

            left++;
        }
    }

    return ans;
}
