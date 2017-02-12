#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 1000010, M = 1510;
struct node { int x, y, id; }a[N];
inline bool operator < (const node &a, const node &b) { return a.x / M < b.x / M || (a.x / M == b.x / M && a.y < b.y);}
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y), a[i].id = i;
	sort(a + 1, a + n + 1);
	rep(i,1,n) printf("%d ",a[i].id); printf("\n");
}