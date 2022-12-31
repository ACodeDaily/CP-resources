#include<bits/stdc++.h>
using namespace std;
class UnionFind{
    vector<int> par,sz;
    public:
    UnionFind(int n){
        par.assign(n,0);
        sz.assign(n,1);
        iota(par.begin(),par.end(),0);
    }     
    int getPar(int i){
        return par[i]=par[i]==i?i:getPar(par[i]);
    }
    void combine(int i,int j){
        int pi=getPar(i),pj=getPar(j);
        if(pi!=pj){
            par[pi]=pj;
            sz[pj]+=sz[pi];
        }
    }
    int getSz(int i){
        return sz[getPar(i)];
    }
};
bool solve(int n,int s, vector<int>& A,vector<int>& B){
    UnionFind uf(s+1);
    for(int i=0;i<n;i++){
        uf.combine(A[i],B[i]);
    }
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[uf.getPar(A[i])]++;
    }
    for(int i=0;i<n;i++){
        if(uf.getSz(A[i])<freq[uf.getPar(A[i])])  return 0;
    }
    return 1;
    
}
int main(){
    int N=0,S=0;
    cin>>N>>S;
    vector<int> A(N,0),B(N,0);
    for(auto& i:A)  cin>>i;
    for(auto& i:B)  cin>>i;
    cout<<solve(N,S,A,B)<<"\n";
    
}

