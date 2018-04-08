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

#define MAXN 100000

using namespace std;

int v0[(MAXN + 1) / 2], v1[MAXN / 2];

int& get(int i) {
  return (i % 2 ? v1 : v0)[i / 2];
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &get(i));
    }
    sort(v0, v0 + (n + 1) / 2);
    sort(v1, v1 + n / 2);

    int err = -1;
    for(int i = 1; i < n; i++) {
      if(get(i - 1) > get(i)) { err = i - 1; break; }
    }
    if(err == -1) printf("Case #%d: OK\n", tc);
    else printf("Case #%d: %d\n", tc, err);
  }
  return 0;
}
