#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
short cache[1<<25];
short win(int bits){
	short& ret = cache[bits];
	if(ret!=-1) return ret;
	ret = 0;
	for(int i=0;i<25;++i){
		if(bits & 1<<i){
			bits ^= 1<<i;
			if(i+1<25 && i%5!=4 && bits & 1<<i+1){
				bits ^= 1<<i+1;
				if(!win(bits)) return ret = 1;
				if(i-5>=0 && i/5!=0 && bits & 1<<i-5){
					bits ^= 1<<i-5;
					if(!win(bits)) return ret = 1;
					bits |= 1<<i-5;
				}
				if(i+5<25 && i/5!=4 && bits & 1<<i+5){
					bits ^= 1<<i+5;
					if(!win(bits)) return ret = 1;
					bits |= 1<<i+5;
				}
				bits |= 1<<i+1;
			}
			if(i+5<25 && i/5!=4 && bits & 1<<i+5){
				bits ^= 1<<i+5;
				if(!win(bits)) return ret = 1;	
				if(i-1>=0 && i%5!=0 && bits & 1<<i-1){
					bits ^= 1<<i-1;
					if(!win(bits)) return ret = 1;
					bits |= 1<<i-1;
				}
				bits |= 1<<i+5;
			}
			if(i-1>=0 && i%5!=0 && bits & 1<<i-1){
				bits ^= 1<<i-1;	
				if(i-5>=0 && i/5!=0 && bits & 1<<i-5){
					bits ^= 1<<i-5;
					if(!win(bits)) return ret = 1;
					bits |= 1<<i-5;
				}
				bits |= 1<<i-1;
			}
			bits |= 1<<i;
		}
	}
	return ret;
}
int main(){
	int C;
	cin >> C;
	memset(cache,-1,sizeof(cache));
	for(int test=0;test<C;++test){
		int initial = 0;
		for(int i=0;i<5;++i){
			string str;
			cin >> str;
			for(int j=0;j<5;++j){
				if(str[j]=='.') initial |= 1<<i*5+j;
			}
		}
		if(win(initial)==1) cout << "WINNING" << endl;
		else cout << "LOSING" << endl;
	}
	return 0;
}
