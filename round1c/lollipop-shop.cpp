#include <cstdio>
#include <cstring>

#define MAXN 200

bool sold[MAXN];
int cnt[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);

    memset(sold, false, sizeof(sold));
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; i++) {
      int d; scanf("%d", &d);

      int choice = -1;
      for(int j = 0; j < d; j++) {
        int li; scanf("%d", &li);
        cnt[li]++;
        if(!sold[li] && (choice == -1 || cnt[li] < cnt[choice])) {
          choice = li;
        }
      }
      if(choice >= 0) sold[choice] = true;
      printf("%d\n", choice); fflush(stdout);
    }
  }
  return 0;
}
