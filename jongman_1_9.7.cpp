#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int C,n,k;
int length_cache[501];
int count_cache[501];
int arr[501];
void kth_lis(int& length,int choice,map<int,int>& index){
	if(k<0) return;
	vector<int> vec;
	for(int i=index[choice]+1;i<n+1;++i){
		if(length_cache[i] == length && arr[index[choice]] < arr[i]){
			vec.push_back(arr[i]);
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();++i){
		if(k>count_cache[index[vec[i]]]) k -= count_cache[index[vec[i]]];
		else{
			cout << vec[i] << " ";
			kth_lis(--length, vec[i],index);	
			break;
		}
	}
}

int lis_length(int start){
	int& ret = length_cache[start];
	if(ret!=-1) return ret;
	ret = 1;
	for(int i=start+1;i<n+1;++i){
		if(arr[start] < arr[i]) ret = max(ret,1+lis_length(i));
	}
	return ret;
}

int lis_count(int start){
	int& ret = count_cache[start];
	if(ret!=-1) return ret;
	ret = 0;
	int index = start;
	for(int i=start+1;i<n+1;++i){
		if(arr[start] < arr[i]){
			ret = lis_count(i);
			index = i;
			break;
		}
	}
	for(int i=index+1;i<n+1;++i){
		if(arr[index] > arr[i] && arr[i] > arr[start]){
			ret += lis_count(i);
		}
	}
	if(ret == 0) ret = 1;
	return ret;
}

int main(){
	cin >> C;
	for(int test = 0; test < C; ++test){
		memset(length_cache,-1,sizeof(length_cache));
		memset(count_cache,-1,sizeof(count_cache));
		cin >> n >> k;
			
		map<int,int> index;
		arr[0] = 0;
		index.insert(map<int,int>::value_type(0,0));
		for(int i=1;i<n+1;++i){
			cin >> arr[i];
			index.insert(map<int,int>::value_type(arr[i],i));
		}
		lis_count(0);
		cout << lis_length(0)-1 << endl;
		cout << "Length_Cache : ";
		for(int i=1;i<n+1;++i){
			cout << length_cache[i] << " ";
		}
		cout << endl;
		cout << "Count_Cache : ";
		for(int i=1;i<n+1;++i){
			cout << count_cache[i] << " ";
		}
		cout << endl;
		int maximum = lis_length(0)-1;
		kth_lis(maximum,0,index);
		cout << endl;
	}
	return 0;
}