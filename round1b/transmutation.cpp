#include <cstdio>
#include <cstring>

#define MAXN 100

typedef long long ll;

int m, r1[MAXN], r2[MAXN], g[MAXN];

ll r[MAXN][MAXN], reqs[MAXN];

bool make(ll qty) {
  memset(r, 0, sizeof(r));
  for(int i = 0; i < m; i++) {
    r[i][r1[i]]++; r[i][r2[i]]++;
    reqs[i] = -g[i];
  }
  reqs[0] += qty;

  bool done = false;
  while(!done) {
    done = true;
    for(int i = 0; i < m; i++) {
      if(reqs[i] <= 0) continue;
      if(r[i][i]) return false;
      done = false;

      for(int j = 0; j < m; j++) {
        reqs[j] += reqs[i] * r[i][j];
      }
      reqs[i] = 0;

      for(int j = 0; j < m; j++) {
        if(!r[j][i]) continue;
        for(int k = 0; k < m; k++) {
          r[j][k] += r[j][i] * r[i][k];
        }
        r[j][i] = 0;
      }
    }

    ll reqsSum = 0;
    for(int i = 0; i < m; i++) {
      reqsSum += reqs[i];
    }
    if(reqsSum > 0) return false;
  }
  return true;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d\n", &m);
    memset(r, 0, sizeof(r));
    for(int i = 0; i < m; i++) {
      scanf("%d %d\n", &r1[i], &r2[i]);
      r1[i]--; r2[i]--;
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", &g[i]);
    }

    ll minL = 0, maxL = 7000000000LL;
    while(minL < maxL) {
      ll midL = (minL + maxL + 1) / 2;
      if(make(midL)) minL = midL;
      else maxL = midL - 1;
    }
    printf("Case #%d: %lld\n", tc, minL);
  }
  return 0;
}
