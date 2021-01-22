/*
https://programmers.co.kr/learn/courses/30/lessons/67256
*/

#include <string>
#include <vector>

#define NUM_STAR    10
#define NUM_ZERO    11
#define NUM_SHOP    12

#define CHAR_LEFT 'L'
#define CHAR_RIGHT 'R'

using namespace std;

inline int abs(int a){
    if(a>=0){
        return a;
    } else {
        return -a;
    }
}

int calcDist(int temp, int target){
    int vert = abs(((temp-1)/3) - ((target-1)/3));
    int horiz = abs(((temp-1)%3) - ((target-1)%3));
    return vert + horiz;
}

char which2Use(bool isLeft, int tempLeft, int tempRight, int target){
    int leftDist = calcDist(tempLeft, target);
    int rightDist = calcDist(tempRight, target);

    if(leftDist == rightDist){
        if(isLeft){
            return CHAR_LEFT;
        } else {
            return CHAR_RIGHT;
        }
    } else if(leftDist > rightDist){
        return CHAR_RIGHT;
    } else {
        return CHAR_LEFT;
    }
    return CHAR_LEFT;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int tempLeft = NUM_STAR;
    int tempRight = NUM_SHOP;
    bool isLeft = (hand == "left");
    
    for(int i=0; i<numbers.size(); i++){
        int target = numbers[i];
        
        if(target == 0){
            target = NUM_ZERO;
        }
        
        switch( (target-1)%3 ) {
            case 0 :
                answer += CHAR_LEFT;
                tempLeft = target;
                break;
            case 2 :
                answer += CHAR_RIGHT;
                tempRight = target;
                break;
            case 1 :
                if(which2Use(isLeft, tempLeft, tempRight, target) == CHAR_LEFT){
                    answer += CHAR_LEFT;
                    tempLeft = target;
                } else { 
                    answer += CHAR_RIGHT;
                    tempRight = target;
                }
                break;
            default :
                break;
        }
    }
    
    return answer;
}