/**
 * 生成指定长度的合法括号序列
 * 按顺序加入，保证合法的前提下随机选取
 */
#include<random>
#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
ll rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
int n,l,r,alpha;
string get_seq(){
    string res;
    for(int i=1;i<=n;i++){
        if(l<n/2&&r<l)
            res.push_back(rnd(0,100)<=alpha?'(':')');
        else if(l<n/2) res.push_back('(');
        else res.push_back(')');
        if(res.back()=='(') ++l;
        else ++r;
    }
    return res;
}
int main(){
    ofstream out("1.in");
    n=1e6;//生成的括号序列长度为 n
    alpha=70;//当加入左右括号都合法时选择左括号的概率（百分数）
    //alpha 值的增大能有效提升嵌套层数
    assert(n%2==0);
    assert(alpha>=0&&alpha<=100);
    out<<get_seq()<<'\n';
    return 0;
}
