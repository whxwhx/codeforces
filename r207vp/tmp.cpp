#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long i64;

const int N = 100 + 10, M = 50000 + 10, MOD = 1000000007;

int moe[N];

int cur[N][N][N];

std::vector<int> d[N];

void sieve() {
  static int p[N];
  static bool flag[N];
  int cnt = 0;
  moe[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) moe[p[++cnt] = i] = -1;
    for (int j = 1; j <= cnt && i * p[j] < N; ++j) {
      flag[i * p[j]] = true;
      if (i % p[j] == 0) {
        moe[i * p[j]] = 0;
        break;
      }
      moe[i * p[j]] = -moe[i];
    }
//      cout <<moe[i]<<' ';
  }
 // cout <<endl;
  for (int i = 1; i < N; ++i)
    for (int j = i; j < N; j += i)
      d[j].push_back(i);
}

int n, m, x[M], y[M], z[M];

int ans[N];

std::vector<int> adj[N];

int q[N], deg[N];

void bfs() {
  int r = 0;
  for (int i = 1; i <= n; ++i) if (!deg[i]) q[++r] = i;
  for (int f = 1; f <= r; ++f) {
    int a = q[f];
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i];
      if (--deg[b] == 0) q[++r] = b;
    }
  }
}

void calc(int a) {
  if (!moe[a]) return;
  static int f[N];
  for (int i = 1; i <= n; ++i) f[i] = 0;
  for (int i = n; i > 0; --i)
    for (int j = i + 1; j <= n; ++j)
      f[i] = (f[i] + cur[a][q[i]][q[j]] * (f[j] + 1LL)) % MOD;
  ans[a] = 0;
  for (int i = 1; i <= n; ++i) (ans[a] += f[i]) %= MOD;
}

void solve() {
  int sum = 0;
  for (int i = 0; i < N; ++i) sum = (sum + (i64)moe[i] * ans[i]) % MOD;
  printf("%d\n", (sum + MOD) % MOD);
}

int main() {
  sieve();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &x[i], &y[i], &z[i]);
    adj[x[i]].push_back(y[i]);
    ++deg[y[i]];
    for (int j = 0; j < d[z[i]].size(); ++j) ++cur[d[z[i]][j]][x[i]][y[i]];
  }
  bfs();
  for (int i = 1; i < N; ++i) calc(i);
  solve();
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < d[z[a]].size(); ++i) {
      int t = d[z[a]][i];
      --cur[t][x[a]][y[a]];
      calc(t);
    }
    z[a] = b;
    for (int i = 0; i < d[b].size(); ++i) {
      int t = d[b][i];
      ++cur[t][x[a]][y[a]];
      calc(t);
    }
    solve();
  }
  return 0;
}