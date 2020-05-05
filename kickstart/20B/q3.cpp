#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int i){
    ll max = 1000000000;
    ll x=ll(0), y=ll(0);
    stack<ll> st;
    string s;
    cin >> s;
    ll m = ll(1);
    for(int i=0; i<s.length(); ++i){
        if(s[i] >= '2' && s[i] <= '9'){
            st.push(ll(s[i] - '0'));
            m= (m*(s[i]-'0'))%max;
            continue;
        }
        switch (s[i])
        {
        case 'E':
            x = (x+m)%max;
            break;
        case 'W':
            x = (x-m+max)%max;
            break;
        case 'S':
            y = (y+m)%max;
            break;
        case 'N':
            y = (y-m+max)%max;
            break;
        case ')':
            m/=st.top();
            st.pop();
            break;
        default:
            break;
        }
    }
    
    cout << "Case #" << i << ": " << x+1 << " " << y+1 << '\n';
}

int main(){
    // int T = 0;
    // cin >> T;
    // for(int i=0; i<T; ++i)
    //     solve(i+1);
    cout << (-15) % 2 ;
}