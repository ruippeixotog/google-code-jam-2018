#include <algorithm>
#include <cstdio>

#define MAXN 1000

using namespace std;

typedef long double ld;

int k[MAXN], s[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int d, n; scanf("%d %d\n", &d, &n);
    for(int i = 0; i < n; i++)
      scanf("%d %d\n", &k[i], &s[i]);

    ld arrival = 0;
    for(int i = 0; i < n; i++) {
      arrival = max(arrival, (d - k[i]) / (ld) s[i]);
    }
    printf("Case #%d: %.9f\n", tc, (double) (d / arrival));
  }
  return 0;
}
