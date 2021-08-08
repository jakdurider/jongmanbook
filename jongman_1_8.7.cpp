#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string str;
int cache[10001];
int pi(int start, int size){
	char first = str[start];
	char second = str[start+1];
	if(first==second){
		for(int i=2;i<size;++i){
			if(str[start+i]!=first)	return 10;
			return 1;
		}
	} 
	else{
		int sub = second-first;
		for(int i=2;i<size;++i){
			if(str[start+i]-str[start+i-1] != sub){
				for(int j=2;j<size;++j){
					if(str[start+j]!=first) return 10;
					char temp = first;
					first = second;
					second = temp;
				}
				return 4;
			}
		}

		if(sub==1 || sub==-1) return 2;
		else return 5;
	}
}
int diff(int start){
	int& ret = cache[start];
	if(ret!=-1) return ret;
	if(start == str.size()) return ret = 0;
	if(start == str.size()-1) return ret = 50000;
	if(start == str.size()-2) return ret = 50000;
	ret = pi(start,3)+diff(start+3);
	ret = min(ret,pi(start,4)+diff(start+4));
	ret = min(ret,pi(start,5)+diff(start+5));
	return ret;
}
int main(){
	int testcase;
	cin >> testcase;
	for(int test=0;test<testcase;++test){
		memset(cache,-1,sizeof(cache));
		cin >> str;
		cout << diff(0) << endl;
	}
	return 0;
}