#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
constexpr int N=1e5+10;
int n,cnt[3];
vector<int> e[N];
int main(){
    freopen("1.in","r",stdin);
    cin>>n;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        assert(e[i].size()<=2);
        ++cnt[e[i].size()];
    }
    assert(cnt[0]==0);
    assert(cnt[1]==2);
    assert(cnt[2]==n-2);
    return 0;
}
