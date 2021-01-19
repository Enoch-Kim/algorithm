/*
https://programmers.co.kr/learn/courses/30/lessons/49191
나중에 푼 방식 => E + N^3 => N^3
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> resultMap(n+1, vector<int>(n+1,0));
    
    // graph => 이긴 쪽에만 표시
    for(int i=0; i<results.size(); i++){
        resultMap[results[i][0]][results[i][1]] = 1;
    }
    
    for(int mid=1; mid<=n; mid++){
        for(int up=1; up<=n; up++){
            if(resultMap[up][mid] == 0){
                continue;
            }
            // up > mid
            for(int down=1; down<=n; down++){
                if(resultMap[mid][down]){ // up > mid > down
                    resultMap[up][down] = 1;
                }
            }
        }
    }

    // 이건 안됨.. side effect가 발생함..
    // for(int up=1; up<=n; up++){
    //     for(int mid=1; mid<=n; mid++){
    //         if(resultMap[up][mid] == 0){
    //             continue;
    //         }
    //         // up > mid
    //         for(int down=1; down<=n; down++){
    //             if(resultMap[mid][down]){ // up > mid > down
    //                 resultMap[up][down] = 1;
    //             }
    //         }
    //     }
    // }
    
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            cnt += resultMap[i][j] + resultMap[j][i];
        }
        if(cnt == n-1){
            answer++;
        }
    }
    
    return answer;
}