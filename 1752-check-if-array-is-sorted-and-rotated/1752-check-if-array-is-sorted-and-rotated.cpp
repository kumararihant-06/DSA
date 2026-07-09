class Solution {
public:
    
    bool check(vector<int>& nums) {
        int flag = 0;
        
        for(int i = 0; i<nums.size();i++){
           if(nums[i]>nums[(i+1)%nums.size()]) flag+=1;
        }
        if(flag <= 1) return true;

        return false;
    }
};