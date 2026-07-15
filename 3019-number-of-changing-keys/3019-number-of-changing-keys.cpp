class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        char prev = s[0];
        for(char &c: s){
            c = tolower(static_cast<unsigned char>(c));
        }
        for (int i =0; i<s.size()-1;i++){
            if(s[i]!=s[i+1]) count++;
        }
        return count;
    }
};