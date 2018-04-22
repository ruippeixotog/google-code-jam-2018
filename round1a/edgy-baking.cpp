#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MAXN 100
#define MAXWH 250

using namespace std;

typedef long double ld;

int w[MAXWH], h[MAXWH];

bool dp[MAXN + 1][MAXN * 2 * MAXWH + 1];
ld dpV[MAXN + 1][MAXN * 2 * MAXWH + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, p; scanf("%d %d\n", &n, &p);

    int pLeft = p;
    for(int i = 0; i < n; i++) {
      scanf("%d %d\n", &w[i], &h[i]);
      pLeft -= 2 * (w[i] + h[i]);
    }

    memset(dp, false, sizeof(dp));
    memset(dpV, 0, sizeof(dpV));
    dp[0][0] = true;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= min(pLeft, n * 2 * MAXWH); j++) {
        if(!dp[i][j]) continue;
        dp[i + 1][j] = true;
        dpV[i + 1][j] = dpV[i][j];

        int minCut = 2 * min(w[i], h[i]);
        ld maxCut = 2 * sqrt(w[i] * w[i] + h[i] * h[i]);
        dp[i + 1][j + minCut] = true;
        dpV[i + 1][j + minCut] = max(
          dpV[i + 1][j + minCut], dpV[i][j] + (maxCut - minCut));
      }
    }
    ld best = 0;
    for(int i = 0; i <= min(pLeft, n * 2 * MAXWH); i++) {
      if(!dp[n][i]) continue;
      best = min((ld) pLeft, max(best, i + dpV[n][i]));
    }
    printf("Case #%d: %.9f\n", tc, (double) (p - pLeft + best));
  }
  return 0;
}
