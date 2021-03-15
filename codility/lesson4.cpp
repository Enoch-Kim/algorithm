// https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<bool> leafMap(X+1, false);
    int cnt = 0;
    for(size_t i=0; i<A.size(); i++){
        int temp = A[i];
        if(leafMap[temp]) continue;
        leafMap[temp] = true;
        cnt++;
        if(cnt == X) return i;
    }
    return -1;
}

// https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/
vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> answer(N, 0);
    int max = 0;
    int tempMax = 0;

    for(size_t i=0; i<A.size(); i++){
        int temp = A[i]-1;
        if(temp < N){
            if(answer[temp] < max){
                answer[temp] = max+1;
            } else {
                answer[temp]++;
            }

            if(answer[temp] > tempMax){
                tempMax = answer[temp];
            }
        } else {
            max = tempMax;
        }
    }

    for(size_t i=0; i<answer.size(); i++){
        if(answer[i] < max){
            answer[i] = max;
        }
    }

    return answer;
}

// https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 1000001;
    vector<bool> nums(1000001, true);

    for(size_t i=0; i<A.size(); i++){
        if(A[i] > 0){
            nums[A[i]] = false;
        }
    }

    for(size_t i=1; i<nums.size(); i++){
        if(nums[i]){
            answer = i;
            break;
        }
    }

    return answer;

}

// https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 1;
    int xorVal = 0;
    for(size_t i=0; i<A.size(); i++){
        xorVal ^= i+1;
        xorVal ^= A[i];
    }
    if(xorVal){
        answer = 0;
    }
    return answer;
}
