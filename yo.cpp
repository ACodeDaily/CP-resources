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

void solve(){
    int n=1,m=0;
    string s;
    cin>>n;
    vi a(n),b(n);
    cin>>a>>b;
    unordered_map<int,int> locsA,locsB;
    for(int i=0;i<n;i++)    locsA[a[i]]=i,locsB[b[i]]=i;
    // seperate case for 1 .. exclude one from the array-> mex is 1 
    int res=1;      // the entire array case!
    int left=min(locsA[1],locsB[1]),right=max(locsA[1],locsB[1]);
    
    res+=(left)*(left+1)/2;
    res+=(n-right-1)*(n-right)/2;
    res+=max(0ll,(right-left-1)*(right-left)/2);

    // cout<<res<<"\n";
    for(int m=2;m<=n;m++){      // here m is MEX
        int loc_left=min(locsA[m],locsB[m]);
        int loc_right=max(locsA[m],locsB[m]);

        if(loc_left>=right) res+=(left+1)*(loc_left-right);     //
        else if(loc_right<=left) res+=(n-right)*(left-loc_right);
        else if(loc_left<left && loc_right>right)   res+=(left-loc_left)*(loc_right-right);

        left=min(left,loc_left),right=max(right,loc_right);
    }
    cout<<res<<"\n";


}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    