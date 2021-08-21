#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int h,w,r,c;
vector<vector<pair<int,int>>> rotations;
int blocksize;
int covered[10][10];
int best;
vector<string> board;
vector<string> original_block;

vector<string> rotate(vector<string>& origin){
	vector<string> ret(origin[0].size(),string(origin.size(),' '));
	for(int i=0;i<ret.size();++i){
		for(int j=0;j<ret[0].size();++j){
			ret[i][j] = origin[j][origin[0].size()-1-i];
		}
	}
	return ret;
}

void generateRotations(vector<string> block){
	rotations.clear();
	rotations.resize(4);
	for(int rot = 0; rot<4;++rot){
		int originY = -1, originX = -1;
		for(int i=0;i<block.size();++i){
			for(int j=0;j<block[i].size();++j){
				if(block[i][j] == '#'){
					if(originY == -1){
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i-originY,j-originX));
				}
			}
		}
		block = rotate(block);
	}
	sort(rotations.begin(),rotations.end());
	rotations.erase(unique(rotations.begin(),rotations.end()),rotations.end());
	blocksize = rotations[0].size();
}

bool set(int y, int x, vector<pair<int,int>>& block, int delta){
	if(delta == 1){
		bool possible = true;
		for(int i=0;i<block.size();++i){
			int set_y = y + block[i].first;
			int set_x = x + block[i].second;
			if(set_y>=0 && set_y<h && set_x>=0 && set_x<w){
				if(covered[set_y][set_x]){
					possible = false;
					break;
				}
			}
			else{
				possible = false;
				break;
			}
		}
		if(possible){
			for(int i=0;i<block.size();++i){
				int set_y = y + block[i].first;
				int set_x = x + block[i].second;
				covered[set_y][set_x] = true;
			}
		}
		return possible;
	}
	else{
		for(int i=0;i<block.size();++i){
			int set_y = y + block[i].first;
			int set_x = x + block[i].second;
			covered[set_y][set_x] = false;
		}
		return false;
	}
}

void search(int placed){
	int y = -1, x = -1;
	
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			if(!covered[i][j]){
				y = i;
				x = j;
				break;
			}
		}
		if(y!=-1) break;
	}
	int blank = 0;
	for(int j=x;j<w;++j){
		if(!covered[y][j]) ++blank;
	}
	for(int i=y+1;i<h;++i){
		for(int j=0;j<w;++j){
			if(!covered[i][j]) ++blank;
		}
	}
	if(placed + blank/blocksize < best) return;
	if(y==-1){
		best = max(best,placed);
		return;
	}
	for(int i=0;i<rotations.size();++i){
		if(set(y,x,rotations[i],1)) {
			search(placed+1);
			set(y,x,rotations[i],-1);
		}
	}
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;

}

int main(){
	int T;
	cin >> T;
	for(int test = 0; test < T; ++test){
		memset(covered,0,sizeof(covered));
		board.clear();
		rotations.clear();
		original_block.clear();
		cin >> h >> w >> r >> c;
		best = 0;
		for(int i=0;i<h;++i){
			string str;
			cin >> str;
			board.push_back(str);
		}
		for(int i=0;i<r;++i){
			string str;
			cin >> str;
			original_block.push_back(str);
		}
		generateRotations(original_block);
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				covered[i][j] = (board[i][j]=='#');
			}
		}
		search(0);
		cout << best << endl;
	}
	return 0;
}
