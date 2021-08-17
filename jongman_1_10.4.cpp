#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C;++test){
		int n;
		cin >> n;
		vector<int> len(n);
		for(int i=0;i<n;++i){
			cin >> len[i];
		}
		sort(len.begin(),len.end());
		int total = 0;
		while(len.size() > 1){
			int temp = len[0]+len[1];
			total += len[0] + len[1];
			len.erase(len.begin());
			len.erase(len.begin());
			vector<int>::iterator it;
			for(it=len.begin(); it!=len.end(); ++it){
				if(temp<(*it)) break;
			}
			len.insert(it,temp);	
		}
		cout << total << endl;
	}
	return 0;
}
