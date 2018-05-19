#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 100

using namespace std;

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

      int maxRows = 0, supply = 0;
      for(int i = 0; i < c; i++) {
        maxRows = max(maxRows, -supply);
        for(int j = 0; j < -supply; j++) {
          grid[j][i] = '/';
        }
        supply += 1 - b[i];
        maxRows = max(maxRows, supply);
        for(int j = 0; j < supply; j++) {
          grid[j][i] = '\\';
        }
      }
      printf("Case #%d: %d\n", tc, maxRows + 1);
      for(int i = 0; i < maxRows + 1; i++) {
        for(int j = 0; j < c; j++) {
          printf("%c", grid[i][j]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
