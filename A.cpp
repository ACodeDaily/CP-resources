#include <iostream>
#include <algorithm>
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;
typedef long long ll;
 
const int N = 105;
const int INF = 0x3f3f3f3f;
template <typename T> bool chkmin (T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax (T &x, T y) {return y > x ? x = y, 1 : 0;}
 
int n;
ll a[N];
 
int cnt[N];
 
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);              // take input from the file and O/P on the console-- > more clarity!
#endif
 
	MULTI {
		cin >> n;
		for (int i = 1;i <= n;++i) {
			cin >> a[i];
		}
		
		int isDistinct = 1;
		sort(a + 1, a + n + 1);
		for (int i = 1;i <= n - 1;++i) {
			if (a[i] == a[i + 1]) isDistinct = 0;
		}
		if (isDistinct == 0) {
			cout << "NO" << endl;
			continue;
		}
		int CRT_able = 1;
		for (int mod = 2;mod <= n / 2;++mod) {
			fill(cnt, cnt + mod, 0);
            for (int i = 1;i <= n;++i) {
				cnt[a[i] % mod]++;
                cout<<a[i]%mod<<"\n";
			}
			if (*min_element(cnt, cnt + mod) >= 2) CRT_able = 0;
		}
		cout << (CRT_able ? "YES" : "NO") << endl;
	}
}