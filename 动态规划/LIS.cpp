//O(NlgN)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=60000;

int c[maxn],l[maxn];
int n;

int lis(){
    l[0]=c[0];
    int length=1;

    for(int i=1;i<n;++i){
        if(l[length-1]<c[i]){
            l[length++]=c[i];
        }else{
            *lower_bound(l,l+length,c[i])=c[i];
        }
    }

    return length;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&c[i]);
    }

    printf("%d",lis());
    return 0;
}
