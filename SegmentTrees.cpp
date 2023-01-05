#include "bits/stdc++.h"
using namespace std;
/*
Segment Tree basics... the values reside at the leaf nodes..
the internal nodes represent some sort of combination operation which 
is computed based on the leaf nodes values -> and hence the internal 
nodes actually represent a range!
// array representation of the node 
*/

vector<int> STree;
void build(vector<int>& a, int v,int tl, int tr){
    if(tl==tr)    STree[v]=a[tl];
    else{
        int tmid=(tl+tr)/2;
        build(a,v*2,tl,tmid);
        build(a,v*2+1,tmid+1,tr);
        STree[v]=STree[2*v]+STree[2*v+1];
    }
}
int sum(int v,int tl,int tr, int l,int r){
    if (l > r)  return 0;
    if (l == tl && r == tr) return STree[v];
    gcd(l,r);
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
// void buildTre
int main(){
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);  
    freopen("output.txt", "w", stdout);              // take input from the file and O/P on the console-- > more clarity!
    #endif
    int nodes=10;
    STree.assign(4*nodes,0);
    vector<int> a={1,2,3,2,3,45,5,6,6,343};
    for(auto& i:a)  cout<<i<<" ";
    return 0;
}

