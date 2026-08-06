class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token: tokens){
            if(token != "+" && token != "-" && token != "*" && token != "/" ){
                st.push(stoi(token));
            }
            else{
                int secOp = int(st.top());
                st.pop();
                int firstOp = int(st.top());
                st.pop();
                int res;
                if(token == "+"){
                    res = firstOp+secOp;
                }else if(token == "-"){
                    res = firstOp-secOp;
                }else if(token == "*"){
                    res = firstOp*secOp;
                }else{
                    res = firstOp/secOp;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};