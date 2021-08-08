#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[101][101];
int A[100];
int B[100];
int n,m;
const long long NEGINF = numeric_limits<long long>::min();
int jlis(int indexA, int indexB){
    int& ret = cache[indexA+1][indexB+1];
    if(ret!=-1) return ret;
    ret = 2;
    
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    
    long long front = max(a,b);
    
    for(int nextA = indexA + 1; nextA < n; ++nextA){
        if(A[nextA] > front){
            ret = max(ret , jlis(nextA, indexB) + 1);
        }
    }
    for(int nextB = indexB + 1; nextB < m; ++nextB){
        if(B[nextB] > front){
            ret = max(ret , jlis(indexA, nextB) + 1);
        }
    }
    
    return ret;
}
int main()
{
    int testcase;
    cin >> testcase;
    for(int test = 0; test < testcase; ++test){
        memset(cache, -1, sizeof(cache));
        cin >> n >> m;
        for(int i=0;i<n;++i){
            cin >> A[i];
        }
        for(int i=0;i<m;++i){
            cin >> B[i];
        }
        
        cout << jlis(-1,-1)-2 <<endl;  // at front of JLIS : (-inf, -inf)
        
    }
    return 0;
}