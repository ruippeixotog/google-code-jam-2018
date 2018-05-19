#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXRB 500
#define MAXSZ 45 // solve MAXRB * 2 = MAXSZ * (MAXSZ + 1) / 2

using namespace std;

int dp[MAXRB + 1][MAXRB + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int r, b; scanf("%d %d\n", &r, &b);

    memset(dp, -1, sizeof(dp));
    dp[r][b] = 0;
    for(int sz = 1; sz <= MAXSZ; sz++) {
      for(int nr = 0; nr <= sz; nr++) {
        int nb = sz - nr;
        for(int i = nr; i <= r; i++) {
          for(int j = nb; j <= b; j++) {
            if(dp[i][j] == -1) continue;
            dp[i - nr][j - nb] = max(dp[i - nr][j - nb], dp[i][j] + 1);
          }
        }
      }
    }
    int best = 0;
    for(int i = 0; i <= r; i++) {
      for(int j = 0; j <= b; j++) {
        best = max(best, dp[i][j]);
      }
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
