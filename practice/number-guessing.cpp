#include <cstdio>
#include <cstring>

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int a, b; scanf("%d %d", &a, &b);
    scanf("%*d");

    while(a < b) {
      int mid = (a + b + 1) / 2;
      printf("%d\n", mid); fflush(stdout);

      char res[12]; scanf("%s", res);
      if(strcmp(res, "CORRECT") == 0) break;
      else if(strcmp(res, "TOO_SMALL") == 0) a = mid;
      else b = mid - 1;
    }
  }
  return 0;
}
