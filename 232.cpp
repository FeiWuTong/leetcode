/*
 * Approach: stack + recursive
 * Time complexity: O(n) push   || 100.00% (0 ms)
 * Space complexity: O(n)  || 74.85% (6.9 MB)
 */
class MyQueue {
private:
    stack<int> q;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (q.empty()) q.push(x);
        else {
            int t = pop();
            push(x);
            q.push(t);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = q.top();
        q.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return q.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */