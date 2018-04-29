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

#define MAXN 100
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int d[MAXN], a[MAXN], b[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int s; scanf("%d\n", &s);
    for(int i = 0; i < s; i++)
      scanf("%d %d %d\n", &d[i], &a[i], &b[i]);

    int best = 0, bestCnt = 0;
    for(int i = 0; i < s; i++) {
      int idx = i + 1, da = d[i] + a[i], db = INF;
      for(; idx < s; idx++) {
        if(d[idx] + a[idx] == da || d[idx] - b[idx] == db) continue;
        if(db == INF) db = d[idx] - b[idx];
        else break;
      }
      int sz = idx - i;
      idx = i + 1, da = INF, db = d[i] - b[i];
      for(; idx < s; idx++) {
        if(d[idx] + a[idx] == da || d[idx] - b[idx] == db) continue;
        if(da == INF) da = d[idx] + a[idx];
        else break;
      }
      if(idx - i > sz) { sz = idx - i; }

      if(sz > best) { best = sz; bestCnt = 1; }
      else if(sz == best) { bestCnt++; }
    }
    printf("Case #%d: %d %d\n", tc, best, bestCnt);
  }
  return 0;
}
