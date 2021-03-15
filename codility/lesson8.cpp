// https://app.codility.com/programmers/lessons/8-leader/dominator/
#include <unordered_map>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = -1;
    int size = A.size();
    int half = size/2;

    unordered_map<int,int> cntMap;
    for(int i=0; i<size; i++){
        int temp = A[i];
        if(++cntMap[temp] > half){
            answer = i;
            break;
        }
    }

    return answer;
}

// https://app.codility.com/programmers/lessons/8-leader/equi_leader/

#include <unordered_map>
#define NO_LEADER 1000000001

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;

    unordered_map<int,int> leftMap;
    unordered_map<int,int> rightMap;
    int leftLeader = NO_LEADER;
    int rightLeader = NO_LEADER;
    int size = A.size();
    for(int i=0; i<size; i++){
        if(++rightMap[A[i]] > size/2){
            rightLeader = A[i];
        }
    }

    for(int i=0; i<size-1; i++){
        int temp = A[i];
        leftMap[temp]++;
        rightMap[temp]--;
        if(leftMap[temp] > (i+1)/2){
            leftLeader = temp;
        }
        if(temp == rightLeader && rightMap[temp] <= (size-i-1)/2){
            int rightMax = 0;
            for(auto num : rightMap){
                if(num.second > rightMax){
                    rightMax = num.second;
                    rightLeader = num.first;
                }
            }
        }
        if(rightLeader == leftLeader &&
            leftMap[leftLeader] > (i+1)/2 && 
            rightMap[rightLeader] > (size-i-1)/2
        ){
            answer++;
        }
    }
    return answer;
}