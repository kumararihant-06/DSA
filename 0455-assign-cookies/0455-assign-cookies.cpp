class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0;
        int j = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int contentChildren = 0;
        while(i<g.size() && j<s.size()){
            int demand = g[i];
            int size = s[j];
            if(demand<=size){
               contentChildren++;
                i++;
                j++; 
            } else if(demand>size){
                j++;
            }
        }
    return contentChildren;
    }
};