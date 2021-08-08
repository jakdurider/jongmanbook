#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
string str[51];
string& puzzle(int n){
	string& ret = str[n];
	if(ret != "") return ret;
	ret = puzzle(n-1);
	string temp;
	for(long long i = 3*(long long)(pow(2,n-2)) ; i < 3*(long long)(pow(2,n-1))-1 ; ++i){
		if(ret[i] != 'X' && ret[i]!= 'Y') temp.append(1,ret[i]);
		else if(ret[i] == 'X') temp.append("X+YF");
		else temp.append("FX-Y");
	}
	ret.append(1,'+');
	ret.append(temp);
	return ret;
}
void dp(int n,long long start,long long end){
	if(n==0) cout << str[0].substr(start,end-start+1);
	else{
		long long length = 3*(long long)(pow(2,n-1))-1;
		if(end < length) dp(n-1,start,end);
		else if(start < length && end >= length){
			dp(n-1,start,length-1);
			cout << puzzle(n).substr(length,end-length+1);
		}
		else{
			cout << puzzle(n).substr(start,end-start+1);
		}
	}
}
int main(){
	int C;
	cin >> C;
	str[0] = "FX";
	str[1] = "FX+YF";
	for(int test = 0; test < C; ++test){
		long long n,p,l;
		cin >> n >> p >> l;
		dp(n,p-1,p+l-2);
		cout << endl;
	}
	return 0;
}