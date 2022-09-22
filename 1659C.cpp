#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

// g++ 1659C.cpp -o 1659C.out && ./1659C.out < 1659C.in

void solve() {
  i64 n, a, b;
  cin >> n >> a >> b;
  vector<i64> x(n);
  for (i64 i = 0; i < n; i++) {
    cin >> x[i];
  }

  i64 c = 0, j = 0;
  for (i64 i = 0; i < n; i++) {
    c += b * (x[i] - j);
    if ((n - i - 1) * b * (x[i] - j) >= a * (x[i] - j)) {
      c += a * (x[i] - j);
      j = x[i];
    }
  }

  cout << c << endl;
}

int main() {
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++) {
    solve();
  }
}
