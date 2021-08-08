#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int MAX = 1000;
int k;
int cache[1<<15][15];
int choice[1<<15][15];
int con[15][15];
vector<string> str;
string str_input[15];
void backtracking(unsigned int taken, int last){
	if(taken){
		int before = choice[taken][last];
		backtracking(taken^(1<<before),before);
		if(con[before][last]!=0) cout << str[last].substr(str[last].size()-con[before][last],con[before][last]);
	}
	else{
		cout << str[last];
	}
}

int dp(unsigned int taken, int last){
	int& ret = cache[taken][last];
	if(ret != -1) return ret;
	if(taken == 0) return ret = str[last].size();
	else{
		ret = MAX;
		int minindex = -1;
		for(int i=0;i<k;++i){
			if((taken&(1<<i)) && dp(taken^(1<<i),i) + con[i][last] < ret){
				ret = dp(taken^(1<<i),i) + con[i][last];
				minindex = i;
			}
		}
		choice[taken][last] = minindex;
		return ret;
	}
}

int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C; ++test){
		memset(cache,-1,sizeof(cache));
		vector<string> temp;
		str = temp;
		cin >> k;
		for(int i=0;i<k;++i) {
			cin >> str_input[i];
		}
		for(int i=0;i<k;++i){
			bool inclusive = false;
			for(int j=0;j<k;++j){	
				if(i!=j && (str_input[j].find(str_input[i]) != string::npos)){
					inclusive = true; 
					break;
				} 
			}
			if(!inclusive) str.push_back(str_input[i]);
		}

		k = str.size();
		for(int i=0;i<k;++i){
			for(int j=0;j<k;++j){
				if(i==j) con[i][j] = 0;
				else{
					int min_length = min(str[i].size(),str[j].size());
					int length = min_length-1;
					while(length>0){
						if(str[i].substr(str[i].size()-length,length) == str[j].substr(0,length)) break;
						--length;
					}
					con[i][j] = str[j].size() - length;
				}
			}
		}
		int minimum = MAX;
		int minindex = -1;
		for(int i=0;i<k;++i){
			if(dp((1<<k)-1,i) < minimum) {
				minimum = dp((1<<k)-1,i);
				minindex = i;
			}
		}
		backtracking((1<<k)-1,minindex);
		cout << endl;
	}
	return 0;
}