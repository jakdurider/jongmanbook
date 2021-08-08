#include <iostream>
#include <string>
using namespace std;
string original;

string flip(string::iterator& it){    // do flip and return piece string
    char head = *it;
    ++it;
    if(head!='x') return string(1,head);
    else{
        string upperleft = flip(it);
        string upperright = flip(it);
        string lowerleft = flip(it);
        string lowerright = flip(it);
        return string(1,'x') + lowerleft + lowerright + upperleft + upperright;
    }
}

int main()
{
    int C;
    cin >> C;
    for(int test = 0;test<C;++test){
        cin >> original;
        string::iterator it = original.begin();
        cout << flip(it) << endl;
        
    }
    return 0;
}