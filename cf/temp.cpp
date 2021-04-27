#include <iostream>
#include <vector>
using namespace std;

// greedy-simplify: delete 1 as many as possible, i.e., find first '11', and then check whether exists '00'
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        char last = '0';
        int flag = 0, res = 1;
        for (char n : s) {
            if (flag && n == '0' && last == '0') {
                res = 0;
                break;
            } else if (!flag && n == '1' && last == '1') {
                flag = 1;
            }
            last = n;
        }
        cout << (res ? "YES" : "NO") << endl;
    }
    return 0;
}