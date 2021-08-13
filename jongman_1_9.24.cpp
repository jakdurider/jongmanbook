#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;
int len[50];
int prefer[50];
double T[50][50];
double cache[5][50][4];
int main(){
	int C;
	cin >> C;
	cout << fixed;
	cout.precision(8);
	for(int test=0;test<C;++test){
		int n,k,m;
		cin >> n >> k >> m;
		for(int i=0;i<n;++i){
			cin >> len[i];
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin >> T[i][j];
			}
		}
		for(int i=0;i<m;++i){
			cin >> prefer[i];
		}
		memset(cache,0.0,sizeof(cache));
		for(int time=0;time<len[0];++time){
			cache[time][0][time] = 1.0;
		}
		for(int time=len[0];time<=k;++time){
			for(int current=0;current<n;++current){
				for(int duration = 0;duration<len[current];++duration){
					double& ret = cache[time%5][current][duration];
					ret = 0.0;
					for(int before=0;before<n;++before){
						if(time>=duration+1) ret += cache[(time-duration-1)%5][before][len[before]-1] * T[before][current];
					}
				}	
			}
		}
		for(int i=0;i<m;++i){
			double total = 0;
			for(int j=0;j<len[prefer[i]];++j){
				total += cache[k%5][prefer[i]][j];
			}
			cout << total << " ";
		}	
		cout << endl;
	}
	return 0;
}
