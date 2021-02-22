/*
https://programmers.co.kr/learn/courses/30/lessons/42860
오른쪽과 왼쪽으로 가는 거리 같으면 오른쪽으로 가야 마지막 테스트 케이스 통과 -> 문제가 잘못되었음.
*/
#include <string>
#include <vector>

using namespace std;

int calcVertDiff(char a){
    static int height = ('Z' - 'A') + 1;
    return min(a-'A', height-(a-'A'));
}


int solution(string name) {
    int answer = 0;
    int size = name.size();
    
    int cnt = 0;
    
    for(int i=1; i<size; i++){
        if(name[i] == 'A'){
            cnt++;
        }
    }
    
    int idx = 0;
    answer += calcVertDiff(name[idx]);
    name[idx] = 'A';
    cnt++;
    while(cnt != size){
        int right = 1;
        int left = 1;
        while(right != size && name[(idx+right)%size] == 'A'){
            right++;
        }
        while(left != size && name[(size+idx-left)%size] == 'A'){
            left++;
        }
        
        if(right <= left){
            idx = (idx+right)%size;
            answer += (calcVertDiff(name[idx]) + right);
            name[idx] = 'A';
        } else {
            idx = (size+idx-left)%size;
            answer += (calcVertDiff(name[idx]) + left);
            name[idx] = 'A';
        }
        cnt++;
    }
    
    return answer;
}