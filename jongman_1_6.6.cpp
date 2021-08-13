#include <iostream>
#include <string>
using namespace std;

int total;
const int cen_dx[4] = {-1,-1,1,1};
const int cen_dy[4] = {-1,1,-1,1};
const int side_dx[8] = {-1,1,-1,1,-1,1,-1,1};
const int side_dy[8] = {1,1,-1,-1,-1,-1,1,1};
void solve(bool** covered, int h, int w){
    int x = -1;
    int y = -1;

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(!covered[i][j]){
                x = j; y = i; break;
            }
        }
        if(x!=-1) break;
    }    
    
    if(x==-1) ++total;
    else{
        for(int i=0;i<4;++i){
            int another_x = x+cen_dx[i];
            int another_y = y+cen_dy[i];
            if(another_x>=0 && another_x < w && another_y>=0 && another_y < h && !covered[another_y][x] && !covered[y][another_x]){
                
                covered[y][x] = true;
                covered[another_y][x] = true;
                covered[y][another_x] = true;
                solve(covered,h,w);
                covered[y][x] = false;
                covered[another_y][x] = false;
                covered[y][another_x] = false;
                
            }
        }
        for(int i=0;i<8;++i){
            int another_x = x+side_dx[i];
            int another_y = y+side_dy[i];
            if(i<4){
                if(another_x>=0 && another_x < w && another_y>=0 && another_y < h && !covered[another_y][another_x] && !covered[another_y][x]){
                
                    covered[y][x] = true;
                    covered[another_y][another_x] = true;
                    covered[another_y][x] = true;
                    solve(covered,h,w);
                    covered[y][x] = false;
                    covered[another_y][another_x] = false;
                    covered[another_y][x] = false;
                    
                } 
            }
            else{
                if(another_x>=0 && another_x < w && another_y>=0 && another_y < h && !covered[another_y][another_x] && !covered[y][another_x]){
                
                    covered[y][x] = true;
                    covered[another_y][another_x] = true;
                    covered[y][another_x] = true;
                    solve(covered,h,w);
                    covered[y][x] = false;
                    covered[another_y][another_x] = false;
                    covered[y][another_x] = false;
                    
                }
            }
            
        }
    }
}

int main()
{
    int C;
    cin >> C;
    for(int test=0;test<C;++test){
        total = 0;
        int h,w;
        cin >> h >> w;
        bool ** covered = new bool* [h];
        for(int i=0;i<h;++i){
            covered[i] = new bool[w];
        }
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                covered[i][j] = false;
            }
        }
        for(int i=0;i<h;++i){
            string str;
            cin >> str;
            for(int j=0;j<w;++j){
                if(str[j] == '#') covered[i][j] = true;
            }
        }
        solve(covered,h,w);
        cout << total << endl;
        for(int i=0;i<h;++i){
            delete[] covered[i];
        }
        delete[] covered;
    }

    return 0;
}
