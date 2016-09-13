/* if(tree[pos]==1)
    return;
    
    
    take y at all place instead of input      //Tripathihelp
    
    a[node] ==1 return
    
scanf() <-- cin */   
    
void update(int segtree[],int y[],int low,int high,int pos,int qlow,int qhigh)
{
    if(segtree[pos]==1)
        return;
    if(qlow>high || qhigh<low)
        return;
    if(low==high)
    {
        y[low]=y[low]/a[y[low]];    /* a stores the lowestprime */ 
        segtree[pos]=a[y[low]];             /*input --> original array*/
        return;
    }
    else
    {
            int mid = (low+high)/2;
        update(segtree,y,low,mid,2*pos+1,qlow,qhigh);
        update(segtree,y,mid+1,high,2*pos+2,qlow,qhigh);
        segtree[pos] = max(segtree[2*pos + 1],segtree[2*pos + 2]);
    }
}    
