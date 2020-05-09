#include <string>
#include <vector>

using namespace std;
vector<vector<int>>* costMap;
int N = 0;

void makeRoad(vector<vector<int>>& board, int i, int j, int cost, int direct){
    if(i < 0 || j < 0 || i >= N || j >= N || board[i][j] || cost >= costMap->at(i).at(j)) return;
    if(i == 0 && j == 0){
        costMap->at(i).at(j) = cost;
        return;
    }
    costMap->at(i).at(j) = cost;
    board[i][j] = 1;
    if(i > 0 && direct != 1) {
        makeRoad(board, i-1, j, direct == -1 ? cost + 100 : cost+600, -1);
    }
    if(i < N-1 && direct != -1){
        makeRoad(board, i+1, j, direct == 1 ? cost + 100 : cost+600, 1);  
    } 
    if(j > 0 && direct != 2){
        makeRoad(board, i, j-1, direct == -2 ? cost + 100 : cost+600, -2);
    }
    
    if(j < N-1 && direct != -2) {
        makeRoad(board, i, j+1, direct == 2 ? cost + 100 : cost+600, 2);
    }
    board[i][j] = 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    costMap = new vector<vector<int>>(N, vector<int>(N, 1000000000));
    board[N-1][N-1] = 1;
    // costMap -> at(N-1).at(N-1) = 0;
    makeRoad(board, N-2, N-1, 100, -1);
    makeRoad(board, N-1, N-2, 100, -2);
    answer = costMap -> at(0).at(0);
    if(answer != 1000000000) answer = 0;
    return answer;
}