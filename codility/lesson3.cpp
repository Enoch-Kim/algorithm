/*
https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
*/

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    return (Y-X + D-1)/D;
}

/*
https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
*/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    for(int i=0; i<A.size(); i++){
        result ^= A[i];
        result ^= i+1;
    }
    result ^= A.size()+1;
    return result;
}

/*
https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
*/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 1000000000;
    int tempSum = 0;
    for(size_t i=0; i<A.size(); i++){
        tempSum += A[i];
    }
    for(size_t i=A.size()-1; i>0; i--){
        tempSum -= A[i]*2;
        int temp = tempSum >= 0 ? tempSum : -tempSum;
        if(result > temp){
            result = temp;
        }
    }
    return result;
}