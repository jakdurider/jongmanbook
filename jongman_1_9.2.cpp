#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int cache[101][1001];
string name[101];
int volume[101];
int want[101];
void backtracking(int n, int w, vector<string>& vec){
	if(n==0 || w==0) return;
	if(volume[n]>w) backtracking(n-1,w,vec);
	else{
		if(cache[n][w] == cache[n-1][w]) backtracking(n-1,w,vec);
		else{
			backtracking(n-1,w-volume[n],vec);
			vec.push_back(name[n]);
		}
	}
}

int dp(int n, int w){
	int& ret = cache[n][w];
	if(ret!=-1) return ret;
	if(n==0 || w==0) return ret = 0;
	if(volume[n] > w) return ret = dp(n-1,w);
	else return ret = max(dp(n-1,w),dp(n-1,w-volume[n])+want[n]);
}

int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C; ++test){
		memset(cache,-1,sizeof(cache));
		int N, W;
		cin >> N;
		cin >> W;
		for(int i=0;i<N;++i){
			cin >> name[i+1] >> volume[i+1] >> want[i+1];
		}
		cout << dp(N,W) << " ";
		vector<string> vec;
		backtracking(N,W,vec);
		cout << vec.size() << endl;
		for(int i=0;i<vec.size();++i){
			cout << vec[i] << endl;
		}
	}
	return 0;
}