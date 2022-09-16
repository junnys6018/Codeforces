#include <algorithm>
#include <iostream>

using namespace std;
using i64 = int64_t;

// g++ 1675E.cpp -o 1675E.out && ./1675E.out < 1675E.in

void solve() {
  i64 n, k;
  string s;
  cin >> n >> k >> s;

  i64 i = 0;
  char c = s[i];
  bool op[26] = {0};
  k = min((i64)25, k);
  while (k > 0) {
    if (c == 'a' || op[c - 'a']) {
      i++;
      if (i >= s.length()) {
        break;
      }
      c = s[i];
    } else {
      op[c - 'a'] = true;
      k--;
      c--;
    }
  }

  for (i64 i = 25; i >= 0; i--) {
    if (op[i]) {
      char c = 'a' + i;
      replace(s.begin(), s.end(), c, (char)(c - 1));
    }
  }
  cout << s << endl;
}

int main() {
  i64 t;
  cin >> t;
  while (t--) {
    solve();
  }
}