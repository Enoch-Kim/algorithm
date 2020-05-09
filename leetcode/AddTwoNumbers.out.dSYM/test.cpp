#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    unordered_map<string, int> sum;
    unordered_map<string, vector<pair<int,int>>> m;
    vector<pair<int,string>> veri;
    string curG;
    int curP;
    for(int i=0; i<size; ++i){
        curG = genres[i];
        curP = plays[i];
        sum[curG]+=curP;
        m[curG].push_back({curP,size-i});
    }
    for(auto x : sum){
        veri.push_back({x.second,x.first});
    }
    sort(veri.rbegin(), veri.rend());
    for(int i=0; i<veri.size(); i++){
        string g = veri[i].second;
        if(m[g].size() == 1){
            answer.push_back(size-m[g][0].second);
            continue;
        }
        sort(m[g].rbegin(), m[g].rend());
        answer.push_back(size-m[g][0].second);
        answer.push_back(size-m[g][1].second);
    }
    return answer;
}

int f(int x, int& n){
    n++;
    if(x < 2) return x;
    else {
        return f(x-1,n) + f(x-2,n);
    }
}

class Solution {
public:

    void seekIsland(int i, int j){
        confirm[i*width+j] = 1;
        if(i>0 && (*gridMap)[i-1][j] == '1' && confirm[(i-1)*width+j]==0) 
            seekIsland(i-1, j);
        if(i<height-1 && (*gridMap)[i+1][j] == '1' && confirm[(i+1)*width+j]==0)
            seekIsland(i+1, j);
        if(j>0 && (*gridMap)[i][j-1] == '1' && confirm[i*width+j-1]==0)
            seekIsland(i, j-1);
        if(j<width-1 && (*gridMap)[i][j+1] == '1' && confirm[i*width+j+1]==0)
            seekIsland(i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int ans=0; 
        height = grid.size();
        width = grid[0].size();
        gridMap = &grid;
        confirm = vector<int>(height*width, 0);

        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                if(grid[i][j] == '1' && confirm[i*width+j] == 0){
                    ans++;
                    seekIsland(i, j);
                }
            }
        }
        return ans;
    }
    
    private : 
        int width;
        int height;
        vector<vector<char>>* gridMap;
        vector<int> confirm;
};
                    // if(confirm[i*width+j] == 0) {
                    //     confirm[i*width+j] = 1;
                    //     ans++;
                    // }
                    // if(i<height-1 && grid[i+1][j]=='1') 
                    //     confirm[(i+1)*width+j] = 1;
                    // if(j<width-1 && grid[i][j+1]=='1')
                    //     confirm[i*width+j+1] = 1;

int combineBytesToInt(char high, char low){
  int combined;
  combined += (high << 8);
  combined += low;
  return combined;
}

int main(){
    // int a = combineBytesToInt('a', 'A');
    // cout << a << '\n';
    Solution S;
    vector<vector<char>> v{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    cout << S.numIslands(v) << '\n';
}
