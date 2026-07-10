class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0;i<words.size();i++){
            int j =0;
            int k = words[i].size()-1;
            bool found = false;
            while(j<k){
                if(words[i][j]!=words[i][k]){
                    found = true;
                    break;
                } 
                j++;
                k--;
            }
            if(found){
                continue;
            }else{
                return words[i];
            }   
        }
    return "";
    }
};