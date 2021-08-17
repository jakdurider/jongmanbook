#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int len[100];
int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C;++test){
		int n;
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> len[i];
		}
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i=0;i<n;++i){
			pq.push(len[i]);
		}
		int total = 0;
		while(pq.size() > 1){
			int min1 = pq.top(); pq.pop();
			int min2 = pq.top(); pq.pop();
			pq.push(min1+min2);
			total += min1+min2;
		}
		cout << total << endl;
	}
	return 0;
}
