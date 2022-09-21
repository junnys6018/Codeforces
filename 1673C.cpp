#include <array>
#include <iostream>
#include <vector>
using namespace std;

using i64 = int64_t;

// g++ 1673C.cpp -o 1673C.out && ./1673C.out < 1673C.in

constexpr i64 PALS = 498;
constexpr i64 MOD = 1000000007;

array<i64, PALS> pal;

i64 partitions(i64 N) {
  vector<array<i64, 500>> dp(N);

  for (i64 n = 0; n < N; n++) {
    dp[n][0] = 1;
  }
  for (i64 k = 0; k < 500; k++) {
    dp[0][k] = 1;
  }

  for (i64 n = 1; n < N; n++) {
    for (i64 k = 1; k < 500; k++) {
      dp[n][k] = dp[n][k - 1];
      if (n - k == 0) {
        dp[n][k] += 1;
      } else if (n - k > 0) {
        dp[n][k] += dp[n - k - 1][k];
      }
    }
  }
  return dp[N - 1][499];
}

int main() {
  i64 t;
  cin >> t;

  i64 n = 0;

  // 1 digit
  for (i64 i = 1; i <= 9; i++) {
    pal[n++] = i;
  }

  // 2 digit
  for (i64 i = 1; i <= 9; i++) {
    pal[n++] = i * 10 + i;
  }

  // 3 digit
  for (i64 i = 10; i <= 99; i++) {
    pal[n++] = i * 10 + (i / 10);
  }

  // 4 digit
  for (i64 i = 10; i <= 99; i++) {
    pal[n++] = i * 100 + (i % 10) * 10 + (i / 10);
  }

  // 5 digit <= 40_000
  for (i64 i = 100; i <= 399; i++) {
    pal[n++] = i * 100 + (((i / 10) % 10) * 10) + i / 100;
  }

  constexpr i64 N = 40000;
  vector<array<i64, PALS>> dp(N);

  for (i64 n = 0; n < N; n++) {
    dp[n][0] = 1;
  }
  for (i64 k = 0; k < PALS; k++) {
    dp[0][k] = 1;
  }

  for (i64 n = 1; n < N; n++) {
    for (i64 k = 1; k < PALS; k++) {
      dp[n][k] = dp[n][k - 1];
      if (n + 1 - pal[k] == 0) {
        dp[n][k] += 1;
      } else if (n + 1 - pal[k] > 0) {
        dp[n][k] += dp[n - pal[k]][k];
      }
      dp[n][k] = dp[n][k] % MOD;
    }
  }

  i64 nn;
  for (i64 i = 0; i < t; i++)
  {
    cin >> nn;
    cout << dp[nn - 1][PALS - 1] << endl;
  }
}
