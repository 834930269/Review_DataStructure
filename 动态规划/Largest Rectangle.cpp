#include<cstdio>
#include<stack>
#include<iostream>
#include<algorithm>
#define MAX 1400
using namespace std;

struct Rectangle { int height; int pos; };

int getLargestRectangle(int size,int buffer[]){
    stack<Rectangle> S;
    int maxv=0;
    //通过后一位向前面的计算
    //这里用到的DP大概是无参数getLargestRectangle里面的预处理
    //这里用到的更多是思维吧,对每一行进行计算,最后求出最大值.
    buffer[size]=0;

    for(int i=0;i<=size;++i){
        Rectangle rect;
        rect.height=buffer[i];
        rect.pos=i;
        if(S.empty()){
            S.push(rect);
        }else{
            if(S.top().height < rect.height){
                S.push(rect);
            }else if(S.top().height > rect.height){
                int target=i;
                while(!S.empty() && S.top().height >= rect.height){
                    Rectangle pre=S.top();S.pop();
                    int area=pre.height*(i-pre.pos);
                    maxv=max(maxv,area);
                    target=pre.pos;
                }
                rect.pos=target;
                S.push(rect);
            }
        }
    }
    //printf("\nmaxv: %d\n",maxv);
    return maxv;
}

int H,W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int getLargestRectangle(){
    //预处理每个点离他最近的上边未被污染地板的高度
    for(int j=0;j<W;++j){
        for(int i=0;i<H;++i){
            if(buffer[i][j]){
                T[i][j]=0;
            }else{
                T[i][j]=(i>0)?T[i-1][j]+1:1;
            }
        }
    }
    /*
    例:
        0 0 1 0 0
        1 0 0 0 0
        0 0 0 1 0
        0 0 0 1 0

    After:
        1 1 0 1 1
        0 2 1 2 2
        1 3 2 0 3
        2 4 3 0 4
    */
    int maxv=0;
    //传入两个值 W,列数,处理后T[i]第i行的首地址
    for(int i=0;i<H;++i){
        maxv=max(maxv,getLargestRectangle(W,T[i]));
    }

    return maxv;
}

int main(){
    scanf("%d %d",&H,&W);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            scanf("%d",&buffer[i][j]);
        }
    }

    printf("%d\n",getLargestRectangle());
    return 0;
}
