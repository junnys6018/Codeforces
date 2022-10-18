#include <bits/stdc++.h>
using namespace std;

using li = int64_t;

// g++ 1391C.cpp -o 1391C.out && ./1391C.out < 1391C.in

li MOD = 1000000007;

int main() {
  li n;
  cin >> n;

  li fact = 1;
  for (li i = 2; i <= n; i++) {
    fact = (fact * i) % MOD;
  }

  li pow = 1;
  for (li i = 0; i < n - 1; i++) {
    pow = (2 * pow) % MOD;
  }

  if (pow > fact) {
    fact += MOD;
  }

  cout << (fact - pow) % MOD << endl;
}
