#include <algorithm>
#include <cstdio>

#define MAXN 26

using namespace std;

int p[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d\n", &p[i]);

    int psum = 0;
    for(int i = 0; i < n; i++) { psum += p[i]; }

    printf("Case #%d:", tc);
    if(n == 2) {
      for(int i = 0; i < p[0]; i++) {
        printf(" AB");
      }
    } else {
      for(int i = 0; i < psum - 2; i++) {
        int* mx = max_element(p, p + n);
        printf(" %c", (char) ('A' + (mx - p)));
        (*mx)--;
      }
      printf(" ");
      for(int i = 0; i < n; i++) {
        if(p[i] > 0) printf("%c", (char) ('A' + i));
      }
    }
    printf("\n");
  }
  return 0;
}
