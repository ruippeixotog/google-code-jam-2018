#include <cstdio>
#include <cstring>

#define MAXN 100

int n, a[MAXN][MAXN];

bool seen[MAXN];
int matchL[MAXN], matchR[MAXN];

bool bpmDfs(int k, int u) {
  for(int v = 0; v < n; v++) {
    if(a[u][v] == k) {
      if(seen[v]) continue;
      seen[v] = true;

      if(matchR[v] < 0 || bpmDfs(k, matchR[v])) {
        matchL[u] = v; matchR[v] = u;
        return true;
      }
    }
  }
  return false;
}

int bpm(int k) {
  memset(matchL, -1, sizeof(matchL));
  memset(matchR, -1, sizeof(matchR));
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    memset(seen, false, sizeof(seen));
    if(bpmDfs(k, i)) cnt++;
  }
  return cnt;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int aij; scanf("%d", &aij);
        a[i][j] = aij < 0 ? -aij - 1 : n + aij - 1;
      }
    }
    int correct = 0;
    for(int k = 0; k < 2 * n; k++) {
      correct += bpm(k);
    }
    printf("Case #%d: %d\n", tc, n * n - correct);
  }
  return 0;
}
