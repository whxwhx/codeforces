#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 200010, Q = 500010;
int f[N + Q], tag[N * 4];
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
void merge(int x, int t){
	//cout <<x<<' '<<t<<endl;
	if (tag[x] == 0) 
		tag[x] = t;
	else{
		int fx = find(tag[x]);
		f[fx] = t;
	}
}
void push(int x, int l, int r){
	if (tag[x] == 0) return;
	if (l == r){
		int fx = find(l);
		cout <<x<<' '<<l<<' '<<r<<' '<<fx<<' '<<tag[x]<<endl;
		f[fx] = tag[x];
		tag[x] = 0;
	}else{
		merge(lc, tag[x]);
		merge(rc, tag[x]);
		tag[x] = 0;
	}
}
void fix(int x, int l, int r, int a){
	cout <<x<<' '<<a<<endl;
	push(x, l, r);
	if (l == r) return; else{
		if (a <= mid) fix(lcq,a);
		if (a >  mid) fix(rcq,a);
	}
}
void modify(int x, int l, int r, int a, int b, int t){
	//cout <<x<<' '<<l<<' '<<r<<' '<<a<<' '<<b<<endl;
	//cout <<x<<' '<<t<<endl;
	if (a <= l && b >= r) merge(x, t);else{
		push(x, l, r);
		if (a <= mid) modify(lcq, a, b, t);
		if (b >  mid) modify(rcq, a, b, t);
	}
}
int main(){
	int n, q; scanf("%d%d",&n,&q);
	rep(i,1,n + q) f[i] = i;
	tl = n;
	rep(i,1,q){
		int type, x, y; scanf("%d%d%d",&type,&x,&y);
		if (type == 1){
			tl++;
			fix(rtq,x), fix(rtq, y);
			int fa = find(x), fb = find(y);
			f[fa] = f[fb] = tl;
		}else if (type == 2){
			tl++;
			modify(rtq, x, y, tl);
		}else if (type == 3){
			//cout <<f[2]<<' '<<f[5]<<endl;
			fix(rtq,x), fix(rtq, y);
			if (find(x) == find(y))
				printf("YES\n");
			else 
				printf("NO\n");
		}
		rep(j,1,tl) cout <<tag[j]<<' '<<f[j]<<endl;
		cout <<endl;
		//cout <<tag[1]<<endl;
	}
	return 0;
}