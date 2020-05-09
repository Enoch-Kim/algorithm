#include <string>
#include <vector>

using namespace std;

int getDistance(int hand, int temp, bool isLeft){
    int res = 0;
    if(hand % 3 != 2)
    {
        if(isLeft)
        {
            hand = (hand + 2)/3;
            temp = (temp + 1)/3;
            res = hand >= temp ? hand-temp : temp - hand;
            res++;
            return res;
        }
        else
        {
            hand = (hand + 2)/3;
            temp = (temp + 1)/3;
            res = hand >= temp ? hand-temp : temp - hand;
            res++;
            return res;
        }
    }
    else
    {
        hand = (hand + 1)/3;
        temp = (temp + 1)/3;
        res = hand >= temp ? hand-temp : temp - hand;
        return res;
    }
    return res;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    char h = hand == "right" ? 'R' : 'L';
    int curLeft = 10;
    int curRight = 12;
    for(int i=0; i<numbers.size(); ++i){
        int temp = numbers[i];
        if(temp == 0) temp = 11;
        if(temp == 1 || temp == 4 || temp == 7){
            answer += 'L';
            curLeft = temp;
            continue;
        }else if(temp == 3 || temp == 6 || temp == 9){
            answer += 'R';
            curRight = temp;
            continue;
        }else{
            int leftDistance = getDistance(curLeft, temp, true);
            int rightDistance = getDistance(curRight, temp, false);
            if(leftDistance == rightDistance){
                if(hand == "right"){
                    answer += 'R';
                    curRight = temp;
                    continue;
                }else{
                    answer += 'L';
                    curLeft = temp;
                    continue;
                }
            }else if(leftDistance > rightDistance){
                answer += 'R';
                curRight = temp;
                continue;
            }else{
                answer += 'L';
                curLeft = temp;
                continue;
            }
        }
    }
    return answer;
}