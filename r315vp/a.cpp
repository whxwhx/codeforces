#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 3000010;
bool a[N]; int p[N], l = 0, s[N], s1[N];
bool pd(int x) {
	int l = 0, d[10];
	while (x) d[++l] = x % 10, x /= 10;
	rep(i,1,l) if (d[i] != d[l - i + 1]) return false;
	return true;
}
void init() {
	rep(i,2,N - 10) {
		if (!a[i]) p[++l] = i;
		rep(j,1,l) {
			int k = i * p[j]; if (k > N - 10) break;
			a[k] = true;
			if (i % p[j] == 0) break; 
		}
		s[i] = s[i - 1] + (!a[i]);
	}
	rep(i,1,N - 10) s1[i] = s1[i - 1] + pd(i);
}
int main() {
	int p, q; scanf("%d%d",&p,&q);
	init(); 
	dep(i,N - 10,1) if (1LL * s[i] * q <= 1LL * p * s1[i]) { printf("%d\n",i); return 0; }
	printf("Palindromic tree is better than splay tree\n"); return 0;
}
