#include<iostream>
#include<cassert>
using namespace std;
string s;
int cur;
int main(){
    freopen("1.in","r",stdin);
    cin>>s;
    for(char &c:s){
        if(c=='(') ++cur;
        else --cur;
        assert(cur>=0);
    }
    assert(cur==0);
    return 0;
}
