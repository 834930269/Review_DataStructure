#include<bits/bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXNUM=1000;
struct SegTreeNode{
    int val;//值
}segTree[MAXNUM];//定义线段树

/****hyperlink origin from:http://www.cnblogs.com/TenosDoIt/p/3453089.html*****/
/*
**线段树的每个节点表示一个区间，子节点则
**分别表示父节点的左右半区间，例如父亲的
**区间是[a,b]，那么(c=(a+b)/2)左儿子的区
**间是[a,c]，右儿子的区间是[c+1,b]。
*****************************************
**定义包含n个节点的线段树 SegTreeNode
**segTree[n]，segTree[0]表示根节点。那么
**对于节点segTree[i]，它的左孩子是segTree
**[2*i+1],右孩子是segTree[2*i+2]。
*/
/*********************/
/*
功能:构建线段树
root:当前线段树的根节点下标
arr:用来构造线段树的数组
istart:数组的起始位置
iend:数组的结束位置
*/
void build(int root,int arr[],int istart,int iend){
    if(istart == iend) //叶子结点
        segTree[root].val=arr[istart];
    else{
        int mid=(istart+iend)/2;
        build(root*2+1,arr,istart,mid);//递归构造左子树
        build(root*2+2,arr,mid+1,iend);//递归构造右子树
        //根据左右子树根节点的值,更新当前节点的值
        segTree[root].val=min(segTree[root*2+1].val,segTree[root*2+2].val);
    }
}

/*
功能:线段树的区间查询
root:当前线段树的根节点下标
[nstart,nend]:当前节点所表示的区间
[qstart,qend]:此次查询的区间
*/
int query(int root,int nstart,int nend,int qstart,int qend){
    //查询区间和当前节点区间没有交集
    if(qstart>nend||qend<nstart)
        return INF;
    //当前节点区间包含在查询区间内
    if(qstart<=nstart && qend>=nend)
        return segTree[root].val;
    //分别从左右子树查询,返回两者查询结果的较小值
    int mid=(nstart+nend)/2;
    return min(query(root*2+1,nstart,mid,qstart,qend),
               query(root*2+2,mid+1,nend,qstart,qend));
}

/*
功能：更新线段树中某个叶子节点的值,但是更新叶子时
会对其父节点产生影响,因此更新子节点后,要回溯更新其父节点.
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
index: 待更新节点在原始数组arr中的下标
addVal: 更新的值（原来的值加上addVal）
*/
void updateOne(int root,int nstart,int nend,int index,int addVal){
    if(nstart == nend){
        if(index == nstart) //找到了相应的节点,更新之
            segTree[root].val+=addVal;
        return;
    }
    int mid = (nstart+need)/2;
    if(index<=mid)//在左子树中更新
        updateOne(root*2+1,nstart,mid,index,addVal);
    else updateOne(root*2+2,mid+1,nend,index,addVal);//在右子树中更新
    //根据左右子树的值回溯更新当前节点的值
    segTree[root].val=min(segTree[root*2+1].val,segTree[root*2+2].val);
}

int main(){

    return 0;
}
