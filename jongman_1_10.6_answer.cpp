#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const double pi = 2.0*acos(0);
const int INF = 987654321;
int n;
double y[100];
double x[100];
double r[100];
pair<double,double> range[100];
int solvelinear(double begin, double end){	
	if(begin >= end) return 0;
	double maxcover = -1.0;
	for(int i=0;i<n;++i){
		if(range[i].first <= begin){
			if(range[i].second >= maxcover){
				maxcover = range[i].second;
			}
		}	
	}
	if(maxcover <= begin) return INF;
	return 1+solvelinear(maxcover,end);
}
int solveCircular(){
	int ret = INF;
	for(int i=0;i<n;++i){
		if(range[i].first<=0.0 || range[i].second>=2*pi){
			double begin = fmod(range[i].second,2*pi);
			double end = fmod(range[i].first+2*pi, 2*pi);
			ret = min(ret, 1+solvelinear(begin,end));
		}
	}

	return ret;
}
int main(){
	int C;
	cin >> C;
	for(int test = 0; test < C;++test){
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> y[i] >> x[i] >> r[i];
		}
		for(int i=0;i<n;++i){
			double loc = fmod(2*pi+atan2(y[i],x[i]),2*pi);
			double ran = 2.0 * asin(r[i]/16.0);
			range[i] = make_pair(loc-ran,loc+ran);
		}
		sort(range, range+n);
		int ret = solveCircular();
		if(ret >= INF) cout << "IMPOSSIBLE" << endl;
		else cout << ret << endl;
		
	}
	return 0;
}
