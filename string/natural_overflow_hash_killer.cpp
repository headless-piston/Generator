/*
* 生成两个不同的串，满足其自然溢出哈希值相同
* 生成方法：
* 对于 base 为偶数的情况，利用 base 幂次较高时与 2^64 同余构造
* 对于 base 为奇数的情况，利用 Thue Morse 序列构造
*/
#include<iostream>
#include<random>
#include<algorithm>
#include<fstream>
using namespace std;
typedef long long ll;
mt19937_64 getrnd(__builtin_ia32_rdtsc());
ll rnd(ll l,ll r){return getrnd()%(r-l+1)+l;}
char st[30];
string get_rev(const string &s){//反转字符，a 变 b，b 变 a
    string res;
    for(char c:s)
        if(c=='a') res.push_back('b');
    else res.push_back('a');
    return res;
}
ofstream out("1.in");
void gen1(){//base 为偶数，需要令 len 大于 64
    int len=70;
    string s;
    for(int i=2;i<=len;i++) s.push_back(rnd('a','z'));
    char a,b;
    shuffle(st,st+26,getrnd);
    a=st[0],b=st[1];
    out<<a<<s<<'\n';
    out<<b<<s<<'\n';
}
void gen2(){//base 为奇数，使用 Thue Morse 序列
    int len=5;//初始串长
    int n=15;//最终串长为 len*(2^n) n>12
    string s;
    for(int i=1;i<=len;i++) s.push_back(rnd('a','b'));
    for(int i=1;i<=n;i++){
        string rev=get_rev(s);
        s+=rev;
    }
    out<<s<<'\n';
    out<<get_rev(s)<<'\n';
}
int main(){
    for(int i=0;i<26;i++) st[i]='a'+i;
//    gen1();
    gen2();
    return 0;
}
