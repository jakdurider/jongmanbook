#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int total;
bool pairs[10][10]={0,};

void picnic(bool* taken, int student_num){
    int firstfree = -1;
    for(int i=0;i<student_num;++i){
        if(taken[i] == false){
            firstfree = i;
            break;
        }
    }
    if(firstfree == -1) ++total;
    else{
        for(int i=firstfree;i<student_num;++i){
            if(pairs[firstfree][i] == true && taken[i] == false){
                taken[firstfree] = true;
                taken[i] = true;
                picnic(taken,student_num);
                taken[i] = false;
                taken[firstfree] = false;
            }
        }
    }
    
}

int main()
{
    int C;
    int student_num, pair_num;
    cin >> C;
    for(int i=0;i<C;++i){
        total = 0;
        cin >> student_num >> pair_num;
        for(int i=0;i<pair_num;++i){
            int friend0, friend1;
            cin >> friend0 >> friend1;
            pairs[friend0][friend1] = true;
            pairs[friend1][friend0] = true;
        }
        bool * taken = new bool[student_num];
        for(int i=0;i<student_num;++i){
            taken[i] = false;
        }
        picnic(taken,student_num);
        
        
        cout<<total<<endl;
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                pairs[i][j] = false;
            }
        }
        delete[] taken;
    }
    return 0;
}