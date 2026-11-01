//#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
//#include<cctype>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<numeric>
//#include<functional>
#define int long long
#define init(name,data) memset(name,data,sizeof(name))

using namespace std;

const int INF = 0x3f3f3f3f; //long long 0x3f3f3f3f3f3f3f3f
#ifdef _DEBUG
	const int maxn = 1e3+11; //
	const int maxm = 5e2+11; //
#else
	const int maxn = 2e5+11; //
	const int maxm = 3e6+11; //
#endif

int frac[maxn];

int inv(int i, const int &p) {
	int ans = 1, po = p - 2;
	while (po) {
		if (po & 1) {
			ans = ans * i % p;
		}
		i = i * i % p;
		po >>= 1;
	}
	return ans;
}

int c(const int &n, const int &m, const int &p) { //
	if (n < m || m < 0)return 0;
	return frac[n] * inv(frac[m], p) % p * inv(frac[n - m], p) % p;
}

int lucas(const int &n, const int &m, const int &p) {
	if (m == 0)return 1;
	return c(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	frac[0] = 1;
	while (t--) {
		int n, m, p;
		cin >> n >> m >> p;
		for (int i = 1; i <= p - 1; i++) {
			frac[i] = frac[i - 1] * i % p;
		}
		cout << lucas(n + m, n, p) << endl;
	}
	return 0;
}

/*



*/
