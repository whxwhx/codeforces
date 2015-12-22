#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb(a) push_back(a)
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 100010;
typedef long long LL;
 
int a[N];
vector<int> L[N], R[N];
typedef vector<int>::iterator vit;
 
int rev[N * 4], s[N * 4];//s means the number of 1
#define lc (x << 1)
#define rc (lc ^ 1)
#define mid ((l + r) >> 1)
#define lcq lc, l, mid
#define rcq rc, mid + 1, r
void push(int x, int l, int r){
    if (rev[x]) {
        rev[x] = 0, s[x] = r - l + 1 - s[x];
        if (l < r) rev[lc] ^= 1, rev[rc] ^= 1;
    }
}
void upd(int x){
    s[x] = s[lc] + s[rc];
}
void modi(int x, int l, int r, int a, int b){
    if (a > b) return;
    if (a <= l && r <= b) rev[x] ^= 1, push(x,l,r); else{
        push(x,l,r);
        if (a <= mid) modi(lcq, a, b); else push(lcq);
        if (b >  mid) modi(rcq, a, b); else push(rcq);
        upd(x);
    }
}
int qry(int x, int l, int r, int a, int b){
    if (a > b) return 0;
    push(x, l, r);
    if (a <= l && r <= b) return s[x]; else{
        int ans = 0;
        if (a <= mid) ans += qry(lcq, a, b);
        if (b >  mid) ans += qry(rcq, a, b);
        return ans;
    }
}

#undef mid
int n, k; 
int find(int x){
    int l = 1, r = n + 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        if (a[mid] <= x) l = mid; else r = mid;
    }
    return l;
}
 
int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a + 1, a + n + 1);
    rep(i,1,k){
        int t1, t2; scanf("%d%d",&t1,&t2);
        int l = find(t1), r = find(t2);
        if (a[l] < t1) l++;
        if (l < r){
            L[l].pb(r);
            R[r].pb(l);
        }
    }
    LL ans = 1LL * n * (n - 1) * (n - 2) / 3 / 2;//!
    rep(i,1,n){
        for(vit t = L[i].begin(); t != L[i].end(); t++) modi(1, 1, n, i, *t);
        LL t = i - 1 - qry(1, 1, n, 1, i - 1) + qry(1, 1, n, i + 1, n);
        ans -= t * (t - 1) / 2;
        for(vit t = R[i].begin(); t != R[i].end(); t++) modi(1, 1, n, *t, i);
    }
    cout <<ans<<endl;
}