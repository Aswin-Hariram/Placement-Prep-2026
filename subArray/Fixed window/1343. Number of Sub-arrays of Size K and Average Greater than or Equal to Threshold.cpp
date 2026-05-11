class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        


        int left = 0;
        int ans=0;
        int sum = 0;

        for(int right = 0; right< arr.size(); right++){
            sum += arr[right];

            if(right-left+1 == k ){

                int avg = sum/k;
                if(avg>=threshold){
                    ans++;
                }

                sum -= arr[left];
                left++;
            }

            
        }
        return ans;
    }
};
