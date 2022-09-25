#include <bits/stdc++.h>
using namespace std;

using li = int64_t;

// g++ 1553D.cpp -o 1553D.out && ./1553D.out < 1553D.in

void solve() {
  string s, t;
  cin >> s >> t;
  li p = s.length() - 1;
  li q = t.length() - 1;
  while (p >= 0 && q >= 0) {
    if (s[p] == t[q]) {
      p -= 1;
      q -= 1;
    } else {
      p -= 2;
    }
  }
  if (q < 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  li t;
  cin >> t;
  for (li i = 0; i < t; i++) {
    solve();
  }
}
