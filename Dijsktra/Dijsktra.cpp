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
    int n,m;//�����ͱ���,�����ڽ�ͼʱ����
    vector<Edge> edges;//�߱�
    vector<int> G[maxn];//ÿ���ڵ�����ı߱��
    bool done[maxn];//�Ƿ����ñ��
    int d[maxn];//��s������������ľ���
    int p[maxn];//���·�е���һ����
    int T;//Դ�㣬=s

    void init(int n){
        this->n=n;
        for(int i=0;i<n;++i) G[i].clear();//����ڽӱ�
        edges.clear();//��ձ߱�
    }

    void AddEdge(int from,int to,int dist){
        //���������ͼ,��Ҫ�����α�
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);//�ѱ߱���±��¼
    }

    void dijsktra(int s){
        //��s�����е�ľ���
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
void seEd(int ind){//�������·��.
    if(ind!=dj.T){
        seEd(dj.edges[dj.p[ind]].from);
        que.push(ind);
    }else
        que.push(ind);
}
int main(){
    return 0;
}
