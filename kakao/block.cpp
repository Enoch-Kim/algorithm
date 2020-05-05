#include <string>
#include <vector>
#include <utility>

using namespace std;
vector<bool> cantRemove;


void searchAndRemove(vector<vector<int>>& board, int i, int j){
    int target = board[i][j];
    if()
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    int answer = 0;
    cantRemove.resize(n);
    for(int i=0; i<n;++i){
        for(int j=0; j<n; ++j){
            if(cantRemove[j]) continue;
            if(board[i][j]){
                if(j>0 && board[i][j-1]) {
                    cantRemove[j] = true;
                    continue;
                }
                if(j<n-1 && board[i][j+1]) {
                    cantRemove[j] = true;
                    continue;
                }
                searchAndRemove(board, i,j);
            }
        }
    }
   

    
    return answer;
}