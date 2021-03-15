// https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
#include <vector>

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 1;
    vector<char> nestSt;

    for(size_t i=0; i<S.size(); i++){
        char temp = S[i];
        switch(temp){
            case '(' :
            case '{' :
            case '[' :
                nestSt.push_back(temp);
                break;
            case ')' :
                if(nestSt.empty() || nestSt.back() != '('){
                    answer = 0;
                } else {
                    nestSt.pop_back();
                }
                break;
            case '}' :
                if(nestSt.empty() || nestSt.back() != '{'){
                    answer = 0;
                } else {
                    nestSt.pop_back();
                }
                break;
            case ']' :
                if(nestSt.empty() || nestSt.back() != '['){
                    answer = 0;
                } else {
                    nestSt.pop_back();
                }
                break;
            default :
                throw "Internal Error Occur";
                break;
        }
        if(!answer) break;
    }

    if(nestSt.size()){
        answer = 0;
    }

    return answer;
}

// https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/

#include <utility>
#define UPSTREAM 0
#define DOWNSTREAM 1

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    vector<pair<int,int>> fishSt; // {size, direct} arr

    for(size_t i=0; i<A.size(); i++){
        int tempSize = A[i];
        int tempDirect = B[i];

        if(fishSt.empty() || 
            tempDirect == DOWNSTREAM || 
            fishSt.back().second == UPSTREAM){

            fishSt.push_back(make_pair(tempSize, tempDirect));

        } else { // temp UPSTREAM

            while(true){
                if(fishSt.empty() || fishSt.back().second == UPSTREAM){
                    fishSt.push_back(make_pair(tempSize, tempDirect));
                    break;
                } else if(fishSt.back().first < tempSize) {
                    fishSt.pop_back();
                } else {
                    break;
                }
            }
            
        }
    }
    return fishSt.size();
}

// https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 1;
    int cnt = 0;

    for(size_t i=0; i<S.size(); i++){
        char temp = S[i];
        if(temp == '('){
            cnt++;
        } else if(cnt > 0){
            cnt--;
        } else {
            answer = 0;
            break;
        }
    }

    if(cnt){
        answer = 0;
    }

    return answer;
}

// https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    vector<int> heightSt;
    for(size_t i=0; i<H.size(); i++){
        int temp = H[i];
        if(heightSt.empty() || heightSt.back() < temp){
            heightSt.push_back(temp);
            answer++;
        } else if(heightSt.back() == temp){
            continue;
        } else {
            while(!heightSt.empty() && heightSt.back() > temp){
                heightSt.pop_back();
            }
            if(heightSt.empty() || heightSt.back() != temp){
                heightSt.push_back(temp);
                answer++;
            }
        }
    }
    return answer;
}