/*
https://programmers.co.kr/learn/courses/30/lessons/64061
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    
    vector<int> basket(0);
    
    for(int i=0; i<moves.size(); i++){
        int temp = moves[i]-1;
        if(board[size-1][temp] == 0) continue;
        
        for(int j=0; j<size; j++){
            int target = board[j][temp];
            if(target){
                if(!basket.empty() && basket.back() == target){
                    basket.pop_back();
                    answer += 2;
                } else {
                    basket.push_back(target); 
                    
                }
                board[j][temp] = 0;
                break;
            }
        }
    }
    return answer;
}