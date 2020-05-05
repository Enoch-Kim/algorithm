#include <bits/stdc++.h>
using namespace std;

int n, k, a[100000];

void solve() {
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	int lb=1, rb=a[n-1]-a[0];
	while(lb<rb) {
		int mb=(lb+rb)/2;
        cout << "lb is " << lb << '\n';
        cout << "rb is " << rb << '\n';
        cout << "mb is " << mb << '\n';
		int k2=0;
		for(int i=1; i<n; ++i) {
			int d=a[i]-a[i-1];
            cout << "d is " << d << '\n';
            cout << "------- " << (d-1)/mb << '\n';
			k2+=(d-1)/mb;
		}
        cout << "k2 is " << k2 << '\n';
		if(k2<=k)
			rb=mb;
		else
			lb=mb+1;
	}
	cout << lb << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i=1;
	cin >> t;
	while(t--) {
		cout << "Case #" << i << ": ";
		solve();
		++i;
	}
}
// 3
// 5 2
// 10 13 15 16 17
// 5 6
// 9 10 20 26 30
// 8 3
// 1 2 3 4 5 6 7 10