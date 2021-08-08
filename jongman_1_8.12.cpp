#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long prime = 1000000007;
long long any[101];
long long asym[101];


long long dp(int n){
	long long& ret = asym[n];
	if(ret!=-1) return ret;
	if(n<=2) return ret = 0;
	if(n==3) return ret = 2;
	ret = (any[n-3]%prime) + (any[n-3]%prime) + (dp(n-2)%prime) + (dp(n-4)%prime);
	ret %= prime;
	return ret;
}

int main(){
	any[0] = 1; any[1] = 1; any[2] = 2;
	for(int i=3;i<101;++i) any[i] = (any[i-1] + any[i-2])%prime;
	int C;
	cin >> C;
	memset(asym,-1,sizeof(asym));
	for(int test= 0;test<C;++test){
		int n;
		cin >> n;
		cout << dp(n) << endl;
	}
	return 0;
}