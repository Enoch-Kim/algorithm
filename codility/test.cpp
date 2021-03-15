int solution(string &S, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;

    int size = S.size();
    int idx = 0;
    while(idx < size){
        char tempChar = S[idx];
        int higherCost = C[idx];

        int nextIdx = idx+1;
        while(nextIdx < size && S[nextIdx] == tempChar){
            if(C[nextIdx] > higherCost){
                answer += higherCost;
                higherCost = C[nextIdx];
            } else {
                answer += C[nextIdx];
            }
            nextIdx++;
        }
        idx = nextIdx;
    }
    return answer;
}

('aabbcc', [0, 0, 0, 0, 0, 0])
('a', [5])
('abbbcccccdef', [1,20,10,30,10,20,30,40,50,1,2,3])
('abbbcccccdef', [1,30,20,10,50,40,30,20,10,1,2,3])
('abbbcccccddddd', [1,30,20,10,50,40,30,20,10,1, 0, 10, 2,3])


#include <string>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;

    string num = to_string(N);
    int size = num.size();
    if(N > 0){          // positive
        int idx = 0;
        
        while(idx < size){
            if(num[idx] < '5'){
                break;
            }
            idx++;
        }

        num = num.substr(0, idx) + '5' + num.substr(idx);

    } else if(N == 0){  // 0
        num = '5' + num;

    } else {            // negative
        int idx = 1;    // except (-)

        while(idx < size){
            if(num[idx] > '5'){
                break;
            }
            idx++;
        }
        num = num.substr(0, idx) + '5' + num.substr(idx);
    }

    answer = stoi(num);

    return answer;
} 

5268
5628
5689
-5268
-5628
-8000
8000
-6
6666

