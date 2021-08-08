#include <iostream>
#include <string>
using namespace std;
string original;

int flip(int start){    // do flip and return size of piece
    if(original[start]!='x') return 1;
    else{
        int size[5];
        size[0] = 1;    // 'x'
        int total = 1;
        for(int i=0;i<4;++i){
            size[i+1] = flip(start + total);
            total += size[i+1];
        }
        string string_temp = original;
        string_temp.replace(start+1,size[3],original.substr(start+1+size[1]+size[2],size[3]));
        string_temp.replace(start+1+size[3],size[4],original.substr(start+1+size[1]+size[2]+size[3],size[4]));
        string_temp.replace(start+1+size[3]+size[4],size[1],original.substr(start+1,size[1]));
        string_temp.replace(start+1+size[3]+size[4]+size[1],size[2],original.substr(start+1+size[1],size[2]));
        original = string_temp;
        return total;
    }
}

int main()
{
    int C;
    cin >> C;
    for(int test = 0;test<C;++test){
        cin >> original;
        flip(0);
        cout << original << endl;
    }
    return 0;
}