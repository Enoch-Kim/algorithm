/*
https://programmers.co.kr/learn/courses/30/lessons/67259
*/

#include <string>
#include <vector>
#include <deque>

#define MAX_COST 10000000000
#define LEFT    1
#define RIGHT   -1
#define UP      2
#define DOWN    -2

#define COST_DIRECT 100
#define COST_CORNER 500

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 1000000000;
    
    int size = board.size();
    
    deque<vector<int>> posQue;  // {x, y, cost, direct}
    vector<vector<int>> costMap(size, vector<int>(size, MAX_COST));
    
    costMap[size-1][size-1] = 0;
    posQue.push_back({size-2, size-1, COST_DIRECT, LEFT});
    posQue.push_back({size-1, size-2, COST_DIRECT, DOWN});
    
    while(posQue.size()){
        vector<int>& temp = posQue.front();
        
        if(temp[0] < 0 || temp[0] >= size || 
           temp[1] < 0 || temp[1] >= size || 
           costMap[temp[0]][temp[1]] < temp[2] ||
           board[temp[0]][temp[1]]
          ){
            posQue.pop_front();
            continue;
        }
        
        costMap[temp[0]][temp[1]] = temp[2];
        
        if(temp[0] == 0 && temp[1] == 0){
            answer = min(answer, temp[2]);
        }
        
        if(temp[3] + RIGHT) {
            int cost = (temp[3] == RIGHT ? COST_DIRECT : COST_DIRECT+COST_CORNER);
            posQue.push_back({temp[0]+1, temp[1], temp[2]+cost, RIGHT});
        }
        
        if(temp[3] + LEFT) {
            int cost = (temp[3] == LEFT ? COST_DIRECT : COST_DIRECT+COST_CORNER);
            posQue.push_back({temp[0]-1, temp[1], temp[2]+cost, LEFT});
        }
        
        if(temp[3] + UP) {
            int cost = (temp[3] == UP ? COST_DIRECT : COST_DIRECT+COST_CORNER);
            posQue.push_back({temp[0], temp[1]+1, temp[2]+cost, UP});
        }
        
        if(temp[3] + DOWN) {
            int cost = (temp[3] == DOWN ? COST_DIRECT : COST_DIRECT+COST_CORNER);
            posQue.push_back({temp[0], temp[1]-1, temp[2]+cost, DOWN});
        }
        
        posQue.pop_front();
    }
    
    
    
    
    return answer;
}