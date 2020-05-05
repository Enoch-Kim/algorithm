#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calcul(){
    ll N, D;
    cin >> N >> D;
    ll ans = D;
    vector<ll>  v(N);
    for(int i=0; i< N; ++i)
        cin >> v[i];
    
    for(int i=N-1; i>=0; --i){
        ans = (ans/v[i]) * v[i];
    }
    
    return ans;
}

int main(){
    int T = 0,
        N = 0, D=0;
    cin >> T;
    for(int i=0; i<T; ++i){
        ll result = calcul();
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
}