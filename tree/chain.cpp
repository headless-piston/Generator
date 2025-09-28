/*
* 生成一条链
* 生成方法：钦定 1 为根，对于后续的节点 i，令 i-1 作为它的父亲
* 打乱方法：对所有点重新随机编号
*/
#include<random>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
int rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
constexpr int N=1e7+10;
int n,p[N];
struct edge{int u,v;};
vector<edge> e;
void shuf(){
    for(int i=1;i<=n;i++) p[i]=i;
    shuffle(p+1,p+1+n,getrnd);
    for(edge &x:e){
        x.u=p[x.u];
        x.v=p[x.v];
    }
    shuffle(e.begin(),e.end(),getrnd);
}
int main(){
    ofstream out("1.in");
    n=1e5;//节点数
    out<<n<<'\n';
    for(int i=2;i<=n;i++)
        e.push_back({i,i-1});
    shuf();//随机打乱
    for(edge &x:e)
        out<<x.u<<' '<<x.v<<'\n';
    return 0;
}
