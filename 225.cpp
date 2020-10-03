/*
 * Approach: queue
 * Time complexity: -   || 10.03% (4 ms)
 * Space complexity: -  || 9.66% (7.2 MB)
 */
class MyStack {
private:
    queue<int> st;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // O(n)
        int n = st.size();
        st.push(x);
        while (n--) {
            st.push(st.front());
            st.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = st.front();
        st.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return st.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */