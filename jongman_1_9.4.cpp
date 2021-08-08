#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
string word[500];
double B[500];
double T[500][500];
double M[500][500];
int classified[100];
double cache[100][500];

int m,q;
void backtracking(int n, int last){
	if(n==0){
		cout << word[last] << " ";
		return;
	}
	for(int i=0;i<m;++i){
		if(cache[n][last]==cache[n-1][i]*T[i][last]*M[last][classified[n]]){
			backtracking(n-1,i);
			break;
		}
	}
	cout << word[last] << " ";
}

double dp(int n,int last){
	double& ret = cache[n][last];
	if(ret!=-1.0) return ret;
	if(n==0) return ret = M[last][classified[n]] *B[last];
	ret = 0;
	for(int i=0;i<m;++i){
		ret = max(ret, dp(n-1,i)*T[i][last]*M[last][classified[n]]);
	}
	return ret;
}
int main(){
	cin >> m >> q;
	for(int i=0;i<m;++i) cin >> word[i];
	for(int i=0;i<m;++i) cin >> B[i];
	for(int i=0;i<m;++i){
		for(int j=0;j<m;++j) cin >> T[i][j];
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<m;++j) cin >> M[i][j];
	}


	for(int test = 0; test<q;++test){
		fill_n(cache[0],50000,-1.0);
		int n;
		cin >> n;
		for(int i=0;i<n;++i){
			string str;
			cin >> str;
			for(int j=0;j<m;++j){
				if(word[j]==str){
					classified[i] = j;
					break;
				}
			}
		}
		double maximum = 0;
		int last;
		for(int i=0;i<m;++i){
			if(dp(n-1,i)>maximum){
				maximum = dp(n-1,i);
				last = i;
			}
		}
		backtracking(n-1,last);
		cout << endl;
	}
	return 0;
}