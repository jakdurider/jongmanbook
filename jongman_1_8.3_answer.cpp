#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void normalize(vector<int>& vec){
    vec.push_back(0);
    for(int i=0;i<vec.size()-1;++i){
        if(vec[i]>=0){
            vec[i+1] += vec[i]/10;
            vec[i] = vec[i]%10;
        }
        else{
            int borrow = vec[i]/10 + 1;
            vec[i+1] -= borrow;
            vec[i] += borrow*10;
        }
    }
    while(vec.size() > 1 && vec.back() == 0) vec.pop_back();
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
 
    normalize(c);
    return c;
}

void addTo(vector<int>& a, vector<int>& b, int k){ // a += b*(10^k)
    int s = max(a.size(),b.size()+k);
    
    a.resize(s,0);
    b.resize(s,0);
    for(int i = 0;i < s-k ;++i) a[i+k] += b[i];
    
}

void sumFrom(vector<int>& a, vector<int>& b){   // a -= b; (a>=b)
    int s = max(a.size(),b.size());
 
    a.resize(s, 0);
    b.resize(s, 0);
 
    for (int i = 0; i < s; ++i) a[i] -= b[i];
}

vector<int> karatsuba(vector<int>& a, vector<int>& b){
    int an = a.size(), bn = b.size();
    if(an<bn) return karatsuba(b,a);
    if(an==0 || bn ==0) return vector<int>();
    if(an<50) return multiply(a,b);
    int half = an/2;
    vector<int> a0(a.begin(),a.begin()+half);
    vector<int> a1(a.begin()+half,a.end());
    vector<int> b0(b.begin(),b.begin()+min<int>(half,b.size()));
    vector<int> b1(b.begin()+min<int>(half,b.size()),b.end());
    // z2 = a1*b1
    vector<int> z2 = karatsuba(a1,b1);
    // z0 = a0*b0
    vector<int> z0 = karatsuba(a0,b0);
    // z1 = (a1*b0)+(a0*b1) = (a0+a1)*(b0+b1)-z0-z2
    addTo(a0,a1,0); addTo(b0,b1,0);
    vector<int> z1 = karatsuba(a0,b0);
    sumFrom(z1,z0); 
    sumFrom(z1,z2);
    vector<int> ret;
    addTo(ret,z0,0);
    addTo(ret,z2,half*2);
    addTo(ret,z1,half);
    
    return ret;
}

int hugs(string& members, string& fans){
    int N = members.size(); int M = fans.size();
    vector<int> A(N), B(M);
    for(int i=0;i<N;++i) A[i] = (members[i] == 'M');
    for(int i=0;i<M;++i) B[M-1-i] = (fans[i] == 'M');
    vector<int> C = karatsuba(A,B);
    int allHugs = 0;
    //do not normalize because lower side can make answer different
    for(int i=N-1;i<M;++i){
        if(C[i] == 0) ++allHugs;
    }
    return allHugs;
}
int main()
{
    int C;
    cin >> C;
    for(int test = 0; test < C; ++test){
        string members;
        string fans;
        cin >> members;
        cin >> fans;
        cout << hugs(members, fans) << endl;
    }
    

    return 0;
}