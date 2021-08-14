#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;
int m[10000];
int e[10000];
int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C;++test){
		int n;
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> m[i];
		}
		for(int i=0;i<n;++i){
			cin >> e[i];
		}
		vector<pair<int,int>> order;
		for(int i=0;i<n;++i){
			order.push_back(make_pair(e[i],m[i]));
		}
		sort(order.begin(),order.end());
		int start = 0;
		int maximum = 0;
		for(int i=n-1;i>=0;--i){
			start += order[i].second;
			maximum = max(start+order[i].first,maximum);
		}
		cout << maximum << endl;
	}
	return 0;
}
