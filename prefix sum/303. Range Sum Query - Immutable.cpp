class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        prefix.push_back(0);

        for(int num : nums){
            prefix.push_back(prefix.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};
