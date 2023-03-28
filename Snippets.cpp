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
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!

const int MX_SZ=1e5+5;
int par[MX_SZ];


void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


constexpr int N = 200005; // No. of vertices
constexpr int L = 20; // ceil(logN / log2) + 1

// Vertices from 1 to N.
vector<int> adj[N + 1];
int up[N + 1][L];
int level[N + 1];

void dfs(int u, int prev = 0){
 up[u][0] = prev;
 for (auto &v : adj[u]){
     if (v == prev) continue;

     level[v] = level[u] + 1;
     dfs(v, u);
 }
}

void binaryLift(){
 dfs(1);
 for (int i = 1; i < L; i++)
     for (int j = 1; j <= N; j++)
          up[j][i] = up[up[j][i - 1]][i - 1];
}

int LCA(int a, int b){
 if (level[a] > level[b])
     swap(a, b);

 int diff = level[b] - level[a];
 for (int i = 0; i < L; i++){
     if ((diff & (1 << i)))
         b = up[b][i];
 }

 if (a == b) return a;

 for (int i = L - 1; i >= 0; i--){
     if (up[a][i] != up[b][i]){
         a = up[a][i];
         b = up[b][i];
     }
 }
 return up[a][0];
}

void addEdge(int u, int v){
 adj[u].push_back(v);
 adj[v].push_back(u);
}

int dist(int a, int b){
 return level[a] + level[b] - 2 * level[LCA(a, b)];
}
/// ====================================PRIME utility ==================================================
int sz=1e6+5;
bool PrimeSieve[1000005];   // 1e6+5
void buildSieve(){
    for(int i=2;i<=sz;i++)    PrimeSieve[i]=1;
    PrimeSieve[0]=0;// 
    PrimeSieve[1]=0;    // 1 is neither prime nor composite 
    for(int i=2;i<sz;i++){
        if(PrimeSieve[i]==0)    continue;       // the current number itself is composite 
        for(int j=2;j*i<sz;j++){
            PrimeSieve[i*j]=0;
        }
    }
}
// add SieveOfEratosthenes
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)  return 0;
    }
    return 1;
}

/// ====================================PRIME utility ENDS here==================================================

template<class T, class U>
// T -> node, U->update.
struct Lsegtree{
    vector<T>st;
    vector<U>lazy;
    int n;
    T identity_element;
    U identity_update;

    /*
        Definition of identity_element: the element I such that combine(x,I) = x
        for all x

        Definition of identity_update: the element I such that apply(x,I) = x
        for all x        
    */

    Lsegtree(int n, T identity_element, U identity_update){
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n,identity_element);
        lazy.assign(4*n, identity_update);
    }

    T combine(T l, T r){
        // change this function as required.
        T ans = (l + r);
        return ans;
    }

    void buildUtil(int v, int tl, int tr, vector<T>&a){
        if(tl == tr){
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, int tl, int tr){
        T ans = (tr-tl+1)*upd;
        // increment range by upd:
        // T ans = curr + (tr - tl + 1)*upd
        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, int tl, int tr){
        U ans = old_upd;
        ans=new_upd;
        return ans;
    }  

    void push_down(int v, int tl, int tr){
        //for the below line to work, make sure the "==" operator is defined for U.
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if(2*v + 1 <= 4*n){
            int tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }

    T queryUtil(int v, int tl, int tr, int l, int r){
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        if(tr < l or tl > r){
            return identity_element;
        }
        if(l <= tl and r >= tr){
            return st[v];
        }
        int tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
 
    void updateUtil(int v, int tl, int tr, int l, int r, U upd){
        push_down(v,tl,tr); 
        if(tr < l or tl > r)return;
        if(tl >=l and tr <=r){
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        } else{
            int tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }

    void build(vector<T>a){
        assert( (int)a.size() == n);
        buildUtil(0,0,n-1,a);
    }

    T query(int l, int r){
        return queryUtil(0,0,n-1,l,r);
    }

    void update(int l,int r, U upd){
        updateUtil(0,0,n-1,l,r,upd);
    }
};

// ========================================MATH UTIL BEGINS==============================================
//==================================== compute higher powers with mod ===================================
uint power(int x, int y, int p =  MOD)
{
    unsigned long long res = 1;

    x = x % p;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// =============================================================================================================

uint modInverse(int n, int p=MOD)       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
{
    return power(n, p - 2, p);
}
// can also derive this using extended euclidean... however this has a much simpler code....


// =========================================Used to calculate nCr of higher values ===================================
uint nCr(int n, int r, int p=MOD)     // faster calculation.. 
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;
        
    vector<int> fac(n+1,0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
// ==================================== MATH UTIL ENDS=======================================================//


void solve(){
    int n=1,m=0;
    string s;
    cin>>n;
    vi v(n);
    cin>>v;
    
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    