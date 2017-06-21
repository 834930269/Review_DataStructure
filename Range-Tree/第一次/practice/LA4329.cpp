#include<bits/stdc++.h>
#define cle(x) memset(x,0,sizeof(x))
using namespace std;

const int maxn=200000;

int N,C[maxn],A[maxn],T;//����ǰ׺��C
int sm[maxn],sl[maxn];//С��ai,����ai

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
    while(x<=150000){//Ϊ�˱�֤����������䷶Χ��
        C[x]+=d;x+=lowbit(x);
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        long long ans=0;//Ҫ��longlong
        /*
        ��˳��˼��,������ÿ�������������1,2,3...20000
        ��ôһ�����T=1*19998+2*19997+3*19996+...+19998*1 ÿ��϶���һ��
        ��Ϊ���в�һ��,20�����result=20*T.
        test�в��T=1333133340000,��int
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
