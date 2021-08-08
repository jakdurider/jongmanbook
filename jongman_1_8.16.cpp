#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N,D,P,T,Q;
double cache[51][101];
double dp(int town, int day, vector<vector<int>>& edge){
	double& ret = cache[town][day];
	if(ret!=0) return ret;
	if(day==0){
		if(town == P) return ret = 1.0;
		else return ret = 0;
	}
	ret = 0;
	for(int i=0;i<edge[town].size();++i){
		ret += dp(edge[town][i],day-1,edge) / edge[edge[town][i]].size();
	}
	return ret;
}
int main(){
	int C;
	cin >> C;
	for(int test = 0; test<C; ++test){
		memset(cache,0,sizeof(cache));
		cin >> N;
		cin >> D;
		cin >> P;
		vector<vector<int>> edge;
		for(int i=0;i<N;++i){
			vector<int> vec;
			for(int j=0;j<N;++j){
				bool line;
				cin >> line;
				if(line) vec.push_back(j);
			}
			edge.push_back(vec);
		}
		cin >> T;
		cout << fixed;
		cout.precision(8);
		for(int i=0;i<T;++i){
			cin >> Q;
			cout << dp(Q,D,edge) << " ";
		}
		cout << endl;
	}
	return 0;
}