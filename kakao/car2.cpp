#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    if(m==1 && n==1) return 1;
    vector<vector<int>> map(m+1, vector<int>(n+1,0));
    map[0][0]=1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            switch(city_map[i][j]){
                case 0:
                    
                    break;
                case 1:
                    map[i][j]=0;
                    break;
                case 2:
                    if(i==0)
                        map[i][j+1]+=map[i][j-1];
                    else if(j==0)
                        map[i+1][j]+=map[i-1][j];
                    else{
                        map[i+1][j]+=map[i-1][j];
                        map[i][j+1]+=map[i][j-1];
                    }
                    break;
                default :
                    break;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << ", ";
        }
        cout << '\n';
    }
    answer=map[m-1][n-1]%MOD;
    return answer;
}
// 6:25
// 
int main(){
    vector<vector<int>> v{{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};
    int s = solution(3,6,v);
    cout << "solution is " << s << '\n';

}