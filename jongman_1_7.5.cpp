#include <iostream>
#include <algorithm>
using namespace std;
int fence[20000];
int solve(int left, int right){     // solve [left,right] fence
    if(left==right) return fence[left];
    else{
        int mid = (left+right)/2;
        int left_max = solve(left,mid);
        int right_max = solve(mid+1,right);
        int width = 2;
        int middle_max = min(fence[mid],fence[mid+1]) * width;
        int minheight = min(fence[mid],fence[mid+1]);
        int left_end = mid-1;
        int right_end = mid+2;
        while(left <= left_end && right_end <= right){
            ++width;
            int left_rect = min(minheight, fence[left_end]) * width;
            int right_rect = min(minheight, fence[right_end]) * width;
            if(left_rect >= right_rect){
                if(left_rect > middle_max){
                    minheight = min(minheight, fence[left_end]);
                    middle_max = left_rect;
                }
                --left_end;
            }
            else{
                if(right_rect > middle_max){
                    minheight = min(minheight, fence[right_end]);
                    middle_max = right_rect;
                }
                ++right_end;
            }
        }
        if(left_end == left-1){ // left is ended
            int right_minheight = fence[right_end];
            while(right_end < right){
                ++width;
                right_minheight = min(right_minheight, fence[right_end]);
                int right_rect = min(minheight, right_minheight) * width;
                if(right_rect > middle_max){
                    minheight = min(minheight, fence[right_end]);
                    middle_max = right_rect;
                }
                ++right_end;
            }
        }  
        else{  // right is ended
            int left_minheight = fence[left_end];
            while(left <= left_end){
                ++width;
                left_minheight = min(left_minheight, fence[left_end]);
                int left_rect = min(minheight, left_minheight) * width;
                if(left_rect > middle_max){
                    minheight = min(minheight, fence[left_end]);
                    middle_max = left_rect;
                }
                --left_end;
            }
        }

        return max(max(right_max,left_max),middle_max);
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