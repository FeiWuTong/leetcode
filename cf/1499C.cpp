#include <iostream>
using namespace std;
#define NMAX 100001
#define LL long long

int t, n;
int rec[NMAX];

// greedy: odd / even <==> one direction, find the least cost in each direction
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rec[i];
    // min horizon / vertical
    LL mh = rec[0], mv = rec[1];
    // step horizon / vertical
    LL sh = rec[0], sv = rec[1];
    // pass horizon / vertical
    LL ph = 1, pv = 1;
    LL res = mh * n + mv * n;
    for (int i = 2; i < n; i++) {
        if (i & 1) {
            mv = min(mv, (LL)rec[i]);
            sv += rec[i];
            pv++;
            
        } else {
            mh = min(mh, (LL)rec[i]);
            sh += rec[i];
            ph++;
        }
        res = min(res, mh * (n - ph) + sh + mv * (n - pv) + sv);
    }
    cout << res << endl;
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}