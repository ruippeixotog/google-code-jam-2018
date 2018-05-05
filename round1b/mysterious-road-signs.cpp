#include <algorithm>
#include <cstdio>

#define MAXN 100000
#define INF 0x3f3f3f3f

using namespace std;

int s, da[MAXN], db[MAXN];

pair<int, int> search(int st, int a, int b, int inc) {
  int idx1 = st + inc;
  for(; idx1 >= 0 && idx1 < s; idx1 += inc) {
    if(da[idx1] == a || db[idx1] == b) continue;
    if(a == INF) a = da[idx1];
    else if(b == INF) b = db[idx1];
    else break;
  }
  int idx2 = st - inc;
  for(; idx2 >= 0 && idx2 < s; idx2 -= inc) {
    if(da[idx2] == a || db[idx2] == b) continue;
    if(a == INF) a = da[idx2];
    else if(b == INF) b = db[idx2];
    else break;
  }
  return { abs(idx1 - st) + abs(st - idx2) - 1, max(idx1, idx2) };
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d\n", &s);
    for(int i = 0; i < s; i++) {
      int di, ai, bi; scanf("%d %d %d\n", &di, &ai, &bi);
      da[i] = di + ai; db[i] = di - bi;
    }

    int i = 0, best = 0, bestCnt = 0;
    while(i < s) {
      auto resFwd = max(search(i, da[i], INF, 1), search(i, INF, db[i], 1));
      if(resFwd.first > best) { best = resFwd.first; bestCnt = 1; }
      else if(resFwd.first == best) bestCnt++;

      auto resBck = max(search(i, da[i], INF, -1), search(i, INF, db[i], -1));
      if(resBck.first > best) { best = resBck.first; bestCnt = 1; }
      else if(resBck.first == best && resBck.second != resFwd.second) bestCnt++;

      i = resFwd.second;
    }
    printf("Case #%d: %d %d\n", tc, best, bestCnt);
  }
  return 0;
}
