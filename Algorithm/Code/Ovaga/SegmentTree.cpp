#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
int tree[mx * 4],treeMax[mx*4],treeMin[mx*4];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        treeMin[node] = arr[b];
        treeMax[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
    treeMax[node] = max(treeMax[Left],treeMax[Right]);
    treeMin[node] = min(treeMin[Left],treeMin[Right]);
}
int query(int node, int b, int e, int i, int j,int a)
{
    if (i > e || j < b)
        {
     if(a==1)
        return 0;
     else if(a==2)
        return 9999999;
     else if(a==3)
        return 0;
    }

    if (b >= i && e <= j)
    {
     if(a==1)
        return tree[node];
     else if(a==2)
        return treeMin[node];
     else if(a==3)
        return treeMax[node];
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j,a);
    int p2 = query(Right, mid + 1, e, i, j,a);
    if(a==1)
     return p1 + p2;
    else if(a==2)
     return min(p1,p2);
    else if(a==3)
     return max(p1,p2);
}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[node] = arr[i];
        treeMax[node] = arr[i];
        treeMin[node] = arr[i];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    treeMax[node] = max(treeMax[Left],treeMax[Right]);
    treeMin[node] = min(treeMin[Left],treeMin[Right]);
    tree[node] = tree[Left] + tree[Right];
}

int getMid(int s, int e) { return s + (e - s) / 2; }

int l= 1e9;
int findMinimumIndex(int ss, int se, int K, int si)
{

    if (treeMax[si] < K)
        return 1e9;


    if (ss == se) {


        if (treeMax[si] >= K) {

            return ss;
        }

        return 1e9;
    }


    int mid = getMid(ss, se);



    if (treeMax[2 * si ] >= K)
        l = findMinimumIndex( ss, mid, K,
                                    2 * si );


    if (l == 1e9 && treeMax[2 * si + 1] >= K)
        l =  findMinimumIndex( mid + 1, se, K,
                                    2 * si + 1);

    return l;
}


struct node {
    int f;
    int s;
};


void build(
    int arr[], node tree[],
    int start, int end,
    int index)
{

    if (start == end) {
        tree[index].f = arr[start];

        tree[index].s = 0;

        return;
    }


    int mid = start + (end - start) / 2;


    build(
        arr, tree, start,
        mid, 2 * index + 1);


    build(
        arr, tree, mid + 1,
        end, 2 * index + 2);


    int l1 = tree[2 * index + 1].f;
    int l2 = tree[2 * index + 1].s;
    int r1 = tree[2 * index + 2].f;
    int r2 = tree[2 * index + 2].s;


    tree[index].f = max(l1, r1);


    tree[index].s
        = max(min(l1, r1),
              max(l2, r2));





             /* range queryte aituku change
node Left
        = runQuery(
            tree, start,
            mid, 2 * index + 1,
            L, R);

    node Right
        = runQuery(
            tree, mid + 1,
            end, 2 * index + 2,
            L, R);

    int l1 = Left.f;
    int l2 = Left.s;
    int r1 = Right.f;
    int r2 = Right.s;


    return { max(l1, r1),
             max(min(l1, r1),
                 max(l2, r2)) };
                 */
}




int main()
{
    int x,n,m,q,a,b;
    cin >> x;
    for(int i=0;i<x;i++)
     cin>> arr[i];
    n=x-1;
    init(1, 0, n);
    q=findMinimumIndex(0,n,5,1);
    cout<<q<< arr[q]<<endl;


}
/*
10
3 8 4 5 1 3 2 7 0 6
8
1 3 8
2 2 7
4 5 9
3 0 7
1 4 8
4 1 0
2 0 3
1 0 9
*/


/*

cin>>m;
for(int i=1;i<=m;i++)
    {
    cin>>q>>a>>b;

    if(q==1)
    {

       cout<<"Query "<<i<<":";
       cout<<query(1,0,n,a,b,q)<<endl;
    }
    else if(q==2)
    {
       cout<<"Query "<<i<<":";
       cout<<query(1,0,n,a,b,q)<<endl;
    }
    else if(q==3)
    {
       cout<<"Query "<<i<<":";
       cout<<query(1,0,n,a,b,q)<<endl;
    }
    else if(q==4)
    {
        arr[a]=b;
        update(1,0,n,a,b);
    }
    }
    for(int i=0;i<x;i++)
     cout<< arr[i]<<" ";

     */
