#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ll n, k; scanf("%lld %lld\n", &n, &k);

    map<ll, ll> segments = {{ n, 1 }};
    ll lastSz = k;
    while(k > 0) {
      ll sz = segments.rbegin()->first, toTake = segments.rbegin()->second;
      segments[(sz - 1) / 2] += toTake;
      segments[sz / 2] += toTake;
      segments.erase(prev(segments.end()));
      k -= toTake;
      lastSz = sz;
    }
    printf("Case #%d: %lld %lld\n", tc, lastSz / 2, (lastSz - 1) / 2);
  }
  return 0;
}
