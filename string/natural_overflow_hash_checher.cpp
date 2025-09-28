#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
typedef unsigned long long ull;
string s1,s2;
ull h1,h2;
int base;
int main(){
    freopen("1.in","r",stdin);
//    base=224;
    base=131;
    cin>>s1>>s2;
    for(int i=0;i<int(s1.length());i++)
        h1=h1*base+s1[i];
    for(int i=0;i<int(s2.length());i++)
        h2=h2*base+s2[i];
    assert(h1==h2&&s1!=s2);
    return 0;
}
