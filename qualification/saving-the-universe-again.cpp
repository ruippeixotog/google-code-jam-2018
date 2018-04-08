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

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int d; string p; cin >> d >> p;

    vector<int> shoots;
    int dmg = 0, pwr = 1;
    for(char ch : p) {
      if(ch == 'S') { shoots.push_back(pwr); dmg += pwr; }
      else pwr *= 2;
    }

    int hacks = 0, idx = (int) shoots.size() - 1;
    while(dmg > d) {
      if(idx < 0 && pwr == 1) break;
      while(idx < 0 || shoots[idx] < pwr) {
        pwr /= 2;
        idx = (int) shoots.size() - 1;
      }
      shoots[idx--] /= 2;
      dmg -= pwr / 2;
      hacks++;
    }
    if(dmg > d) printf("Case #%d: IMPOSSIBLE\n", tc);
    else printf("Case #%d: %d\n", tc, hacks);
  }
  return 0;
}
