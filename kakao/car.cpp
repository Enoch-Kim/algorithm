#include <vector>

using namespace std;

int MOD = 20170805;
vector<vector<int>>* mapPtr = nullptr;
int height = 0;
int width = 0;

void moveToStart(int& ans, int i, int j, int direct){
    if(i<0 || j<0 || mapPtr->at(i).at(j)==1) return;
    if(i==0 && j==0)
    {
        ans++;
        ans%=MOD;
        return;
    }
    if(mapPtr->at(i).at(j)==2){
        moveToStart(ans, i-!direct, j-direct, direct);
    }else{
        moveToStart(ans, i-1, j, 0);
        moveToStart(ans, i, j-1, 1);
    }
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    mapPtr = &city_map;
    height = m;
    width = n;
    if(height==1 && width==1) return 1;
    moveToStart(answer, height-2, width-1, 0);
    moveToStart(answer, height-1, width-2, 1);
    return answer;
}
// 6:25
// 

0 1 1
1 2 1
1 1 2