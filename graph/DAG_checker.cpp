#include<queue>
#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
constexpr int N=1e5+10;
int n,m,indeg[N];
bool vis[N];
vector<int> e[N];
queue<int> q;
int main(){
    freopen("1.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        ++indeg[v];
    }
    for(int i=1;i<=n;i++) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(int &v:e[u])
            if(!--indeg[v]) q.push(v);
    }
    for(int i=1;i<=n;i++) assert(vis[i]);
    return 0;
}
