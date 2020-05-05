#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;



class Solution{
    public :
        Solution() {
            cin >> W >> H >> L >> U >> R >> D;
        }



        ld solve(){
            if(W == 1 || H == 1 || (W==R && H==D) || (L==1 && U==1))
                return 0.;
            if(L>1){
                ll i=0;
                ld prob = 1;
                
            }
            if(R>1){

            }
            return Prob;
        }

    private :
        ll W;
        ll H;
        ll L;
        ll U;
        ll R;
        ll D;
        ld Prob;
};

int main(){
    int T = 0;
    cin >> T;
    for(int i=0; i<T; ++i){
        Solution S;
        ld result = S.solve();
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
}