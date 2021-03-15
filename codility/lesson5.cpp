// https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)

    if(A == 0){
        return B/K + 1;
    }

    return (B/K) -  ((A-1)/K);
}

// https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
