class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int> st;
        for(int num: nums2){
            while(!st.empty()&&st.top()<num){
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int>ans;
        for(int num: nums1){
            if(mpp[num]==0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mpp[num]);
            }
        }
        return ans;
    }
};