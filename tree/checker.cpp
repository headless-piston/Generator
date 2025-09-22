//用于检测生成的树是否合法和计算平均树高
#include<cstdio>
#include<vector>
#include<cassert>
#include<random>
using namespace std;
template<typename T>
inline void read(T &x){
    bool f=0;x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    if(f) x=~x+1;
}
template<typename T,typename...Args>
void read(T &x,Args &...args){read(x);read(args...);}
typedef long long ll;
constexpr int N=1e5+10;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
int rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
int n,dep[N];
vector<int> e[N];
bool vis[N];
void dfs(int u,int f){
    vis[u]=1;
    dep[u]=dep[f]+1;
    for(int &v:e[u]){
        if(v==f) continue;
        assert(!vis[v]);
        dfs(v,u);
    }
}
int main(){
    freopen("1.in","r",stdin);
    read(n);
    for(int i=1,u,v;i<n;i++){
        read(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
//    dfs(rnd(1,n),0);
    dfs(1,0);
    for(int i=1;i<=n;i++) assert(vis[i]);
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=dep[i];
    printf("%lf\n",1.0*sum/n);
    return 0;
}
