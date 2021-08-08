#include <iostream>
#include <algorithm>
using namespace std;
int fence[20000];
int solve(int left, int right){     // solve [left,right] fence
    if(left==right) return fence[left];
    else{
        int mid = (left+right)/2;
        int ret = max(solve(left,mid),solve(mid+1,right));
        int lo = mid, hi = mid+1;
        int height = min(fence[lo],fence[hi]);
        while(left < lo || hi < right){
            if(hi < right && (left == lo || fence[hi+1]>fence[lo-1])){
                height = min(fence[hi+1],height);
                
                ++hi;
            }
            else{
                height = min(fence[lo-1],height);
                
                --lo;
            }
            ret = max(ret, (hi-lo+1)*height);
        }

        return ret;
    }
    
}

int main()
{
    int C;
    cin >> C;
    for(int test = 0;test<C;++test){
        int n;
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> fence[i];
        }
        cout << solve(0,n-1) << endl;
    }

    return 0;
}