#include <bits/stdc++.h>
using namespace std;

using li = int64_t;

// g++ 1547E.cpp -o 1547E.out && ./1547E.out < 1547E.in

void solve() {
  li n, k;
  cin >> n >> k;
  vector<li> a(k), t(k), c(n, numeric_limits<int>::max()), L(n), R(n);

  for (li i = 0; i < k; i++) {
    cin >> a[i];
  }

  for (li i = 0; i < k; i++)
    cin >> t[i];

  for (li i = 0; i < k; i++) {
    c[a[i] - 1] = t[i];
  }

  li p = numeric_limits<li>::max() - 1;
  for (li i = n - 1; i >= 0; i--)
  {
    p = min(p + 1, c[i]);
    L[i] = p;
  }

  p = numeric_limits<li>::max() - 1;
  for (li i = 0; i < n; i++) {
    p = min(p + 1, c[i]);
    R[i] = p;
  }

  for (li i = 0; i < n; i++) {
    cout << min(L[i], R[i]) << ' ';
  }
  cout << endl;
}

int main() {
  li t;
  cin >> t;
  for (li i = 0; i < t; i++) {
    solve();
  }
}
