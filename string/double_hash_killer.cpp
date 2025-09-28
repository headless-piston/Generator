/*
* 生成两个不同的串，满足其在给定的 base 和 p 下双哈希值相同
* 生成方法：
* 期望 sqrt p1 个串对于 p1 出现哈希冲突
* 以使得 p1 冲突的两串作为字符集随机生成串使得 p2 产生冲突
*/
#include<random>
#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
ll rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
int p1,p2,base1,base2;
int gethash(const string &s,int base,int p){//根据哈希方式动态调整
    ll res=0;
    for(char c:s) res=(res*base+c)%p;
    return res;
}
unordered_map<int,string> h1,h2;
string rndstr1(int len){
    string res;
    for(int i=1;i<=len;i++) res.push_back(rnd('a','z'));
    return res;
}
string x,y;
string rndstr2(int len){
    string res;
    for(int i=1;i<=len;i++) res+=rnd(0,1)?x:y;
    return res;
}
bool check1(const string &s,string &a,string &b){
    int h=gethash(s,base1,p1);
    if(h1.count(h)){
        a=s,b=h1[h];
        if(a==b) return 1;
        return 0;
    }
    h1[h]=s;
    return 1;
}
ofstream out("1.in");
bool check2(const string &s){
    int h=gethash(s,base2,p2);
    if(h2.count(h)){
        if(s==h2[h]) return 1;
        out<<s<<'\n';
        out<<h2[h]<<'\n';
        return 0;
    }
    h2[h]=s;
    return 1;
}
int main(){
    base1=131;
    base2=13331;
    p1=1e9+7;
    p2=998244353;
    while(check1(rndstr1(10),x,y));
    while(check2(rndstr2(40)));
    return 0;
}
