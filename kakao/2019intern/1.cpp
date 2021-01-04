/*
https://programmers.co.kr/learn/courses/30/lessons/64061
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    
    vector<int> cntMap(size,0);
    for(int col=0; col<size; col++){
        for(int row=0; row<size; row++){
            if(board[row][col]){
                cntMap[col]++;
            }
        }
    }
    
    vector<int> st(0);
    for(int i=0; i<moves.size(); i++){
        int col = moves[i]-1;
        if(cntMap[col]){
            int row = size - cntMap[col];
            int temp = board[row][col];
            
            if(st.empty() || st.back() != temp){
                st.push_back(temp);
            } else {
                st.pop_back();
                answer+=2;
            }
            cntMap[col]--;
        }
    }
    
    return answer;
}