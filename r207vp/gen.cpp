#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)//(a)!
#define dep(i,a,b) for(int i = (a); i >= (b); i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 110;
int id[N];
int main() {
	int t; cin >>t; srand(t);
	int n = 5, m = 7; cout <<n<<' '<<m<<endl;
	rep(i,1,n) id[i] = i;
	rep(i,1,n) swap(id[i], id[rand() % i + 1]);
	rep(i,1,m) {
		int x = rand() % n + 1, y = rand() % n + 1;
		while (x == y) x = rand() % n + 1, y = rand() % n + 1;
		if (x > y) swap(x, y);
		cout <<id[x]<<' '<<id[y]<<' '<<rand() % 10 + 1<<endl;
	}
	int T = 7; cout <<T<<endl;
	rep(i,1,T) {
		cout <<rand() % m + 1<<' '<<rand() % 10 + 1<<endl;
	}
}