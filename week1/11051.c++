#include <iostream>
using namespace std;

int c[1001][1001];

int nCk(int n, int k) {
  if (k == 0 || k == n)
    return 1;
  if (c[n][k] != -1)
    return c[n][k];
  c[n][k] = (nCk(n - 1, k - 1) + nCk(n - 1, k)) % 10007;
  return c[n][k];
}

int main() {

  int n, k;
  cin >> n >> k;

  if (k > n - k)
    k = n - k;

  for (int i = 0; i < 1001; i++)
    for (int j = 0; j < 1001; j++)
      c[i][j] = -1;

  cout << nCk(n, k);

  return 0;
}