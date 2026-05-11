class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = (k*2)+1;

        int left = 0;
        double sum = 0;
        vector<int> res(nums.size(),-1);
        for(int right = 0; right < nums.size();right++ ){

            sum += nums[right];

            if(right - left + 1 == size){
                double avg = sum/size;
                res[left + k]=avg;

                sum -= nums[left];
                left++;
            }
        }

        return res;
    }
};
