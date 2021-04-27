#include <iostream>
#include <vector>
using namespace std;

// greedy
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // flag: last number deleted or not (1 is deleted)
        // pos: last 2nd number deleted or not (1 is deleted)
        int flag = 0, pos = 0;
        int res = 1;
        for (int i = 2; i < s.size(); i++) {
            if (flag) {
                if (s[i] < s[i - 2]) {
                    res = 0;
                    break;
                } else {
                    flag = 0, pos = 1;
                }
            } else {
                if (s[i] < s[i-1]) {
                    if (s[i] < s[i - 2 - pos])
                        flag = 1, pos = 0;
                    else
                        flag = 0, pos = 1;
                } else {
                    flag = 0, pos = 0;
                }
            }
        }
        cout << (res ? "YES" : "NO") << endl;
    }
    return 0;
}