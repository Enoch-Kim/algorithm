#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcul(int N){
    vector<int> v(N);
    for(int i=0; i< N; ++i)
        cin >> v[i];
    int ans=0;
    bool slop=1;
    for(int i=1; i<N; ++i){
        if(v[i] - v[i-1] < 0 && slop == 1)
            ans++;
        slop = v[i] - v[i-1];
    }
    
    return ans;
}

int main(){
    int T = 0,
        N = 0;
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> N;
        int result = calcul(N);
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
}