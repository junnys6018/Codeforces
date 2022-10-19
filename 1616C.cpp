#include <bits/stdc++.h>
using namespace std;

using li = int64_t;

// g++ 1616C.cpp -o 1616C.out && ./1616C.out < 1616C.in

void solve() {
    li n;
    cin >> n;
    vector<li> a(n);
    for (li i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n < 3) {
        cout << 0 << endl;
        return;
    }

    li c = n;
    for (li i = 0; i < n-1; i++) {
        for (li j = i + 1; j < n; j++) {
            li cc = 0;
            for (li k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                double v = (double)(a[j]-a[i])/(j-i)*(k-i)+a[i];
                if (abs(v - a[k]) > 0.000001) {
                    cc++;
                }
            }
            c = min(c, cc);
        }
    }
    cout << c << endl;
}

int main() {
    li t;
    cin >> t;
    for (li i = 0; i < t; i++) {
        solve();
    }
}
