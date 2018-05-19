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

int b[MAXN];

char grid[MAXN][MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int c; scanf("%d\n", &c);
    for(int i = 0; i < c; i++)
      scanf("%d", &b[i]);

    if(b[0] == 0 || b[c - 1] == 0) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    } else {
      memset(grid, '.', sizeof(grid));

      int maxRows = 1, supply = 0;
      for(int i = 0; i < c; i++) {
//        cerr << "c=" << i << "; supply " << supply << endl;

        if(supply < 0) {
          maxRows = max(maxRows, -supply + 1);
          for(int j = 0; j < -supply; j++) {
            grid[j][i] = '/';
          }
        } else {
          maxRows = max(maxRows, supply - b[i] + 2);
          for(int j = 0; j < supply + 1 - b[i]; j++) {
            grid[j][i] = '\\';
          }
        }
        supply += 1 - b[i];
      }
      printf("Case #%d: %d\n", tc, maxRows);
      for(int i = 0; i < maxRows; i++) {
        for(int j = 0; j < c; j++) {
          printf("%c", grid[i][j]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
