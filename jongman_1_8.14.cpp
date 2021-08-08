#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int mod = 10000000;
int cache[101][101];

int poly(int n,int last){
	int& ret = cache[n][last];
	if(ret!=-1) return ret;
	if(n==last) return ret = 1;
	if(n==0) return ret = 1;
	if(n==1) return ret = 1;
	ret = 0;
	for(int i=1;i<=n-last;++i){
		ret += (poly(n-last,i)%mod) * ((last+i-1)%mod);
		ret %= mod;		
	}
	return ret;
}

int main(){
	int C;
	cin >> C;
	memset(cache,-1,sizeof(cache));
	for(int test = 0; test<C; ++test){
		int n;
		cin >> n;
		int total = 0;
		for(int i=1;i<=n;++i){
			total += poly(n,i)%mod;
		}
		cout << total%mod << endl;
	}
	return 0;
}