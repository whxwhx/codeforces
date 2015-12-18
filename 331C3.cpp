#include <iostream>
#include <cstdio>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 180000, M = 997807;
typedef long long LL; 

struct hashnode{
    int b, c, pre;
    LL a, f, g;
}h[N];
int l = 0, u[M];
void add(LL a, int b, int c, LL f, LL g){
    int H = (a + b * 137 * c * 373) % M;
    h[++l] = (hashnode){b, c, u[H], a, f, g};
    u[H] = l;
}
pair<LL, LL> qry(LL a, int b, int c){
    int H = (a + b * 137 * c * 373) % M;
    for(int i = u[H]; i; i = h[i].pre) if (h[i].a == a && h[i].b == b && h[i].c == c) return mp(h[i].f, h[i].g);
    return mp(-1, 0);
}
 
#define max(a,b) ((a) > (b) ? (a) : (b))

LL pw[19];
pair<LL, LL> f(LL n, int a, int b){ 
    if (n == 0) return mp(0, 0);
    if (n <= b) return mp(1, -b); else if (a == 0) return mp(1, -n);

    if (n / pw[a] == 0) return f(n, a - 1, b);
    
    pair<LL, LL> t = qry(n, a, b), ans = mp(0, 0);
    if (t.first != -1) return t;

    LL t1 = n;//!
    while (n / pw[a] && n > 0){
        if (n % pw[a] == 0) {
            int t = n / pw[a];
            n -= max(b, t), ans.second -= max(b, t), ans.first++;
        }
        t = f(n % pw[a], a - 1, max(b, n / pw[a]));
        n += t.second;
        ans.second += t.second, ans.first += t.first;
    }

    add(t1, a, b, ans.first, ans.second);
    return ans;
}
int main(){
    LL n; cin >>n;
    pw[0] = 1;
    rep(i,1,18) pw[i] = pw[i - 1] * 10; 
    cout <<f(n, 18, 0).first<<endl;
}
