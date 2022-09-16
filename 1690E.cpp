#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// g++ 1690E.cpp -o 1690E.out && ./1690E.out < 1690E.in

using i64 = int64_t;

i64 solve() {
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  vector<vector<i64 *>> o(k);

  for (i64 i = 0; i < n; i++) {
    cin >> a[i];
    o[a[i] % k].push_back(&a[i]);
  }

  i64 c = 0;
  // for (i64 i = 0; i < n; i++) {
  //   if (a[i] == -1) {
  //     continue;
  //   }

  //   i64 ai = a[i];
  //   a[i] = -1;

  //   i64 m = ai % k;
  //   bool done = false;
  //   for (int j = 0; j < k && !done; j++) {
  //     auto &pool = o[(k - m + j) % k];
  //     for (i64 *p : pool) {
  //       if (*p == -1) {
  //         continue;
  //       } else {
  //         c += (ai + *p) / k;
  //         *p = -1;
  //         done = true;
  //         break;
  //       }
  //     }
  //   }
  // }
  for (int m = 0; m < k; m++) {
    auto &b1 = o[m];
    while (b1.size() > 0) {
      i64* p1 = b1.back();
      b1.pop_back();
      for (int j = 0; j < k; j++)
      {
        auto &b2 = o[(k - m + j) % k];
        if (b2.size() == 0) {
          continue;
        } else {
          i64 *p2 = b2.back();
          b2.pop_back();
          c += (*p1 + *p2) / k;
          break;
        }
      }
    }
  }

  return c;
}

int main() {
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++) {
    cout << solve() << endl;
  }
}