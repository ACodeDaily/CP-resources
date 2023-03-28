#include<bits/stdc++.h>
using namespace std;
long long n,s,x,y,inv[1000001];
string a,b;
int mod=998244353;
signed main() {
  inv[0]=inv[1]=1;
  for(long long i=2; i<=1000000; ++i)
    inv[i]=-998244353/i*inv[998244353%i]%998244353;
  int T;
  cin >> T;
  while(T--) {

    cin >> n >> a >> b;
    s=0;
    x=y=1;
    for(long long i=0; i<n; ++i) s+=a[i]!=b[i];
    for(long long i=n; i>=2; --i) {
      x=((n*inv[i]%998244353+(n*inv[i]%998244353-1)*x%998244353)%998244353+998244353)%998244353;
      y=(y+(i<=s)*x)%998244353;
    }
    if(s==0) cout << 0 << endl;
    else cout << ((x*n+n+y-x)%998244353+998244353)%998244353-1 << endl;
  }
}
