class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force TC: O(n^2) SC: O(n)
        // vector<int> ansArr;
        // for(int i =0; i<nums.size()-1;i++){
        //     for(int j = i+1; j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             ansArr.push_back(i);
        //             ansArr.push_back(j);
        //         }
        //     }
        // }
        // return ansArr;

        //Optimal Approach TC: O(n) SC: O(n)
        vector<int> ansArr;
        unordered_map<int,int> mpp;
        for(int i = 0; i<nums.size(); i++){
            int rem = target - nums[i];
            if(mpp.contains(rem)){
                ansArr.push_back(mpp[rem]);
                ansArr.push_back(i);
            }else{
                mpp[nums[i]] = i;
            }
        }
        return ansArr;
    }
};