#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXRB 50
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int dp[MAXRB + 1][MAXRB + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int r, b; scanf("%d %d\n", &r, &b);

    memset(dp, -1, sizeof(dp));
    dp[r][b] = 0;
    for(int sz = 1; sz <= r + b; sz++) {
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
