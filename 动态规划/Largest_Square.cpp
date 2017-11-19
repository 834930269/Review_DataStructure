#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1500;

int dp[maxn][maxn],G[maxn][maxn];
int n,m;

int main(){
    int maxedge=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&G[i][j]);
            if(G[i][j]==1)dp[i][j]=0;
            else dp[i][j]=1,maxedge=1;
        }
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            if(!G[i][j]){
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                maxedge=max(maxedge,dp[i][j]);
            }
        }
    }
    printf("%d\n",maxedge*maxedge);
    return 0;
}
