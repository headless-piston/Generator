/*
* 生成期望树高 O(sqrtn) 级别的树
* 生成方法：随机生成一个 Prüfer 序列，根据此构造一棵树
* 打乱方法：对所有点重新随机编号
*/
#include<random>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<queue>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
int rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
constexpr int N=1e7+10;
int n,p[N],deg[N];
struct edge{int u,v;};
vector<int> prufer;
vector<edge> e;
priority_queue<int,vector<int>,greater<int>> leaf;
void prufer_decoding(){
    for(int i=1;i<=n;i++) deg[i]=1;
    for(int &v:prufer) ++deg[v];
    for(int i=1;i<=n;i++) if(deg[i]==1) leaf.push(i);
    for(int &v:prufer){
        int u=leaf.top();
        leaf.pop();
        e.push_back({u,v});
        --deg[u],--deg[v];
        if(deg[v]==1) leaf.push(v);
    }
    vector<int> remain;
    for(int i=1;i<=n;i++) if(deg[i]==1) remain.push_back(i);
    e.push_back({remain[0],remain[1]});
}
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
    out<<n<<'\n';
    for(int i=1;i<=n-2;i++) prufer.push_back(rnd(1,n));//随机生成 Prüfer 序列
    prufer_decoding();//根据 Prüfer 序列还原树
//    shuf();//随机打乱
    for(edge &x:e)
        out<<x.u<<' '<<x.v<<'\n';
    return 0;
}
/*
* n=1e5：
* --若不调用 shuf，平均高度在 380~500 之间浮动，有时会有下至 200，上至 700 的极端情况
*/
