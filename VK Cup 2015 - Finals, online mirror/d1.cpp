#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 200010, Q = 500010;
int f[N + Q], tag[N * 4], n, q;
#define lc (x << 1)
#define rc (lc + 1)
#define mid ((l + r) >> 1)
#define rtq 1,1,n
#define lcq lc,l,mid
#define rcq rc,mid+1,r
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
int tl;
int qry(int x, int l, int r, int a){
	if (tag[x]) return find(tag[x]);
	if (l == r) return l;
	if (a <= mid) return qry(lcq,a); else return qry(rcq,a);
}
void rf(int x){
	int t = qry(rtq, x), fx = find(x);
	f[x] = t;
}
void modify(int x, int l, int r, int a, int b, int t){
	if (tag[x]){
		int fx = find(tag[x]);
		f[fx] = t;
		return;
	}
	if (a <= l && b >= r) tag[x] = t;
	if (l != r){
		if (a <= mid) modify(lcq, a, b, t);
		if (b >  mid) modify(rcq, a, b, t);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n + q) f[i] = i;
	tl = n;
	rep(i,1,q){
		int type, x, y; scanf("%d%d%d",&type,&x,&y);
		if (type == 1){
			tl++;
			modify(rtq, x, x, tl);
			modify(rtq, y, y, tl);
		}else if (type == 2){
			modify(rtq, x, y, ++tl);	
		}else if (type == 3){
			rf(x), rf(y);
			int fa = find(x), fb = find(y);
			if (fa == fb) printf("YES\n"); else printf("NO\n");
		}
	}
	return 0;

}