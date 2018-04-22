#include <algorithm>
#include <cstdio>

#define MAXC 1000

using namespace std;

typedef long long ll;

int m[MAXC], s[MAXC], p[MAXC];

int items[MAXC];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int r, b, c; scanf("%d %d %d\n", &r, &b, &c);
    for(int i = 0; i < c; i++)
      scanf("%d %d %d\n", &m[i], &s[i], &p[i]);

    ll minTime = 2, maxTime = (ll) 2e18;
    while(minTime < maxTime) {
      ll time = (maxTime + minTime) / 2;

      for(int i = 0; i < c; i++) {
        items[i] = (int) max(0LL, min((ll) m[i], (time - p[i]) / s[i]));
      }
      sort(items, items + c);
      ll cnt = 0;
      for(int i = 0; i < r; i++) cnt += items[c - i - 1];

      if(cnt >= b) maxTime = time;
      else minTime = time + 1;
    }
    printf("Case #%d: %lld\n", tc, minTime);
  }
  return 0;
}
