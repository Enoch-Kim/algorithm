// https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int answer = 0;

    int size = A.size();
    vector<int> left_max(size);
    vector<int> right_max(size);
    
    if(A.size() < 4)
        return 0;
    
    for(int i=1; i<size-1; i++){
        left_max[i] = max(left_max[i-1] + A[i] , 0);
    }

    for(int i=size-1; i>1; i--){
        right_max[i-1] = max(right_max[i] + A[i-1], 0);
    }
        
    for(int i=1; i<size-1; i++){
        answer = max(left_max[i-1] + right_max[i+1], answer);
    }    
        
    
    return answer;
}

// https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() < 2){
        return 0;
    }

    int answer = 0;
    int minPrice = A[0];

    for(size_t i=1; i<A.size(); i++){
        int temp = A[i];
        answer = max(answer, temp - minPrice);
        minPrice = min(minPrice, temp);
    }

    return answer;
}

// https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = A[0];
    int tempMax = max(0, A[0]);

    for(size_t i=1; i<A.size(); i++){
        int temp = A[i];
        
        tempMax = max(temp, tempMax+temp);
        answer = max(answer, tempMax);
    }

    return answer;
}
