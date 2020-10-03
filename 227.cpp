/*
 * Approach: stack
 * Time complexity: O(n)   || 44.47% (32 ms)
 * Space complexity: O(n)  || 39.95% (8.7 MB)
 */
class Solution {
private:
    int tran2digit(string& s, int& i) {
        int n = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            n *= 10;
            n += s[i] - '0';
            i++;
        }
        return n;
    }

    int calc(char c, int a, int b) {
        switch (c) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default : return a / b;
        }
    }
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        bool f = false;
        for (int i = 0; i < s.size();) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (f) {
                    char _op = op.top();
                    op.pop();
                    int cur = num.top();
                    num.pop();
                    cur = calc(_op, cur, tran2digit(s, i));
                    num.push(cur);
                    f = false;
                } else {
                    num.push(tran2digit(s, i));
                }
            } else if (s[i] == ' ') {
                i++;
            } else {
                if (s[i] == '*' || s[i] == '/') f = true;
                op.push(s[i]);
                i++;
            }
        }
        if (num.empty()) return 0;
        int ret = 0;
        while (!op.empty()) {
            ret = calc(op.top(), ret, num.top());
            op.pop();
            num.pop();
        }
        ret += num.top();
        return ret;
    }
};
/*
 * Approach: concise stream
 * Time complexity: O(n)   || 82.69% (20 ms)
 * Space complexity: O(1)  || 38.75% (8.7 MB)
 */
class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long ret = 0, temp = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                ret += temp;
                in >> temp;
                temp *= 44 - op;
            } else {
                in >> n;
                if (op == '*') temp *= n;
                else temp /= n;
            }
        }
        return ret;
    }
};