#include<vector>
#include<unordered_map>
#include<queue>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> countMap (n, vector<int>(m,0));
    queue<pair<int,int>> qu; // i, j, count
    qu.push({0,0});
    while(!qu.empty()){
        int i = qu.front().first;
        int j = qu.front().second;
        qu.pop();
        if(i + j == n + m - 3) 
            return countMap[i][j]+1;
        
        if(i>0 && maps[i-1][j]
           && countMap[i-1][j]==0)
        {
            qu.push({i-1, j});
            countMap[i-1][j] = countMap[i][j]+1;
        }
            
        if(j>0 && maps[i][j-1]
           && countMap[i][j-1]==0)
        {
            qu.push({i, j-1});
            countMap[i][j-1] = countMap[i][j]+1;
        }
           
        if(i < n-1 && maps[i+1][j]
           && countMap[i+1][j]==0)
        {
            qu.push({i+1, j});
            countMap[i+1][j] = countMap[i][j]+1;
        }
            
        if(j < m-1 && maps[i][j+1]
           && countMap[i][j+1]==0)
        {
            qu.push({i, j+1});
            countMap[i][j+1] = countMap[i][j]+1;
        }
            
    }
	return -1;
}

int main() {
    string s = "222";
    cout << s.substr(2,3) << '\n';
}