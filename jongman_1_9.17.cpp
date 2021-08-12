#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int num[50];
int cache[50][50];
int dp(int i,int j){	
	if(i>j) return 0;
	int& ret = cache[i][j];
	if(ret != -1) return ret;
	if(i==j) return ret = num[i];
	ret = max(max(num[i]-dp(i+1,j),num[j]-dp(i,j-1)),max(-dp(i+2,j),-dp(i,j-2)));
	return ret;
}
int main(){
	int C;
	cin >> C;
	for(int test=0;test<C;++test){
		memset(cache,-1,sizeof(cache));		
		int n;
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> num[i];
		}
		cout << dp(0,n-1) << endl;
	}
	return 0;
}
