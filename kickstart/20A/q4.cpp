#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    vector<int> v(n,0);
    vector<int> m;
    for(int i=0; i<n; ++i)
       cin >> s[i];
    sort(s.rbegin(), s.rend());

    for(int i=0; i<n-k+1; i++){
        for(int j=v[i]; j<s[i].length(); j++){
            string cur = s[i].substr(0, j+1);
            int count = 1;
            for(int k=i+1; k<n; k++){
                if(s[k].substr(0,j+1) == cur){
                    count++;
                    v[k]=j+1;
                }else
                    break;
            }
            cout << count;
            count /= k;
            if(count==0)
                break;
            else if(j < m.size())
                m[j]+= count;
            else
                m.push_back(count);
        }
    }
    if(m.size() == 0) 
        return 0;

    int ans=0, count=0, i=m.size()-1;
    ans += (i+1)*m[i];
    --i;
    while(i>=0 && count+(m[i]-m[i+1])<=n/k){
        ans += (i+1)*(m[i]-m[i+1]);
        count+= m[i]-m[i+1];
        --i;
    }
    if(count < n/k){
        ans += (i+1)*(k-count);
    }
    return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i=1;
	cin >> t;
	while(t--) {
        int ans = solve();
        cout << "Case #" << i++ << ": " << ans << '\n';
    }
}

// 2
// 2 2
// KICK
// START
// 8 2
// G
// G
// GO
// GO
// GOO
// GOO
// GOOO
// GOOO