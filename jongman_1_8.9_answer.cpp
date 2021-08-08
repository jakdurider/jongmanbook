#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[101];
int psum[101];
int psum_square[101];
int n,s;
int cache[101][11];
int minerror(int from, int end){
	int sum = psum[end] - (from==0 ? 0 : psum[from-1]);
	int sqsum = psum_square[end] - (from==0 ? 0 : psum_square[from-1]);
	int m = int(0.5+(double)sum/(end-from+1));
	return sqsum - 2*m*sum + m*m*(end-from+1);
}
int dp(int from, int set){
	int& ret = cache[from][set];
	if(ret!=-1) return ret;
	if(from == n) return ret = 0;
	if(set == 0) return ret = 10000000;
	ret = 100000000;
	for(int end=from;end< n;++end){
		ret = min(ret,minerror(from,end)+dp(end+1,set-1));
	}
	return ret;
}
int main(){
	int testcase;
	cin >> testcase;
	for(int test=0;test<testcase;++test){
		memset(cache,-1,sizeof(cache));
		cin >> n >> s;
		for(int i=0;i<n;++i){
			cin >> num[i];
		}
		sort(num,num+n);
		psum[0] = num[0];
		psum_square[0] = num[0]*num[0];
		for(int i=1;i<n;++i){
			psum[i] = psum[i-1]+ num[i];
			psum_square[i] = psum_square[i-1] + num[i]*num[i];
		}
		cout << dp(0,s) << endl;
	}
	return 0;
}