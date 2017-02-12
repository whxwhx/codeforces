#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int main(){
	int n = 5, t;
	cin >>t; srand(t);
	cout <<n<<endl;
	rep(i,1,5) cout <<rand() % 5 + 1<<' ';
	cout <<endl;
	rep(i,1,5) cout <<rand() % 5 + 1<<' ';
	cout <<endl;
	rep(i,1,5) cout <<rand() % 5 + 1<<' ';
	cout <<endl;
}