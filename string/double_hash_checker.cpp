#include<random>
#include<iostream>
#include<cassert>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
ll rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
int p1,p2,base1,base2;
int gethash(const string &s,int base,int p){
    ll res=0;
    for(char c:s) res=(res*base+c)%p;
    return res;
}
string x,y;
pair<int,int> h1,h2;
int main(){
    freopen("1.in","r",stdin);
    base1=131;
    base2=13331;
    p1=1e9+7;
    p2=998244353;
    cin>>x>>y;
    h1={gethash(x,base1,p1),gethash(x,base2,p2)};
    h2={gethash(y,base1,p1),gethash(y,base2,p2)};
    assert(x!=y&&h1==h2);
    return 0;
}
