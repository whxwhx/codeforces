#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define print(a, b, c, d) printf("? %d %d %d %d\n",a,c,b,d)
using namespace std;
int main() {
	int n; scanf("%d",&n);
	int X[4], Y[4];
	{
		int x = 0;
		dep(j,16,0) if (x + (1 << j) <= n) {
			print(1, x + (1 << j), 1, n);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t == 0) x += (1 << j);
		}
		int r1 = x + 1;
		dep(j,16,0) if (x + (1 << j) <= n) {
			print(1, x + (1 << j), 1, n);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t <= 1) x += (1 << j);
		}
		int r2 = x + 1;

		x = n + 1;
		dep(j,16,0) if (x - (1 << j) > 0) {
			print(x - (1 << j), n, 1, n);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t == 0) x -= (1 << j);
		}
		int l2 = x - 1;
		dep(j,16,0) if (x - (1 << j) > 0) {
			print(x - (1 << j), n, 1, n);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t <= 1) x -= (1 << j);
		}
		int l1 = x - 1;

		if (l2 <= r1) {
			print(l2, r1, 1, n);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t) swap(r1, r2);
		}

		X[0] = l1, X[1] = r1, X[2] = l2, X[3] = r2;
	}

	{
		int x = 0;
		dep(j,16,0) if (x + (1 << j) <= n) {
			print(1, n, 1, x + (1 << j));
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t == 0) x += (1 << j);
		}
		int r1 = x + 1;
		dep(j,16,0) if (x + (1 << j) <= n) {
			print(1, n, 1, x + (1 << j));
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t <= 1) x += (1 << j);
		}
		int r2 = x + 1;

		x = n + 1;
		dep(j,16,0) if (x - (1 << j) > 0) {
			print(1, n, x - (1 << j), n);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t == 0) x -= (1 << j);
		}
		int l2 = x - 1;
		dep(j,16,0) if (x - (1 << j) > 0) {
			print(1, n, x - (1 << j), n);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t <= 1) x -= (1 << j);
		}
		int l1 = x - 1;

		if (l2 <= r1) {
			print(1, n, l2, r1);
			fflush(stdout);
			int t; scanf("%d",&t);
			if (t) swap(r1, r2);
		}

		Y[0] = l1, Y[1] = r1, Y[2] = l2, Y[3] = r2;
	}

	if (X[3] - X[2] < X[1] - X[0]) swap(X[0], X[2]), swap(X[1], X[3]);

	int mnx = 0;
	rep(i,0,1) {
		print(X[0], X[1], Y[i * 2], Y[i * 2 + 1]);
		fflush(stdout);
		int t; scanf("%d",&t);
		if (t) mnx = i;
	}
	printf("! %d %d %d %d %d %d %d %d\n",X[0], Y[mnx * 2], X[1], Y[mnx * 2 + 1], X[2], Y[(mnx ^ 1) * 2], X[3], Y[(mnx ^ 1) * 2 + 1]);
	fflush(stdout);
	return 0;
}