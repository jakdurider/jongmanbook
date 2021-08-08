#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
long long skip;

char pth_char(string& str, int generation){
	if(generation==0) return str[skip];
	for(int i=0;i<str.size();++i){
		if(str[i] == 'X' || str[i] == 'Y'){
			long long length = 3*(long long)pow(2,generation)-2;
			if(skip >= length) skip -= length;
			else if(str[i] == 'X'){
				string seed = "X+YF";
				return pth_char(seed, generation-1);
			}
			else{
				string seed = "FX-Y";
				return pth_char(seed, generation-1);
			}
		}
		else if(skip > 0) --skip;
		else return str[i];
	}
	return '%';
}

int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C; ++test){
		long long n,p,l;
		cin >> n >> p >> l;
		for(int i=p-1;i<p+l-1;++i){
			skip = i;
			string seed = "FX";
			cout << pth_char(seed,n);
		}
		cout << endl;
	}
	return 0;
}