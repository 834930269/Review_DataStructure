#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=100000+10;
int minv[maxn];
///����������Сֵ����
void build(int o,int L, int R){
    ///��ʼ���߶���
    if(L == R){
        printf("�������±�Ϊ%d�ĸ��ڵ��ֵ:\n",o);
        scanf("%d",&minv[o]);
        return;
    }
    int mid = (L + R) >> 1;
    build(o << 1,L, mid);
    minv[o]=min(minv[o],minv[o<<1]);
    build((o << 1) + 1,mid + 1, R);
    minv[o]=min(minv[o],minv[(o<<1)+1]);
}
int ql,qr;
int query(int o,int L,int R){
    int M=L+((R-L)>>1),ans=INF;
    if(ql<=L&&R<=qr){
        return minv[o];
    }
    if(ql<=M)ans=min(ans,query(o<<1,L,M));
    if(M<qr)ans=min(ans,query((o<<1)+1,M+1,R));
    return ans;
}

int p,v;///�޸�p��Ϊv
void update(int o,int L,int R){
    int M=L+((R-L)>>1);
    if(L==R)minv[o]=v;
    else{
        if(p<=M)update(o<<1,L,M);else update((o<<1)+1,M+1,R);
        minv[o]=min(minv[o<<1],minv[(o<<1)+1]);
    }
}

int main(){
    fill(minv,minv+100000,INF);
    cout<<"����������1-a:\n";
    int a;
    scanf("%d",&a);
    build(1,1,a);
    for(int i=1;i<=15;++i)
        cout<<i<<": "<<minv[i]<<endl;
    printf("��������Ҫ��ѯ��������x-y:\n");
    cin>>ql>>qr;
    cout<<query(1,1,a);
    return 0;
}
