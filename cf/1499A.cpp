#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    string res[] = {"NO", "YES"};
    while (t--) {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        int wmin = min(k1, k2), wmax = max(k1, k2);
        int bmin = n - wmax, bmax = n - wmin;
        cout << res[(wmin + (wmax - wmin) / 2 >= w) && (bmin + (bmax - bmin) / 2) >= b] << endl;
    }
    return 0;
}