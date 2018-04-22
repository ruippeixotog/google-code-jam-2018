#include <cstdio>
#include <cstring>

#define MAXR 100
#define MAXC 100

int r, c, h, v;
bool cells[MAXR][MAXC];

int chips, partH[MAXR], cntH[MAXR];

bool solve() {
  if(chips == 0) return true;
  if(chips % ((h + 1) * (v + 1)) != 0) return false;

  memset(partH, 0, sizeof(partH));
  int target = chips / (h + 1);
  for(int i = 0, k = 0, cnt = 0; i < r; i++) {
    for(int j = 0; j < c; j++) cnt += cells[i][j];
    partH[i] = k;

    if(cnt > (k + 1) * target) return false;
    if(cnt == (k + 1) * target) k++;
  }

  memset(cntH, 0, sizeof(cntH));
  target = chips / ((h + 1) * (v + 1));
  for(int j = 0, k = 0; j < c; j++) {
    for(int i = 0; i < r; i++) cntH[partH[i]] += cells[i][j];

    int partCnt = 0;
    for(int i = 0; i < h + 1; i++) {
      if(cntH[i] > (k + 1) * target) return false;
      if(cntH[i] == (k + 1) * target) partCnt++;
    }
    if(partCnt == h + 1) k++;
  }
  return true;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d %d %d\n", &r, &c, &h, &v);
    chips = 0;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        char ch; scanf("%c", &ch);
        cells[i][j] = ch == '@';
        chips += ch == '@';
      }
      scanf("\n");
    }
    printf("Case #%d: %s\n", tc, solve() ? "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}
