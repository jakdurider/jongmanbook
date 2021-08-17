#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,k,m;
int len[50];
double T[50][50];
vector<vector<double>> matmul(vector<vector<double>>& A, vector<vector<double>>& B){
	vector<vector<double>> ret(A.size());
	for(int i=0;i<A.size();++i){
		for(int j=0;j<B[0].size();++j){
			double total = 0.0;
			for(int each = 0; each<A[0].size();++each){
				total += A[i][each] * B[each][j];
			}
			ret[i].push_back(total);
		}
	}
	return ret;
}
vector<vector<double>> pow(vector<vector<double>>& A, int time){
	if(time==0){
		vector<vector<double>> ret(4*n);
		for(int i=0;i<4*n;++i){
			for(int j=0;j<4*n;++j){
				ret[i].push_back(i==j ? 1.0 : 0.0);
			}
		}
		return ret;
	}
	if(time % 2 == 1){
		vector<vector<double>> temp = pow(A,time-1);
		return matmul(temp,A);
	} 
	vector<vector<double>> half = pow(A,time/2);
	return matmul(half,half);
}
int main(){
	int C;
	cin >> C;
	cout << fixed;
	cout.precision(8);
	for(int test = 0; test < C; ++test){
		cin >> n >> k >> m;
		for(int i=0;i<n;++i){
			cin >> len[i];
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin >> T[i][j];
			}
		}
		vector<vector<double>> W(4*n);
		for(int i=0;i<4*n;++i){
			for(int j=0;j<4*n;++j){
				W[i].push_back(1.0);
				if(j!=i+n) W[i][j] = 1+i/n-j/n == len[j%n] && i>=3*n ? T[j%n][i%n] : 0.0;
			}
		}
		vector<vector<double>> kth_W = pow(W,k);	

		for(int i=0;i<m;++i){
			int prefer;
			cin >> prefer;
			double total = 0.0;
			for(int i=0;i<len[prefer];++i){
				total += kth_W[(3-i)*n+prefer][3*n];
			}
			cout << total << " ";
		}
		cout << endl;
	}
	return 0;
}
