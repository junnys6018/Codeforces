#include <bits/stdc++.h>
using namespace std;

using li = int64_t;

// g++ 1722G.cpp -o 1722G.out && ./1722G.out < 1722G.in

void solve() {
  li n;
  cin >> n;

  li d = ((n % 4) == 2) ? 2 : 0;
  const li MAX = 0xFFFFFFF;

  for (li i = 0; i < n / 2 - d; i++) {
    cout << (i + 4) << ' ' << MAX - (i + 4) << ' ';
  }

  if ((n % 4) == 1) {
    cout << 0;
  } else if ((n % 4) == 2) {
    cout << 1 << ' ' << 3 << ' ' << MAX << ' ' << 2;
  } else if ((n % 4) == 3) {
    cout << MAX;
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
