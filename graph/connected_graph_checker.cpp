#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
using namespace std;
constexpr int N=1e5+10;
struct edge{int v,w;};
bool vis[N];
int n,m,cnt;
vector<edge> e[N];
void dfs(int u){
    ++cnt;
    vis[u]=1;
    for(auto &[v,w]:e[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}
int main(){
    freopen("1.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1);
    assert(cnt==n);
    return 0;
}
