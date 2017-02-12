#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 1000;
int ans[N];
int main(){
	int a, b; scanf("%d%d",&a,&b);
	int da = 0, db = 0;
	for(int i = a; i; i = (i >> 1)) {
		da++;
		if (i == b) {printf("-1\n"); return 0;}
	}
	for(int i = b; i; i = (i >> 1)) {
		db++;
		if (i == a) {printf("-1\n"); return 0;}
	}
	ans[0] = 2; ans[1] = a, ans[2] = b;
	while (a != b){
		if (da < db) swap(a, b), swap(da, db);
		ans[++ans[0]] = a^1; a >>= 1; da--;
	}
	ans[0] -= 2;
	while (a != 1) ans[++ans[0]] = a^1, a >>= 1;
	sort(ans + 1, ans + ans[0] + 1);
	rep(i,1,ans[0]) printf("%d ",ans[i]); printf("\n");
	return 0;
}