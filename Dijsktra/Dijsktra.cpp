#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn=100000;
struct Edge{
    int from,to,dist;
};

struct HeapNode{
    int d,u;
    bool operator<(const HeapNode& rhs)const{
        return d<rhs.d;
    }
};

struct Dijsktra{
    int n,m;//点数和边数,边数在建图时更新
    vector<Edge> edges;//边表
    vector<int> G[maxn];//每个节点出发的边编号
    bool done[maxn];//是否永久编号
    int d[maxn];//从s出发到各个点的距离
    int p[maxn];//最短路中的上一条边
    int T;//源点，=s

    void init(int n){
        this->n=n;
        for(int i=0;i<n;++i) G[i].clear();//清空邻接表
        edges.clear();//清空边表
    }

    void AddEdge(int from,int to,int dist){
        //如果是无向图,需要加两次边
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);//把边表的下标记录
    }

    void dijsktra(int s){
        //求s到所有点的距离
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;++i)
            d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push((HeapNode){0,s});
        while(!Q.empty()){
            HeapNode x=Q.top(); Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<G[i].size();++i){
                Edge &e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }

};
queue<int> que;
Dijsktra dj;
void seEd(int ind){//查找最短路径.
    if(ind!=dj.T){
        seEd(dj.edges[dj.p[ind]].from);
        que.push(ind);
    }else
        que.push(ind);
}
int main(){
    return 0;
}
