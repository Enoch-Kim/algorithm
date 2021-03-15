// https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/

#include <unordered_set>
typedef long long ll;

int solution(int N) {
    ll longN = ll(N);
    unordered_set<ll> numSet;
    for(ll i=1; i*i<=N; i++){
        ll div = N/i;
        if(div * i == N){
            numSet.insert(i);
            numSet.insert(div);
        }
    }

    return numSet.size();
}

// https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
