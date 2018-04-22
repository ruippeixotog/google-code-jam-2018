#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;

vector<ld> cross(vector<ld> u, vector<ld> v) {
  return {
    u[1] * v[2] - u[2] * v[1],
    u[2] * v[0] - u[0] * v[2],
    u[0] * v[1] - u[1] * v[0]
  };
}

void printVec(vector<ld> v) {
  printf("%.9lf %.9lf %.9lf\n",
         (double) (v[0] / 2), (double) (v[1] / 2), (double) (v[2] / 2));
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ld a; cin >> a;
    printf("Case #%d:\n", tc);

    // equation system for solving n2 = {x, y, z}:
    // x^2 + y^2 + z^2 = 1                  // n2 must have norm 1
    // n1[0]*x + n1[1]*y + n1[2]*z = 0      // n2 must be orthogonal to n1
    // n1[1] + y + (n1[0]*z-n1[2]*x) = a    // the sum of the 3 y components must equal a
    vector<ld> n1, n2;
    if(a <= 2.0 / sqrt(2.0)) {
      ld x = (a - sqrt(2 - a * a)) / 2;
      n1 = {0, 0, 1};
      n2 = {x, a - x, 0};
    } else {
      ld b = 1.0 / sqrt(3.0);
      ld x = (sqrt((b - 1) * (b - 1) * (-3 * a * a + 6 * a * b + 3 * b * b + 2))
              - 3 * a * b - a + 3 * b * b + b) / (2 * (3 * b * b + 1));
      ld y = (-b * sqrt((b - 1) * (b - 1) * (-3 * a * a + 6 * a * b + 3 * b * b + 2))
              + a * b - a - b * b + b) / ((b - 1) * (3 * b * b + 1));
      n1 = { b, b, b };
      n2 = { x, y, -(x + y) };
    };
    printVec(n1);
    printVec(n2);
    printVec(cross(n2, n1));
  }
  return 0;
}
