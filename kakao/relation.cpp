#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int col = relation.size();
    int row= relation[0].size();
    vector<vector<vector<int>>> vMap;
    for(int i=0; i<row; ++i){
        unordered_map<string, vector<int>> colMap;
        for(int j=0; j<col; ++j){
            colMap[relation[j][i]].push_back(j);
        }
        for(auto i : colMap){
            auto temp = i.second;
            if(temp.size() <= 1){
                temp
            }
        }
    }
    for(int i=0; i<row; ++i){

    }

    return answer;
}
//4:38

int main(){}