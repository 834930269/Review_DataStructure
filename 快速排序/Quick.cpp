#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;

int qpartition(int *a,int lo,int hi){
    int v=a[lo];
    int i=lo,j=hi+1;
    while(true){
        while(a[++i]<v)if(i==hi)break;
        while(a[--j]>v)if(j==lo)break;
        if(i>=j)break;
        swap(a[i],a[j]);
    }
    swap(a[lo],a[j]);
    return j;
}

void qsort(int *a,int lo,int hi){
    if(lo>=hi) return;
    int j=qpartition(a,lo,hi);
    qsort(a,lo,j-1);
    qsort(a,j+1,hi);
}

int main(){
    srand((unsigned)time(NULL));
    int a[20];
    for(int i=0;i<20;++i){
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }
    printf("\n");
    qsort(a,0,19);
    for(int i=0;i<20;++i){
        printf("%d ",a[i]);
    }
    return 0;
}



