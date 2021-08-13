#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int cache[10000001];
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
			int each_price;
			cin >> each_price;
			price[i] = each_price/100;
			cin >> prefer[i];
		}
		for(int i=0;i<=m;++i){
			cache[i] = (i/price[0])*prefer[0];
		}
		for(int i=1;i<n;++i){
			for(int j=price[i];j<=m;++j){
				cache[j] = max(cache[j],cache[j-price[i]]+prefer[i]);
			}
		}
		cout << cache[m] << endl;
	}
	return 0;
}
