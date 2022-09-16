#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// g++ 1714D.cpp -o 1714D.out && ./1714D.out < 1714D.in

using i64 = int64_t;

bool is_substring(const string& body, const string& needle, i64 p) {
  if (p < 0 || body.length() < needle.length() + p) {
    return false;
  }
  for (i64 i = p; i < needle.length() + p; i++) {
    if (body[i] != needle[i - p])
      return false;
  }
  return true;
}

i64 fit(const string &body, const string &needle, i64 p) {
  for (i64 i = 0; i < needle.length(); i++) {
    if (is_substring(body, needle, p-i)) {
      return needle.length() - i;
    }
  }
  return 0;
}

void solve() {
  string t;
  i64 n;
  cin >> t >> n;
  vector<pair<i64, string>> s(n);
  for (i64 i = 0; i < n; i++) {
    s[i].first = i;
    cin >> s[i].second;
  }

  sort(s.begin(), s.end(), [](const auto &s1, const auto &s2) {
    return s1.second.length() > s2.second.length();
  });

  vector<pair<i64, i64>> ans;
  i64 p = 0;
  while (p < t.length()) {
    i64 w = 0;
    pair<i64, i64> a;
    for (i64 i = 0; i < n; i++) {
      i64 k = fit(t, s[i].second, p);
      if (k > w) {
        w = k;
        a.first = s[i].first + 1;
        a.second = p + k - s[i].second.length() + 1;
      }
    }
    if (w == 0) {
      cout << "-1" << endl;
      return;
    }
    ans.push_back(a);
    p += w;
  }

  cout << ans.size() << endl;
  for (auto &a : ans) {
    cout << a.first << ' ' << a.second << endl;
  }
}

int main() {
  i64 t;
  cin >> t;
  while (t--) {
    solve();
  }
}