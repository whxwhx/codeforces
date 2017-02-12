#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef unsigned int ui;
const int N = 80010, M = 32, B = 2190;
ui f[2][B];
typedef pair<int, int> node;
#define mp(a,b) make_pair(a,b)
node tmp[N];
int a[N], first[N], id[N], b[N], l = 0, ind[N], pre[N];
bool ch[N];
int main() {
	int n, s; scanf("%d%d",&n,&s);
	rep(i,1,n) scanf("%d",&a[i]), tmp[i].first = a[i], tmp[i].second = i;
	
	sort(tmp + 1, tmp + n + 1);
	rep(i,1,n) a[i] = tmp[i].first, ind[ id[i] = tmp[i].second ] = i;
	s -= a[n], n--;
	if (s < 0) { printf("-1\n"); return 0; }
	int t = 0; f[t][0] = 1;
	rep(T,1,n) {
		t ^= 1;
		memset(f[t], 0, sizeof(f[t]));
		int shift = a[T], block = a[T] / M, w = a[T] % M;
		for(int i = 0; i + block < B; i++) f[t][i + block] = f[t^1][i];

		int t0 = (1LL << (M - w)) - 1, t1 = ((1LL << M) - 1) ^ t0;
		f[t][B - 1] = ( f[t][B - 1] & t0 ) << w;
		for(int i = B - 2; i >= 0; i--) 
			f[t][i + 1] |= (f[t][i] & t1) >> (M - w),
			f[t][i] = (f[t][i] & t0) << w;

		for(int i = 0; i < B; i++) {
			f[t][i] |= f[t^1][i];
			if (f[t][i] != f[t^1][i]) {
				rep(j,0,31) if ((f[t][i] ^ f[t^1][i]) >> j & 1) 
					first[ M * i + j ] = T;
			}
		}
	}
	first[0] = -1;
	if (!first[s]) printf("-1\n");
	else {
		while (s != 0) {
			b[++l] = first[s];
			s -= a[ first[s] ];
		}

//		rep(i,1,l) cout <<a[b[i]]<<' '; cout <<endl;

		rep(i,1,l) ch[b[i]] = true; int mxa = 0;
		n++;
		rep(i,1,n) if (!ch[i]) pre[i] = mxa, mxa = i;
		rep(i,1,n) if (ch[ ind[i] ]) printf("%d %d\n",a[ind[i]], 0);
		else {
			printf("%d ",a[ind[i]] - a[pre[ind[i]]]);
			if (pre[ind[i]]) printf("%d %d\n",1,id[ pre[ind[i]] ]); else printf("0\n");
		}
		return 0;
	}
	return 0;
}
