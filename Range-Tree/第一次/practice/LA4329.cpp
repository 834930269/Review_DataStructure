#include<bits/stdc++.h>
#define cle(x) memset(x,0,sizeof(x))
using namespace std;

const int maxn=200000;

int N,C[maxn],A[maxn],T;//区间前缀和C
int sm[maxn],sl[maxn];//小于ai,大于ai

int lowbit(int n){
    return n&(-n);
}

int sum(int x){
    int ret=0;
    while(x>0){
        ret+=C[x];x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d){
    while(x<=150000){//为了保证都在最大区间范围内
        C[x]+=d;x+=lowbit(x);
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        long long ans=0;//要用longlong
        /*
        按顺序思考,最坏情况下每组测试样例都是1,2,3...20000
        那么一组就是T=1*19998+2*19997+3*19996+...+19998*1 每组肯定不一样
        因为裁判不一样,20组就是result=20*T.
        test中测得T=1333133340000,爆int
        */
        scanf("%d",&N);
        for(int i=1;i<=N;++i) scanf("%d",&A[i]);
        cle(C);
        for(int i=1;i<=N;++i){
            add(A[i],1);
            sm[i]=sum(A[i]-1);
        }
        cle(C);
        for(int i=N;i>=1;--i){
            add(A[i],1);
            sl[i]=sum(A[i]-1);
        }
        for(int i=1;i<=N;++i)
            ans+=(sm[i]*(N-i-sl[i])+sl[i]*(i-sm[i]-1));
        printf("%lld\n",ans);
    }
    return 0;
}
