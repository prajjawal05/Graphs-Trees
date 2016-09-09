/*max Segment Tree*/

#include<bits/stdc++.h>
using namespace std;

void constructTree(int segtree[], int input[], int low,int high,int pos)
{
    if(low == high)
    {
        segtree[pos] = input[low];
        return;
    }
    int mid = (low+high)/2;
    constructTree(segtree,input,low,mid,2*pos+1);
    constructTree(segtree,input,mid+1,high,2*pos+2)
    segtree[pos] = max(segtree[2*pos + 1],segtree[2*pos + 2]);
}

int query(int segtree[],int low,int high,int qlow,int qhigh,int pos)
{
    if(qlow<=low && qhigh>= high)
        return segtree[pos];
    if(qlow>high || qhigh<low)
        return INT_MIN;
    int mid = (low+high)/2;
    return max(query(segtree,qlow,qhigh,low,mid,2*pos+1),query(segtree,qlow,qhigh,mid+1,high,2*pos+2));
}

void update(int segtree[],int input,int idx,int value,int low,int high,int pos)
{
    if(low==high)
    {
        segtree[node]+=value;
        A[idx]+=value;
    }
    else
    {
        int mid = (low+high)/2;
        if(low<=idx && idx<=high)
            update(segtree,idx,value,low,mid,2*pos+1);
        else
            update(segtree,idx,value,mid+1,high,2*pos+2);
        segtree[pos] = max(segtree[2*pos + 1],segtree[2*pos + 2]);
    }
}
