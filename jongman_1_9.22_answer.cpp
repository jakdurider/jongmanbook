#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int cache[201];
int price[20];
int prefer[20];

int main(){
	int C;
	cin >> C;
	for(int test=0;test<C;++test){
		int n,m;
		cin >> n >> m;
		m = m/100;
		for(int i=0;i<n;++i){
			cin >> price[i] >> prefer[i];
			price[i] /= 100;
		}
		int ret = 0;
		cache[0] = 0;
		for(int budget = 1;budget<=m;++budget){
			int cand = 0;
			for(int dish = 0;dish<n;++dish){
				if(budget >= price[dish]){
					cand = max(cand, cache[(budget-price[dish])%201]+prefer[dish]);
				}
			}
			cache[budget%201] = cand;
			ret = max(ret,cand);
		}
		cout << ret << endl;
	}
	return 0;
}
