class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> st;
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                st.push_back(c + 32);
            }
            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                st.push_back(c);
            }
        }

        int j = 0;
        int k = st.size()-1;
        while(j<k){
            if(st[j]!=st[k]) return false;
            j++;
            k--;
        }
        return true;
    }
};