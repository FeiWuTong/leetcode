#include <iostream>
#include <vector>
using namespace std;
#define MDX 20000000

int t, c, d, x;
int cnt[MDX + 5];

// MDX = max{d+x}, init factor pair count for each number, using dp
void init() {
    // not prime
    bool np[MDX + 5];
    vector<int> prime;
    cnt[1] = 1;
    for (int i = 2; i <= MDX; i++) {
        if (!np[i]) {
            cnt[i] = 2;
            prime.push_back(i);
        }
        for (int p : prime) {
            if (p * i > MDX) break;
            np[p * i] = true;
            cnt[p * i] = cnt[i];
            // break in advance, since i / p_{cur} = z, it will be finally traversed to z * p_{next} against p_{cur}
            // which can avoid to calculate a cnt multiple times
            if (i % p == 0) break;
            cnt[p * i] <<= 1;
        }
    }
}

// return pair amount of a 'g'
int calc(int s, int c) {
    if (s % c) return 0;
    return cnt[s / c];
}

// c * a * b = d + x / g
// g is gcd(pair), a and b are coprime numbers, pair is (a * g, b * g)
void solve() {
    cin >> c >> d >> x;
    int ans = 0, i;
    for (i = 1; i * i < x; i++) {
        if (x % i == 0) {
            ans += calc(d + i, c);
            ans += calc(d + x / i, c);
        }
    }
    if (i * i == x) ans += calc(d + i, c);
    cout << ans << endl;
}

int main() {
    init();
    cin >> t;
    while (t--) solve();
    return 0;
}