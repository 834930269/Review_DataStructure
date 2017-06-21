#include<bits/stdc++.h>
using namespace std;

const int maxn=1<<17;

int C[maxn];

int lowbit(int x){
    return x&(-x);
}

int sum(int x){
    int ret = 0;
    while(x>0){
        ret+=C[x]; x-=lowit(x);
    }
    return ret;
}

void add(int x,int d){
    while(x<=n){
        C[x]+=d; x+=lowbit(x);
    }
}

int main(){

    return 0;
}
