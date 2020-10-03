/*
 * Approach: Recursive (BNF)
 * Time complexity: O(n)   || 5.36% (776 ms)
 * Space complexity: O(n)  || 41.30% (8.8 MB)
 * Note: Normally there are 2 solutions to implement calculator, 1 is stack, another is BNF
 * Note: Stack is also O(n) / O(n) (refer to #227)
 */
class Solution {
private:
    bool check_parentheses(int p, int q, string& s) {
        if (s[p] != '(' || s[q] != ')') return false;
        int st = 1;
        while (++p < q) {
            if (s[p] == '(') st++;
            else if (s[p] == ')') st--;
            if (st == 0) return false;
        }
        return true;
    }

    bool is_op(int p, string& s) {
        if (s[p] == '+' || s[p] == '-') return true;
        return false;
    }

    int main_op(int p, int q, string& s) {
        while (q > p) {
            if (s[q] == ')') {
                int st = 1;
                while (--q > p && st != 0) {
                    if (s[q] == ')') st++;
                    else if (s[q] == '(') st--;
                }
            }
            if (is_op(q, s)) return q;
            q--;
        }
        return -1;
    }

    int tran2digit(int p, int q, string& s) {
        int num = 0;
        while (p <= q) {
            if (s[p] >= '0' && s[p] <= '9') {
                num *= 10;
                num += s[p] - '0';
            } else {
                if (num) return num;
            }
            p++;
        }
        return num;
    }

    int eval(int p, int q, string& s) {
        if (p > q) {
            // invalid expression
            return INT_MIN;
        } else if (check_parentheses(p, q, s)) {
            return eval(p + 1, q - 1, s);
        } else {
            int op = main_op(p, q, s);
            // only digit
            if (op == -1) {
                return tran2digit(p, q, s);
            } else {
                int val1 = eval(p, op - 1, s);
                int val2 = eval(op + 1, q, s);
                if (s[op] == '+') return val1 + val2;
                else return val1 - val2;
            }
        }
    }
public:
    int calculate(string s) {
        return eval(0, int(s.size() - 1), s);
    }
};