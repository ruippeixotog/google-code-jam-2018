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

#define MAXN 4
#define MAXA 8
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int n, a[MAXN][MAXN];

bool usedRow[MAXN][MAXA], usedCol[MAXN][MAXA];
int best;

void solve(int ik, int jk, int curr) {
  if(curr >= best) return;
  if(jk == n) { ik++; jk = 0; }
  if(ik == n) {
    memset(usedRow, false, sizeof(usedRow));
    memset(usedCol, false, sizeof(usedCol));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(a[i][j] == -1) continue;
        if(usedRow[i][a[i][j]] || usedCol[j][a[i][j]]) return;
        usedRow[i][a[i][j]] = usedCol[j][a[i][j]] = true;
      }
    }
    best = curr;
  }

  solve(ik, jk + 1, curr);

  int oldA = a[ik][jk];
  a[ik][jk] = -1;
  solve(ik, jk + 1, curr + 1);
  a[ik][jk] = oldA;
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
    best = INF;
    solve(0, 0, 0);
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
