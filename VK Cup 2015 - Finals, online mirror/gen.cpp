#include <iostream>
#include <cstdio>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int main(){
	int n = 200000, m = 500000;
	cout <<n<<' '<<m<<endl;
	rep(i,0,n / 2 - 1){
		cout <<2<<' '<<100000 - i<<' '<<100000 + i<<endl;
	}
	return 0;
}