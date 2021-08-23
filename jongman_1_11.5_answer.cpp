#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m;
string name[50];
vector<int> food_caneat[50], eaters[50];
int best;
void search(vector<int>& edible,int chosen){
	if(chosen >= best) return;
	int first = 0;
	while(first < n && edible[first]>0) ++first;
	if(first==n){
		best = chosen;
		return;
	}
	for(int i=0;i<food_caneat[first].size();++i){
		int food = food_caneat[first][i];
		for(int j=0;j<eaters[food].size();++j){
			++edible[eaters[food][j]];
		}
		search(edible,chosen+1);
		for(int j=0;j<eaters[food].size();++j){
			--edible[eaters[food][j]];
		}
	}
}
int main(){
	int T;
	cin >> T;
	for(int test = 0; test < T; ++test){
		cin >> n >> m;
		best = m+1;
		for(int i=0;i<n;++i){
			food_caneat[i].clear();
		}
		for(int i=0;i<m;++i){
			eaters[i].clear();
		}
		for(int i=0;i<n;++i){
			cin >> name[i];
		}
		for(int i=0;i<m;++i){
			int num;
			cin >> num;
			long long total = 0;
			for(int j=0;j<num;++j){
				string str;
				cin >> str;
				auto itr = find(name,name+n,str);
				int dist = distance(name,itr);
				food_caneat[dist].push_back(i);
				eaters[i].push_back(dist);
			}
		}
		vector<int> edible(n,0);
		search(edible,0);
		cout << best << endl;
	}
	return 0;
}
