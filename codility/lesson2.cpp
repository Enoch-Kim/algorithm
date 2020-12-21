/*
https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
*/

vector<int> solution(vector<int> &A, int K) {
    if(A.size() == 0) return A;

    int size = A.size();
    K %= size;
    if(K == 0) return A;

    vector<int> ans(size, 0);

    for(int i=0; i<size; i++){
        ans[i] = A[(size+i-K) % size];
    }
    return ans;
}


/*
https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
*/

int solution(vector<int> &A) {
    int ans = 0;
    for(int i=0; i<A.size(); i++){
        ans ^= A[i];
    }
    return ans;
}