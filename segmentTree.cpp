#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
using namespace std;

int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
// ====================================start of the segment tree=========================================
class STree{
private:
    vector<int> tree;
    int n;
    int sum(int v, int tl, int tr, int l, int r) {      
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))  + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    void buildTree(vector<int>& a,int tl, int tr,int v=1){
        if(tl>tr) return;
        if(tl==tr){
            tree[v]=a[tl];
            return;
        }

        int mid=(tl+tr)/2;
        buildTree(a,tl,mid,v*2);
        buildTree(a,mid+1,tr,v*2+1);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
    void update(int idx,int val,int v,int tl,int tr){
        if(tl>tr) return;
        if(idx<tl || idx>tr)  return;     //not in the current range
        if(tl==tr){
            tree[v]=val;
            return;
        }
        int tmid=(tl+tr)/2;
        update(idx,val,v*2,tl,tmid);
        update(idx,val,v*2+1,tmid+1,tr);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
public:
    STree(int sz,vector<int>& vec){
        n=sz;
        tree.assign(sz*4,0);
        buildTree(vec,0,n-1);
    }

    int getSum(int l,int r){
        return sum(1,0,n-1,l,r);         // call the function!
    }
    void update(int idx,int val){     // v is the new value!
        update(idx,val,1,0,n-1);
    }

};
// ========================================= Segment tree ends here====================================
int32_t main()
{
    vector<int> v;
    v={1,2,3,4,5,6,7,23431,145,124};
    STree st(10,v);
    cout<<st.getSum(2,3)<<"\n";
    st.update(2,100);
    cout<<st.getSum(2,3)<<"\n";

    

}

    