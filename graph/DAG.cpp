/**
 * 生成随机有向无环图
 * 生成方法：随机生成 m 条边 (u,v)，保证 u<v，再随机打乱
 * 打乱方法：对所有点重新随机编号
 */
#include<random>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
ll rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
constexpr int N=1e6+10;
int n,m,p[N];
struct edge{
    int u,v;
    bool operator<(const edge &x)const{
        return u==x.u?v<x.v:u<x.u;
    }
}e[N];
set<edge> st;
void shuf(){
    for(int i=1;i<=n;i++) p[i]=i;
    shuffle(p+1,p+1+n,getrnd);
    for(int i=1;i<=m;i++){
        e[i].u=p[e[i].u];
        e[i].v=p[e[i].v];
    }
}
int main(){
    ofstream out("1.in");
    n=1e4;//节点数
    m=2e5;//边数
    out<<n<<' '<<m<<'\n';
    for(int i=1,u,v;i<=m;i++){
        while(1){
            u=rnd(1,n),v=rnd(1,n);
            if(u==v) continue;
            if(u>v) swap(u,v);
            if(st.find({u,v})==st.end()) break;
        }
        st.insert({u,v});
        e[i]={u,v};
    }
    shuf();
    for(int i=1;i<=m;i++)
        out<<e[i].u<<' '<<e[i].v<<'\n';
    return 0;
}
