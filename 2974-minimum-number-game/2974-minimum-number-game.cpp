class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0; 
        int j = 1;
        while(j<nums.size()){
            int temp = nums[i];
            nums[i]= nums[j];
            nums[j] = temp;
            i+=2;
            j+=2;
        }
        return nums;
    }
};