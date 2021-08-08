#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int mod = 1000000007;
int cache[1<<14][20][2];
int digits[14];
int e_size;
string e;
int m;
int egg(int index, int taken, int remain, bool already){
	int& ret = cache[taken][remain][already];
	if(ret != -1) return ret;
	if(index == e_size){
		if(remain == 0 && already) return ret = 1;
		else return ret = 0;
	}
	ret = 0;
	int current = -1;
	for(int i=0;i<e_size;++i){
		if(!already && digits[i] > e[index]-48) break;
		bool each_taken = taken & (1<<i);
		if(!each_taken && (current != digits[i])){
			current = digits[i];
			int nexttaken = taken | (1<<i);
			int nextremain = ((remain*10) + current) % m;
			bool nextalready = already | (current < e[index]-48);
			ret += egg(index+1,nexttaken,nextremain,nextalready);
			ret %= mod;
		}
	}
	return ret;
}
int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C; ++test){
		memset(cache,-1,sizeof(cache));
		cin >> e;
		cin >> m;
		e_size = e.size();
		for(int i=0;i<e_size;++i){
			digits[i] = int(e[i]) - 48;
		}
		sort(digits,digits+e_size);
		cout << egg(0,0,0,0) << endl;
	}
	return 0;
}