#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rek(i,k) for(int i=0;i<l;i += (k << 1))
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define hlt {printf("NO\n");return 0;}
using namespace std;
const int N = 200100;
char C[N];
int a[N], b[N], ca[N], cb[N];
struct edge{
	int to, pre;
}e[N];
int L;
int u[N];
void ins(int a, int b){
	e[++L] = (edge){b, u[a]}, u[a] = L;
}
#define reg(i,a) for(int i=u[a];i;i=e[i].pre)
#define v e[i].to
void build(int *a, int *c, int k, int l){
	L = 0;
	rep(i,0,l - 1) u[i] = 0;

	rek(i,k) if (a[i] < a[i + k]) swap(a[i], a[i + k]);
	rep(i,0,l - 1) c[i] = 0;
	rek(i,k) c[a[i + k]]++;
	rep(i,1,l - 1) c[i] += c[i - 1];
	rek(i,k) ins(c[a[i + k]], i);

	rep(i,0,l - 1) c[i] = 0;
	rek(i,k) c[a[i]]++;
	rep(i,1,l - 1) c[i] += c[i - 1];
	rep(j,0,l - 1){
		reg(i,j) a[v] = c[a[v]];
		reg(i,j) c[a[v]]--;
	}

	rep(i,0,l - 1) c[i] = 0;
	rek(i,k) c[a[i]]++;
	rep(i,1,l - 1) c[i] += c[i - 1];
}
int main(){
	scanf("%s",C);int l = strlen(C);
	rep(i,0,l - 1) a[i] = C[i] - 'a';
	scanf("%s",C);int l1 = strlen(C);
	rep(i,0,l - 1) b[i] = C[i] - 'a';
	if (l1 != l) hlt

	rep(i,0,26 - 1) ca[i] = 0;
	rep(i,0,l - 1) ca[a[i]]++;
	rep(i,1,26 - 1) ca[i] += ca[i - 1];
	rep(i,0,l - 1) a[i] = ca[a[i]];

	rep(i,0,26 - 1) cb[i] = 0;
	rep(i,0,l - 1) cb[b[i]]++;
	rep(i,1,26 - 1) cb[i] += cb[i - 1];
	rep(i,0,l - 1) b[i] = cb[b[i]];

	rep(i,0,l - 1) if (ca[i] != cb[i]) hlt

	int tl = l;
	if (tl & 1){
		rep(i,0,l - 1) if (a[i] != b[i]) hlt
		printf("Yes\n");
		return 0;
	}

	for(int k = 1; k < l; k <<= 1){
		build(a, ca, k, l);
		build(b, cb, k, l);
		rep(i,0,l - 1) if (ca[i] != cb[i]) hlt
		tl >>= 1;
		if (tl & 1){
			rek(i,k) if (a[i] != b[i]) hlt
			printf("Yes\n");
			return 0;
		}
	}
	if (a[0] != b[0]) hlt
	printf("Yes\n");
	return 0;
}