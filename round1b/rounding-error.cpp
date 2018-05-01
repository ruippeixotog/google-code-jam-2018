#include <cstdio>
#include <set>
#include <tuple>

#define MAXN 100000

using namespace std;

int n, l, c[MAXN];

multiset<tuple<int, int, int>> s;

void insert(int ci) {
  int curr = (ci * 100 + (n / 2)) / n;
  int next = ((ci + 1) * 100 + (n / 2)) / n;
  int nextMod = ((ci + 1) * 100 + (n / 2) + (n - 1)) % n;
  s.insert(make_tuple(next - curr, nextMod, ci));
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d\n", &n, &l);
    for(int i = 0; i < l; i++)
      scanf("%d", &c[i]);

    s.clear();
    int left = n;
    for(int i = 0; i < n; i++) {
      int ci = i < l ? c[i] : 0;
      left -= ci;
      insert(ci);
    }
    while(left--) {
      int ci = get<2>(*prev(s.end()));
      s.erase(prev(s.end()));
      insert(ci + 1);
    }
    int cnt = 0;
    for(auto& p : s) {
      cnt += (get<2>(p) * 100 + (n / 2)) / n;
    }
    printf("Case #%d: %d\n", tc, cnt);
  }
  return 0;
}
