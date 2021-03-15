// https://app.codility.com/programmers/lessons/6-sorting/distinct/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> numSet;

    for(size_t i=0; i<A.size(); i++){
        numSet.insert(A[i]);
    }

    return numSet.size();
}


// https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int size = A.size();

    return max(A[0] * A[1] * A[size-1], A[size-1] * A[size-2] * A[size-3]);
}

// https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/

#include <algorithm>

typedef long long ll;

bool compareSect(vector<ll> &a, vector<ll> &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    int size = A.size();
    vector<vector<ll>> sects; //{left, right}
    for(int i=0; i<size; i++){
        sects.push_back({ll(i)-A[i], ll(i)+A[i]});
    }

    sort(sects.begin(), sects.end(), compareSect);

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(sects[j][0] > sects[i][1]){
                break;
            }
            answer++;
        }
        if(answer > 10000000){
            break;
        }
    }

    if(answer > 10000000){
        answer = -1;
    }

    return answer;
}