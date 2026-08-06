class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
        }else{
            int a =st.top().second;
            if(a<value){
                st.push({value,a});
            }else{
                st.push({value,value});
            }
        }
        return ;
    }
    
    void pop() {
        st.pop();
        return ;
    }
    
    int top() {
        int a = st.top().first;
        return a;
    }
    
    int getMin() {
        int a = st.top().second;
        return a;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */