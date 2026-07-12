class MinStack {
public:
    typedef long long ll;
    stack<ll> st;
    ll mini;
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
            return;
        }
        if(value < mini){
            ll newValue = 2 * (ll)value - mini;
            mini = value;
            st.push(newValue);
            return;
        }
        st.push(value);
    }
    void pop() {
        if(st.top() < mini){
            mini = 2 * (ll)mini - st.top();
            st.pop();
            return;
        }
        st.pop();
    }
    int top() {
        return max(st.top(),mini);
    }
    
    int getMin() {
        return mini;
    }
};