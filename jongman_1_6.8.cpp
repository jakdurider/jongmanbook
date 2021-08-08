#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minimum;
void rotate(vector<int>& clk, vector<vector<int>>& vec, int button){
    vector<int>& clocks = vec[button];
    for(int i=0;i<clocks.size();++i){
        clk[clocks[i]] += 3;
        if(clk[clocks[i]]>12) clk[clocks[i]] -= 12;
    }
}
void solve(vector<int>& clk, vector<vector<int>>& vec, int button, int total){
    if(button == 10){
        bool correct = true;
        for(int i=0;i<16;++i){
            if(clk[i]!=12){
                correct = false; break;
            }
        }
        if(correct) {
            minimum = min(total, minimum);
        }
    }
    else{
        solve(clk,vec,button+1,total);
        rotate(clk,vec,button);
        solve(clk,vec,button+1,total+1);
        rotate(clk,vec,button);
        solve(clk,vec,button+1,total+2);
        rotate(clk,vec,button);
        solve(clk,vec,button+1,total+3);
        rotate(clk,vec,button);
    }
}
int main()
{
    vector<vector<int>> button(10);
    button[0].push_back(0); button[0].push_back(1); button[0].push_back(2);
    button[1].push_back(3); button[1].push_back(7); button[1].push_back(9); button[1].push_back(11);
    button[2].push_back(4); button[2].push_back(10); button[2].push_back(14); button[2].push_back(15);
    button[3].push_back(0); button[3].push_back(4); button[3].push_back(5); button[3].push_back(6); button[3].push_back(7);
    button[4].push_back(6); button[4].push_back(7); button[4].push_back(8); button[4].push_back(10); button[4].push_back(12);
    button[5].push_back(0); button[5].push_back(2); button[5].push_back(14); button[5].push_back(15);
    button[6].push_back(3); button[6].push_back(14); button[6].push_back(15);
    button[7].push_back(4); button[7].push_back(5); button[7].push_back(7); button[7].push_back(14); button[7].push_back(15);
    button[8].push_back(1); button[8].push_back(2); button[8].push_back(3); button[8].push_back(4); button[8].push_back(5);
    button[9].push_back(3); button[9].push_back(4); button[9].push_back(5); button[9].push_back(9); button[9].push_back(13);
    int C;
    cin >> C;
    for(int test=0;test<C;++test){
        vector<int> clk;
        minimum = 987654321;
        for(int i=0;i<16;++i){
            int t;
            cin >> t;
            clk.push_back(t);
        }
        solve(clk,button,0,0);
        if(minimum == 987654321) cout << -1 << endl;
        else cout<<minimum<<endl;
        
    }
    
    return 0;
}