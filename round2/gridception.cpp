#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAXN 20

using namespace std;

int r, c; string grid[MAXN];

bool enabledColorMasks[1 << 4];
int colorMask, limitI, limitJ;
bool visited[MAXN][MAXN];

char validColor(int i, int j) {
  int sideI = i >= limitI, sideJ = j >= limitJ, bit = (sideI << 1) | sideJ;
  return grid[i][j] == (colorMask & (1 << bit) ? 'B' : 'W');
}

int ffill(int i, int j) {
  if(i < 0 || i >= r || j < 0 || j >= c || visited[i][j] || !validColor(i, j)) {
    return 0;
  }
  visited[i][j] = true;
  return 1 + ffill(i + 1, j) + ffill(i - 1, j) +
    ffill(i, j + 1) + ffill(i, j - 1);
}

int bestPattern() {
  memset(visited, false, sizeof(visited));
  int best = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      best = max(best, ffill(i, j));
    }
  }
  return best;
}

void findColorMasks() {
  memset(enabledColorMasks, false, sizeof(enabledColorMasks));
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      enabledColorMasks[grid[i][j] == 'W' ? 0 : 0b1111] = true;
      if(i > 0) {
        enabledColorMasks[
          (grid[i - 1][j] == 'W' ? 0 : 0b0011) |
          (grid[i][j] == 'W' ? 0 : 0b1100)] = true;
        if(j > 0) {
          enabledColorMasks[
            (grid[i - 1][j - 1] == 'W' ? 0 : 0b0001) |
            (grid[i - 1][j] == 'W' ? 0 : 0b0010) |
            (grid[i][j - 1] == 'W' ? 0 : 0b0100) |
            (grid[i][j] == 'W' ? 0 : 0b1000)] = true;
        }
      }
      if(j > 0) {
        enabledColorMasks[
          (grid[i][j - 1] == 'W' ? 0 : 0b0101) |
          (grid[i][j] == 'W' ? 0 : 0b1010)] = true;
      }
    }
  }
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d\n", &r, &c);
    for(int i = 0; i < r; i++) {
      cin >> grid[i];
    }

    findColorMasks();
    int best = 0;
    for(colorMask = 0; colorMask < (1 << 4); colorMask++) {
      if(!enabledColorMasks[colorMask]) continue;
      for(limitI = 0; limitI < r; limitI++) {
        for(limitJ = 0; limitJ < c; limitJ++) {
          best = max(best, bestPattern());
        }
      }
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
