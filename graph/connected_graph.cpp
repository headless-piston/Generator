/*
* 生成随机连通图（弱连通，无重边、自环，不可用于生成稠密图）
* 生成方法：随机生成一棵树，然后在树上随机加边
* 打乱方法：对所有点重新随机编号
*/
#include<random>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
int rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
constexpr int N=1e7+10;
int n,m,p[N];
struct edge{
    int u,v;
    bool operator<(const edge &x)const{
        return u==x.u?v<x.v:u<x.u;
    }
};
vector<edge> e;
set<edge> st;
void shuf(){
    for(int i=1;i<=n;i++) p[i]=i;
    shuffle(p+1,p+1+n,getrnd);
    for(edge &x:e){
        x.u=p[x.u];
        x.v=p[x.v];
    }
}
int main(){
    ofstream out("1.in");
    n=1e5;//节点数
    m=2e5;//边数
    out<<n<<' '<<m<<'\n';
    for(int i=2;i<=n;i++){
        st.insert({i,rnd(1,i-1)});
        e.push_back({i,rnd(1,i-1)});
    }
    for(int i=n;i<=m;i++){
        int u,v;
        while(1){
            u=rnd(1,n),v=rnd(1,n);
            if(u==v) continue;
            if(u>v) swap(u,v);
            if(st.insert({u,v}).second) break;
        }
        if(rnd(0,1)) swap(u,v);
        e.push_back({u,v});
    }
    shuf();//随机打乱
    for(edge &x:e)
        out<<x.u<<' '<<x.v<<'\n';
    return 0;
}
