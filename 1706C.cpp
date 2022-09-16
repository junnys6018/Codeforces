#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// g++ 1706C.cpp -o 1706C.out && ./1706C.out < 1706.in

int64_t solve() {
    int64_t n;
    cin >> n;
    vector<int64_t> h(n);
    vector<int64_t> c(n);
    for (int64_t i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int64_t i = 1; i < n-1; i++) {
        c[i] = max(h[i - 1], h[i + 1]);
        if (h[i] > c[i]) {
            c[i] = 0;
        } else {
            c[i] = c[i] - h[i] + 1;
        }
    }

    if (n % 2 == 1) {
        int64_t c1 = 0;
        for (int64_t i = 1; i < n - 1; i += 2) {
            c1 += c[i];
        }
        return c1;
    }

    vector<int64_t> ccl(n, 0);
    vector<int64_t> ccr(n, 0);

    for (int64_t i = 1; i < n - 1; i += 2) {
        ccl[i] = c[i] + (i == 1 ? 0 : ccl[i-2]);
    }

    for (int64_t i = n - 2; i > 0; i -= 2) {
        ccr[i] = c[i] + (i == n-2 ? 0 : ccr[i + 2]);
    }

    int64_t c1 = numeric_limits<int64_t>::max();
    for (int64_t i = 1; i < n; i += 2) {
        c1 = min(c1, (i == 1 ? 0 : ccl[i-2]) + (i == n-1 ? 0 : ccr[i+1]));
    }

    return c1;
}

int main() {
    int64_t t;
    cin >> t;
    for (int64_t i = 0; i < t; i++) {
        cout << solve() << endl;
    }
}