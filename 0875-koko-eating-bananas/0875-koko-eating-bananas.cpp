class Solution {
public:
    // int helper(vector<int>& piles, int mid){
        
    //     return requiredHours;
    // }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int speed = high;
        while(low<=high){
            int mid = (low+high)/2;
            long long requiredHours = 0;
            for(auto pile: piles){
            requiredHours+= (pile+mid-1)/mid;
            }
            if(requiredHours<=h){
                speed = min(mid,speed);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
           
        }
        return speed;
    }
};