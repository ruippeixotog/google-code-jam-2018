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

int r1[MAXN], r2[MAXN], g[MAXN];

bool visited[MAXN];

ll make(int k, ll maxRes) {
  if(visited[k]) return 0;
  visited[k] = true;

//  cerr << "making " << k << " (max " << maxRes << ")" << endl;

  ll res = min(maxRes, (ll) g[k]);
  g[k] -= res;
  if(res == maxRes) { visited[k] = false; return res; }

  ll direct = min(maxRes - res, (ll) min(g[r1[k]], g[r2[k]]));
  g[r1[k]] -= direct; g[r2[k]] -= direct;
  res += direct;
  if(res == maxRes) { visited[k] = false; return res; }

  while(res < maxRes) {
    ll mk1 = make(r1[k], 1);
    ll mk2 = make(r2[k], 1);
    if(mk1 != 1 || mk2 != 1) break;
    res++;
  }
  visited[k] = false;
  return res;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
//    cerr << "tc " << tc << endl;

    int m; scanf("%d\n", &m);
    for(int i = 0; i < m; i++) {
      scanf("%d %d\n", &r1[i], &r2[i]);
      r1[i]--; r2[i]--;
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", &g[i]);
    }
    memset(visited, false, sizeof(visited));
    ll res = make(0, INF * INF);
    printf("Case #%d: %lld\n", tc, res);
  }
  return 0;
}
