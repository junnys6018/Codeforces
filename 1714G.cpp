#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// g++ 1714G.cpp -o 1714G.out && ./1714G.out < 1714G.in

using i64 = int64_t;

void dp(vector<i64> &p, vector<i64> &a, vector<i64> &b, vector<i64> &r,
        vector<i64> &A, vector<i64> &B, vector<i64> &l, i64 j) {
  // if (r[j] != -1) {
  //   return;
  // }

  i64 ancestor = p[j];
  if (ancestor == 1) {
    A[j] = a[j];

    // B[j] = b[j];
    B.push_back(b[j]);

    r[j] = (b[j] <= a[j] ? 1 : 0);
    l[j] = 1;
  } else {
    ancestor -= 2;
    if (r[ancestor] == -1) {
      dp(p, a, b, r, A, B, l, ancestor);
    }
    A[j] = A[ancestor] + a[j];

    // B[j] = B[ancestor] + b[j];
    B.push_back(B.back() + b[j]);

    l[j] = l[ancestor] + 1;

    i64 i = B.size() / 2, l = 0, rr = B.size();
    while (!(A[j] >= B[i] && (i < B.size() - 1 ? A[j] < B[i + 1] : true))) {
      if (A[j] >= B[i]) {
        l = i + 1;
      } else {
        rr = i;
      }
      i = (l + rr) / 2;
    }
    r[j] = i + 1;

    // ancestor = j;
    // while (A[j] < B[ancestor] && ancestor >= 0) {
    //   ancestor = p[ancestor] - 2;
    // }
    // if (ancestor == -1) {
    // r[j] = 0;
    // } else {
    //   r[j] = l[ancestor];
    // }
  }
}

void solve() {
  i64 n;
  cin >> n;
  vector<i64> p(n - 1), a(n - 1), b(n - 1), r(n - 1, -1), A(n - 1, 0),
      l(n - 1, 0), B(n - 1, 0);
  for (i64 i = 0; i < n - 1; i++) {
    cin >> p[i] >> a[i] >> b[i];
  }

  for (i64 j = 0; j < n - 1; j++) {
    dp(p, a, b, r, A, B, l, j);
  }

  for (auto ri : r) {
    cout << ri << ' ';
  }
  cout << endl;
}

int main() {
  i64 t;
  cin >> t;
  while (t--) {
    solve();
  }
}