#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
using namespace std;
uint power(int x, int y, int p = 1e9 + 7)
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
uint modInverse(int n, int p)
{
    return power(n, p - 2, p);
}
uint nCrModPFermat(int n, int r, int p)
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
void print(vector<int>& v, int i=0,int j=0){
    if(j==0)    j=v.size()-1;
    for(int idx=i;idx<=j;idx++) cout<<v[idx]<<" ";
    cout<<"\n";
}
void solve(){
    int n=1,m=0;
    string s;
    cin>>n;
    vector<int> vec(n,0);
    for(auto& i:vec)    cin>>i;
    


    
    // print(vec);
}
int32_t main()
{

 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);              // take input from the file and O/P on the console-- > more clarity!
#endif
 
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

