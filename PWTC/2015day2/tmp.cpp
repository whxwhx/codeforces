#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long LL;
int n, m, c;
const int M = 30010, N = 101; 
LL sta[M]; int cnt = 0;
int f[N]; 
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int a, int b) { int fa = find(a), fb = find(b); f[fa] = fb; }
void dfs(int x, LL S) {
	//check
	rep(i,1,m) f[i] = i;
	rep(i,1,x - 1) if (S >> i & 1) rep(j,1,i) merge(j, m - i + j);
	rep(i,1,x - 1) if (!(S >> i & 1)) { 
		bool flag = true; rep(j,1,i) if (find(j) != find(m - i + j)) { flag = false; break; } 
		if (flag) return;
	}
	//dfs
	if (x == m) sta[++cnt] = S;
	else dfs(x + 1, S), dfs(x + 1, S | (1LL << x));
}
int main() {
	scanf("%d%d%d",&n,&m,&c);
	dfs(1,0);
	cout <<cnt<<endl;
	return 0;
}