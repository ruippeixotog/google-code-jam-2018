#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 100000

using namespace std;

typedef long long ll;

int w[MAXN];

ll dp[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &w[n - i - 1]);

    memset(dp, 0, sizeof(dp));
    dp[0] = 10000000000LL;

    int best = 0;
    for(int i = 0; i < n; i++) {
      for(int j = best; j >= max(0, best - n + i - 1); j--) {
        if(dp[j] >= w[i]) {
          dp[j + 1] = max(dp[j + 1], min(dp[j] - w[i], w[i] * 6LL));
          best = max(best, j + 1);
        }
      }
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
