#include<bits/bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXNUM=1000;
struct SegTreeNode{
    int val;//ֵ
}segTree[MAXNUM];//�����߶���

/****hyperlink origin from:http://www.cnblogs.com/TenosDoIt/p/3453089.html*****/
/*
**�߶�����ÿ���ڵ��ʾһ�����䣬�ӽڵ���
**�ֱ��ʾ���ڵ�����Ұ����䣬���縸�׵�
**������[a,b]����ô(c=(a+b)/2)����ӵ���
**����[a,c]���Ҷ��ӵ�������[c+1,b]��
*****************************************
**�������n���ڵ���߶��� SegTreeNode
**segTree[n]��segTree[0]��ʾ���ڵ㡣��ô
**���ڽڵ�segTree[i]������������segTree
**[2*i+1],�Һ�����segTree[2*i+2]��
*/
/*********************/
/*
����:�����߶���
root:��ǰ�߶����ĸ��ڵ��±�
arr:���������߶���������
istart:�������ʼλ��
iend:����Ľ���λ��
*/
void build(int root,int arr[],int istart,int iend){
    if(istart == iend) //Ҷ�ӽ��
        segTree[root].val=arr[istart];
    else{
        int mid=(istart+iend)/2;
        build(root*2+1,arr,istart,mid);//�ݹ鹹��������
        build(root*2+2,arr,mid+1,iend);//�ݹ鹹��������
        //���������������ڵ��ֵ,���µ�ǰ�ڵ��ֵ
        segTree[root].val=min(segTree[root*2+1].val,segTree[root*2+2].val);
    }
}

/*
����:�߶����������ѯ
root:��ǰ�߶����ĸ��ڵ��±�
[nstart,nend]:��ǰ�ڵ�����ʾ������
[qstart,qend]:�˴β�ѯ������
*/
int query(int root,int nstart,int nend,int qstart,int qend){
    //��ѯ����͵�ǰ�ڵ�����û�н���
    if(qstart>nend||qend<nstart)
        return INF;
    //��ǰ�ڵ���������ڲ�ѯ������
    if(qstart<=nstart && qend>=nend)
        return segTree[root].val;
    //�ֱ������������ѯ,�������߲�ѯ����Ľ�Сֵ
    int mid=(nstart+nend)/2;
    return min(query(root*2+1,nstart,mid,qstart,qend),
               query(root*2+2,mid+1,nend,qstart,qend));
}

/*
���ܣ������߶�����ĳ��Ҷ�ӽڵ��ֵ,���Ǹ���Ҷ��ʱ
����丸�ڵ����Ӱ��,��˸����ӽڵ��,Ҫ���ݸ����丸�ڵ�.
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
index: �����½ڵ���ԭʼ����arr�е��±�
addVal: ���µ�ֵ��ԭ����ֵ����addVal��
*/
void updateOne(int root,int nstart,int nend,int index,int addVal){
    if(nstart == nend){
        if(index == nstart) //�ҵ�����Ӧ�Ľڵ�,����֮
            segTree[root].val+=addVal;
        return;
    }
    int mid = (nstart+need)/2;
    if(index<=mid)//���������и���
        updateOne(root*2+1,nstart,mid,index,addVal);
    else updateOne(root*2+2,mid+1,nend,index,addVal);//���������и���
    //��������������ֵ���ݸ��µ�ǰ�ڵ��ֵ
    segTree[root].val=min(segTree[root*2+1].val,segTree[root*2+2].val);
}

int main(){

    return 0;
}
